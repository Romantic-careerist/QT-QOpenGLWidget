/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDraw;
    QAction *actionClear;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(550, 426);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../QT\345\233\276\347\211\207\347\264\240\346\235\220/\350\201\224\346\203\263\346\210\252\345\233\276_20250927210934.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	background-color: rgb(88, 88, 88);\n"
"	color: rgb(255, 255, 255);\n"
"	font: 10pt \"\351\232\266\344\271\246\";\n"
"}\n"
"QMenuBar{\n"
"	background-color: rgb(255, 255, 255);\n"
"	color: rgb(60, 60, 60);\n"
"}\n"
""));
        actionDraw = new QAction(MainWindow);
        actionDraw->setObjectName("actionDraw");
        actionDraw->setMenuRole(QAction::MenuRole::NoRole);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        actionClear->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 550, 16));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        toolBar->addAction(actionDraw);
        toolBar->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Triangle", nullptr));
        actionDraw->setText(QCoreApplication::translate("MainWindow", "\347\224\273\344\270\200\344\270\252\347\237\251\345\275\242", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\347\251\272\347\224\273\351\235\242", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
