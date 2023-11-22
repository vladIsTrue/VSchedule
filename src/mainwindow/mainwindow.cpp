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
    if (m_dbController->connectToDB())
        qDebug() << "Server opens database.";
    else
        qDebug() << "Database open error.";

    setupUI();
}

MainWindow::~MainWindow()
{}

void MainWindow::setupUI()
{
    m_ui->setupUi(this);

    auto resultSelect =
        m_sceneCreator->setQueryFromDB("SELECT name, startofvacation, endofvacation FROM employees"
                                       , QueryCode::EMPLOYEES);

    if(resultSelect.isValid())
        qDebug() << resultSelect;

    resultSelect =
        m_sceneCreator->setQueryFromDB("SELECT mounth, numberofemployees FROM standards"
                                      , QueryCode::STANDARDS);

    if(resultSelect.isValid())
        qDebug() << resultSelect;

    mainScene = m_sceneCreator->createScene(); // это все тоже нужно переделать

    m_ui->mainView->setAlignment(Qt::AlignTop);
    m_ui->mainView->setScene(mainScene);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_ui->mainView->resize(event->size());
    m_ui->mainView->fitInView(QRectF(QPointF(0, 0), event->size()));

    m_ui->mainView->scale((width() - 50) / mainScene->width(),
                          (height() - 50) / mainScene->height()); // this can set 1

    update();

    QWidget::resizeEvent(event);
}

