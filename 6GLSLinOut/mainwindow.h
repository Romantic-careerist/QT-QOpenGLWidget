#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "axbopenglwidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionDraw_triggered();

    void on_actionClear_triggered();

    void on_actionWire_toggled(bool arg1);

private:
    Ui::MainWindow *ui;

    AXBOpenGLWidget* openGLWidget;
};
#endif // MAINWINDOW_H
