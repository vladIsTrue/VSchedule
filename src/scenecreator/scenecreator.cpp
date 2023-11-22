#include "scenecreator.h"

#include <QDate>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>

SceneCreator::SceneCreator()
    : m_employeesQuery(nullptr)
    , m_stardardsQuery(nullptr)
{}

SceneCreator::~SceneCreator()
{}

QSqlError SceneCreator::setQueryFromDB(QString query, QueryCode code)
{
    switch (code)
    {
    case QueryCode::EMPLOYEES:
        m_employeesQuery = new QSqlQuery(query);
        return m_employeesQuery->lastError();
    case QueryCode::STANDARDS:
        m_stardardsQuery = new QSqlQuery(query);
        return m_stardardsQuery->lastError();
    }
}

QGraphicsScene* SceneCreator::createScene()
{
    QGraphicsScene * scene = new QGraphicsScene();

    fillStandardsVec(); // refactor this

    while(m_employeesQuery->next())
    {
        QString name        = m_employeesQuery->value(0).toString();
        QDate vacationStart = m_employeesQuery->value(1).toDate();
        QDate vacationEnd   = m_employeesQuery->value(2).toDate();

        m_standards[vacationStart.month() - 1].currentNumber++;
        if (vacationEnd.month() != vacationStart.month())
        {
            m_standards[vacationEnd.month() - 1].currentNumber++;
        }

        //create a rectangle with which we visualize the duration of the employee’s vacation
        QGraphicsRectItem *itemRect = new QGraphicsRectItem(vacationStart.dayOfYear() * m_scale
                                                        , m_currentRow * m_heightRow + m_heightRow / 2
                                                        , (vacationEnd.dayOfYear() - vacationStart.dayOfYear()) * m_scale
                                                        , m_heightRow);
        itemRect->setPos(m_widthEmployeeName, 0);
        scene->addItem(itemRect);

        //place the number of employee vacation days in the center of the rectangle
        addTextToRect(scene, itemRect, QString::number(vacationEnd.dayOfYear() - vacationStart.dayOfYear()));

        //create a value storing the employee's name
        QGraphicsTextItem *nameEmployeeItem = new QGraphicsTextItem(name);
        nameEmployeeItem->setPos(0, m_currentRow * m_heightRow);
        scene->addItem(nameEmployeeItem);

        QString toolTip = QString("Начало: %1\nКонец: %2")
                              .arg(vacationStart.toString())
                              .arg(vacationEnd.toString());

        itemRect->setToolTip(toolTip);

        ++m_currentRow;
    }

    scene->addLine(m_widthEmployeeName
                   , 0
                   , m_widthEmployeeName
                   , (m_currentRow + 1) * m_heightRow
                   , QPen(Qt::black));

    scene->addLine(m_dayOfMounth * m_mounthCount * m_scale + m_widthEmployeeName
                   , 0
                   , m_dayOfMounth * m_mounthCount * m_scale + m_widthEmployeeName
                   , (m_currentRow + 1) * m_heightRow
                   , QPen(Qt::black));


    for (int i = 0; i < m_mounthCount; ++i)
    {
        QGraphicsRectItem *itemRect = nullptr;

        auto selectedBrush = m_standards[i].currentNumber > m_standards[i].standardNumber
                             ? QBrush(Qt::red)
                             : QBrush(Qt::green);

        itemRect = scene->addRect(m_dayOfMounth * m_scale * i
                                  , (m_currentRow + 1) * m_heightRow
                                  , m_dayOfMounth * m_scale
                                  , m_heightRow
                                  , QPen(Qt::black)
                                  , selectedBrush);

        itemRect->setPos(m_widthEmployeeName, 0);
        addTextToRect(scene, itemRect, m_mounth[i]);
    }

    return scene;
}

void SceneCreator::fillStandardsVec()
{
    while(m_stardardsQuery->next())
        for(int i = 0; i < m_mounthCount; ++i)
            if (m_stardardsQuery->value(0).toString() == m_mounth[i])
            {
                m_standards[i].standardNumber = m_stardardsQuery->value(1).toInt();
                break;
            }
}

void SceneCreator::addTextToRect(QGraphicsScene* scene, QGraphicsRectItem* itemRect, QString text)
{
    qreal x1Rect, y1Rect, widthRect, heightRect;

    QGraphicsTextItem *textItem = scene->addText(text);
    itemRect->rect().getRect(&x1Rect, &y1Rect, &widthRect, &heightRect);
    textItem->setPos(x1Rect + widthRect / 2 + m_widthEmployeeName - textItem->boundingRect().width() / 2
                     , y1Rect - heightRect / 2 + m_scale);
}
