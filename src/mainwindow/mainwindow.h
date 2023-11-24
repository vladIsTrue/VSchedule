/**
 * @file mainwindow.h
 * @brief The MainWindow class declaration.
 *
 * This class represents the main window of the application. It is responsible for setting up the user interface,
 * managing the scene creator and database controller, and handling resize events.
 */

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
    /**
     * @brief MainWindow constructor.
     * @param parent The parent widget.
     */
    MainWindow(QWidget* parent = nullptr);

    /**
     * @brief MainWindow destructor.
     */
    ~MainWindow();

    /**
     * @brief Setup the user interface.
     */
    void setupUI();

protected:
    /**
     * @brief Overridden resize event handler.
     * @param event The resize event.
     */
    void resizeEvent(QResizeEvent* event) override;

private:
    SceneCreator*   m_sceneCreator;  /**< The scene creator. */
    IDBController*  m_dbController;  /**< The database controller. */
    QGraphicsScene* m_mainScene;     /**< The main scene. */
    Ui::MainWindow* m_ui;            /**< The user interface. */
};
#endif // MAINWINDOW_H
