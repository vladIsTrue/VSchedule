#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../scenecreator/scenecreator.h"
#include "../dbcontroller/pgdbcontroller.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupUI();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    SceneCreator    *m_sceneCreator;
    IDBController   *m_dbController;
    QGraphicsScene  *m_mainScene;
    Ui::MainWindow  *m_ui;
};
#endif // MAINWINDOW_H
