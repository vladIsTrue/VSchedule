#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "../utils/utils.h"

#include <QResizeEvent>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_dbController(new PgDBController())
    , m_sceneCreator(new SceneCreator())
    , m_ui(new Ui::MainWindow)
    , m_mainScene(nullptr)
{
    if (m_dbController->connectToDB())
        LOGD("Database is open");
    else
        LOGE("Database open error");

    setupUI();
}

MainWindow::~MainWindow()
{}

void MainWindow::setupUI()
{
    m_ui->setupUi(this);

    setWindowTitle("График отпусков сотрудников");

    auto resultSelect =
        m_sceneCreator->setQueryFromDB("SELECT name, startofvacation, endofvacation FROM employees"
                                       , QueryCode::EMPLOYEES);

    resultSelect.isValid() ? LOGE(resultSelect) : LOGD("Selection from "
                                                       << QueryCode::EMPLOYEES
                                                       << " table completed successfully");

    resultSelect =
        m_sceneCreator->setQueryFromDB("SELECT mounth, numberofemployees FROM standards"
                                      , QueryCode::STANDARDS);

    resultSelect.isValid() ? LOGE(resultSelect) : LOGD("Selection from "
                                                       << QueryCode::STANDARDS
                                                       << " table completed successfully");

    m_mainScene = m_sceneCreator->createScene();

    m_mainScene ? LOGE("Error creating scene") : LOGD("Scene created successfully");

    m_ui->mainView->setAlignment(Qt::AlignTop);
    m_ui->mainView->setScene(m_mainScene);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    m_ui->mainView->resize(event->size());
    m_ui->mainView->fitInView(QRectF(QPointF(0, 0), event->size()));

    m_ui->mainView->scale(width() / m_mainScene->width(),
                          width() / m_mainScene->width());

    update();

    QWidget::resizeEvent(event);
}

