#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    openGLWidget=new AXBOpenGLWidget(parent);
    setCentralWidget(openGLWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionDraw_triggered()
{
    openGLWidget->drawRectangle();
}


void MainWindow::on_actionClear_triggered()
{
    openGLWidget->clear();
}


void MainWindow::on_actionWire_toggled(bool arg1)
{
    openGLWidget->setPolygonMode(arg1);
}

