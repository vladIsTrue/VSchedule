#include "mainwindow.h"
#include "./ui_mainwindow.h" // скорее всего она нахуй нужна не будет

#include <QGraphicsView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dbController(new PgDBController())
    , m_sceneCreator(new SceneCreator())
{
    if (m_dbController->connectToDB()) {
        qDebug() << "Server opens database.";
    }
    else {
        qDebug() << "Database open error.";
    }

    m_sceneCreator->setQueryFromDB("SELECT name, startofvacation, endofvacation FROM employees", QueryCode::EMPLOYEES);

    QGraphicsView *view = new QGraphicsView(m_sceneCreator->createScene(), this);
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{}

