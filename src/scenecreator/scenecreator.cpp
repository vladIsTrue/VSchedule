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

void SceneCreator::setQueryFromDB(QString query, QueryCode code)
{
    // TODO обработка ошибок
    switch (code)
    {
    case QueryCode::EMPLOYEES:
        m_employeesQuery = new QSqlQuery(query);
        break;
    case QueryCode::STANDARDS:
        m_stardardsQuery = new QSqlQuery(query);
        break;
    }
}

QGraphicsScene* SceneCreator::createScene()
{
    QGraphicsScene * scene = new QGraphicsScene();

    int i = 0;

    while(m_employeesQuery->next())
    {
        QString name = m_employeesQuery->value(0).toString();
        QDate vacationStart = m_employeesQuery->value(1).toDate();
        QDate vacationEnd = m_employeesQuery->value(2).toDate();

        QGraphicsRectItem *item = new QGraphicsRectItem(vacationStart.dayOfYear() * 3, i * 15 + 7.5, (vacationEnd.dayOfYear() - vacationStart.dayOfYear()) * 3, 15);
        item->setPos(300, 0);
        // Добавляем прямоугольник на сцену
        scene->addItem(item);

        // ну это говно еще можно подправить попробовать
        QGraphicsTextItem *text = scene->addText(QString::number(vacationEnd.dayOfYear() - vacationStart.dayOfYear()));
        text->setPos(vacationStart.dayOfYear() * 3 + 300, i * 15);

        // Создаем текст для отображения имени сотрудника
        QGraphicsTextItem *nameText = new QGraphicsTextItem(name);
        nameText->setPos(0, i * 15);
        scene->addItem(nameText);

        // Устанавливаем всплывающую подсказку для блока отпуска
        QString toolTip = QString("Start: %1\nEnd: %2").arg(vacationStart.toString()).arg(vacationEnd.toString());
        item->setToolTip(toolTip);

        ++i;
    }

//    for (int i = 0; i < 12; ++i)
//    {
//        QGraphicsRectItem *item = new QGraphicsRectItem(30 * i * 3, model.rowCount() * 15 + 7.5, 30 * 3, 15);
//        item->setPos(300, 0);
//        //item->setBrush(QBrush(Qt::red)); // Устанавливаем красный цвет
//        scene->addItem(item);
//    }

    return scene;
}
