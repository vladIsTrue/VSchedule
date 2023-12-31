#include "scenecreator.h"

#include <QDate>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

SceneCreator::SceneCreator()
    : m_employeesQuery(nullptr)
    , m_stardardsQuery(nullptr)
{}

SceneCreator::~SceneCreator()
{
    delete m_employeesQuery;
    delete m_stardardsQuery;
}

QSqlError SceneCreator::setQueryFromDB(const QString& query, const QueryCode code)
{
    switch (code)
    {
    case QueryCode::EMPLOYEES:
        m_employeesQuery = new QSqlQuery(query);
        return m_employeesQuery->lastError();
    case QueryCode::STANDARDS:
        m_stardardsQuery = new QSqlQuery(query);
        return m_stardardsQuery->lastError();
    default:
        return QSqlError("Invalid code");
    }
}

QGraphicsScene* SceneCreator::createScene()
{
    QGraphicsScene* scene = new QGraphicsScene();

    QString oldName{""};

    fillStandardsVec();

    while(m_employeesQuery->next())
    {
        m_standards[m_employeesQuery->value(1).toDate().month() - 1].currentNumber++;
        if (m_employeesQuery->value(2).toDate().month() != m_employeesQuery->value(1).toDate().month())
        {
            m_standards[m_employeesQuery->value(2).toDate().month() - 1].currentNumber++;
        }

        addRow(scene, m_employeesQuery, oldName);
    }

    ++m_currentNumberRows;
    drawLine(scene);

    addMonths(scene);

    scene->setSceneRect(0
                        , 0
                        , m_widthEmployeeName + m_daysInYear * m_scale
                        , m_heightRow * m_currentNumberRows + m_indentation);

    return scene;
}

void SceneCreator::fillStandardsVec()
{
    while(m_stardardsQuery->next())
        for(int i = 0; i < m_numberofmounth; ++i)
            if (m_stardardsQuery->value(0).toString() == m_months[i].first)
            {
                m_standards[i].standardNumber = m_stardardsQuery->value(1).toInt();
                break;
            }
}

void SceneCreator::addTextToRect(QGraphicsScene* scene, QGraphicsRectItem* itemRect, QString text)
{
    qreal x1Rect, y1Rect, widthRect, heightRect;

    QGraphicsTextItem* textItem = scene->addText(text);
    itemRect->rect().getRect(&x1Rect, &y1Rect, &widthRect, &heightRect);
    textItem->setPos(x1Rect + widthRect / 2 - textItem->boundingRect().width() / 2
                     , y1Rect - heightRect / 2 + m_scale);
}

void SceneCreator::drawLine(QGraphicsScene* scene)
{
    scene->addLine(0
                   , m_currentNumberRows * m_heightRow + m_heightRow / 2
                   , m_daysInYear * m_scale + m_widthEmployeeName
                   , m_currentNumberRows * m_heightRow + m_heightRow / 2
                   , QPen(Qt::black));
}

int SceneCreator::accumulateDays(int end)
{
    auto sum = 0;
    for (int j = 0; j < end; ++j)
    {
        sum += (m_months[j].second * m_scale);
    }

    return sum;
}

void SceneCreator::addRow(QGraphicsScene* scene, QSqlQuery* employeesQuery, QString& oldName)
{
    QString name        = m_employeesQuery->value(0).toString();
    QDate vacationStart = m_employeesQuery->value(1).toDate();
    QDate vacationEnd   = m_employeesQuery->value(2).toDate();

    if (name != oldName)
    {
        //create a value storing the employee's name
        QGraphicsTextItem* nameEmployeeItem = new QGraphicsTextItem(name);
        nameEmployeeItem->setPos(0, ++m_currentNumberRows * m_heightRow);
        scene->addItem(nameEmployeeItem);

        oldName = name;
    }

    //create a rectangle with which we visualize the duration of the employee’s vacation
    QGraphicsRectItem* itemRect = scene->addRect(m_widthEmployeeName + vacationStart.dayOfYear() * m_scale
                                                , m_currentNumberRows * m_heightRow + m_heightRow / 2
                                                , (vacationEnd.dayOfYear() - vacationStart.dayOfYear()) * m_scale
                                                , m_heightRow
                                                , QPen(Qt::black)
                                                , QBrush(Qt::yellow));

    //place the number of employee vacation days in the center of the rectangle
    addTextToRect(scene, itemRect, QString::number(vacationEnd.dayOfYear() - vacationStart.dayOfYear() + 1));

    QString toolTip = QString("Начало: %1\nКонец: %2")
                             .arg(QLocale::system().toString(vacationStart))
                             .arg(QLocale::system().toString(vacationEnd));

    itemRect->setToolTip(toolTip);

    drawLine(scene);
}

void SceneCreator::addMonths(QGraphicsScene* scene)
{
    for (int i = 0; i < m_numberofmounth; ++i)
    {
        QGraphicsRectItem* itemRect = nullptr;

        auto selectedBrush = m_standards[i].currentNumber > m_standards[i].standardNumber
                             ? QBrush(Qt::red)
                             : QBrush(Qt::green);

        itemRect = scene->addRect(m_widthEmployeeName + accumulateDays(i)
                                  , (m_currentNumberRows + 0.5) * m_heightRow
                                  , m_months[i].second * m_scale
                                  , m_heightRow
                                  , QPen(Qt::black)
                                  , selectedBrush);

        scene->addLine(m_widthEmployeeName + accumulateDays(i)
                       , m_heightRow * 1.5
                       , m_widthEmployeeName + accumulateDays(i)
                       , (m_currentNumberRows + 1) * m_heightRow
                       , QPen(Qt::black));

        addTextToRect(scene, itemRect, m_months[i].first);
    }
}
