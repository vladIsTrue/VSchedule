#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QResizeEvent>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dbController(new PgDBController())
    , m_sceneCreator(new SceneCreator())
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);

    if (m_dbController->connectToDB()) {
        qDebug() << "Server opens database.";
    }
    else {
        qDebug() << "Database open error.";
    }

    m_sceneCreator->setQueryFromDB("SELECT name, startofvacation, endofvacation FROM employees", QueryCode::EMPLOYEES);
    m_sceneCreator->setQueryFromDB("SELECT mounth, numberofemployees FROM standards", QueryCode::STANDARDS);

    mainScene = m_sceneCreator->createScene(); // это все тоже нужно переделать

    m_ui->mainView->setScene(mainScene);
    m_ui->mainView->setAlignment(Qt::AlignTop);

    m_ui->mainView->setScene(mainScene);
}

MainWindow::~MainWindow()
{}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_ui->mainView->resize(event->size());
    m_ui->mainView->fitInView(QRectF(QPointF(0, 0), event->size()));

    m_ui->mainView->scale((width() - 50) / mainScene->width(),
                          (height() - 50) / mainScene->height()); // this can set 1

    update();

    QWidget::resizeEvent(event);
}

