#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../scenecreator/scenecreator.h"
#include "../dbcontroller/pgdbcontroller.h"

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    IDBController   *m_dbController;
    SceneCreator    *m_sceneCreator;
};
#endif // MAINWINDOW_H
