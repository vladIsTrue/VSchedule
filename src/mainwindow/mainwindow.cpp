#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
    , m_dbController(new PgDBController())
{
    m_ui->setupUi(this);

    if (m_dbController->connectToDB()) {
        qDebug() << "Server opens database.";
    }
    else {
        qDebug() << "Database open error.";
    }

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT name, startofvacation, endofvacation FROM employees");
    model->setHeaderData(0, Qt::Horizontal, tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, tr("startofvacation"));
    model->setHeaderData(1, Qt::Horizontal, tr("endofvacation"));

    m_ui->tableView->setModel(model);
    m_ui->tableView->show();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

