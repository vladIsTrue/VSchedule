//#include <QApplication>
//#include <QGraphicsView>
//#include <QGraphicsScene>
//#include <QGraphicsRectItem>
//#include <QGraphicsTextItem>
//#include <QSqlQueryModel>
//#include <QSqlQuery>
//#include <QSqlError>
//#include <QToolTip>

//#include <QGraphicsTextItem>

//#include "../dbcontroller/pgdbcontroller.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    auto db = new PgDBController();
//    db->connectToDB();

//    QSqlQueryModel model;
//    model.setQuery("SELECT name, startofvacation, endofvacation FROM employees");

//    if (model.lastError().isValid()) {
//        qDebug() << model.lastError();
//        return 1;
//    }



//    // Создаем графическую сцену
//    QGraphicsScene scene;

//    // Создаем графический вид
//    QGraphicsView view(&scene);

//    // Отображаем данные из модели
//    for (int i = 0; i < model.rowCount(); ++i) {
//        QString name = model.data(model.index(i, 0)).toString();
//        QDate vacationStart = model.data(model.index(i, 1)).toDate();
//        QDate vacationEnd = model.data(model.index(i, 2)).toDate();

//        // Создаем прямоугольник для отображения отпуска сотрудника
//        QGraphicsRectItem *item = new QGraphicsRectItem(vacationStart.dayOfYear() * 3, i * 15 + 7.5, (vacationEnd.dayOfYear() - vacationStart.dayOfYear()) * 3, 15);
//        item->setPos(300, 0);

//        // ну это говно еще можно подправить попробовать
//        QGraphicsTextItem *text = scene.addText(QString::number(vacationEnd.dayOfYear() - vacationStart.dayOfYear()));
//        text->setPos(vacationStart.dayOfYear() * 3 + 300, i * 15);

//        // Добавляем прямоугольник на сцену
//        scene.addItem(item);

//        // Создаем текст для отображения имени сотрудника
//        QGraphicsTextItem *nameText = new QGraphicsTextItem(name);
//        nameText->setPos(0, i * 15);
//        scene.addItem(nameText);

//        // Устанавливаем всплывающую подсказку для блока отпуска
//        QString toolTip = QString("Start: %1\nEnd: %2").arg(vacationStart.toString()).arg(vacationEnd.toString());
//        item->setToolTip(toolTip);
//    }

//    for (int i = 0; i < 12; ++i)
//    {
//        QGraphicsRectItem *item = new QGraphicsRectItem(30 * i * 3, model.rowCount() * 15 + 7.5, 30 * 3, 15);
//        item->setPos(300, 0);
//        //item->setBrush(QBrush(Qt::red)); // Устанавливаем красный цвет
//        scene.addItem(item);
//    }
//    // Отображаем вид
//    view.show();

//    return a.exec();
//}

#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
