/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *_startFlexxAction;
    QAction *_stopFlexxAction;
    QAction *_startRSAction;
    QAction *_stopRSAction;
    QWidget *centralWidget;
    QVTKWidget *_qvtkWidget;
    QMenuBar *menuBar;
    QMenu *menuCamera;
    QMenu *menuPico_Flexx;
    QMenu *menuIntel_Realsense;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(800, 850);
        _startFlexxAction = new QAction(MainWindowClass);
        _startFlexxAction->setObjectName(QStringLiteral("_startFlexxAction"));
        _stopFlexxAction = new QAction(MainWindowClass);
        _stopFlexxAction->setObjectName(QStringLiteral("_stopFlexxAction"));
        _startRSAction = new QAction(MainWindowClass);
        _startRSAction->setObjectName(QStringLiteral("_startRSAction"));
        _stopRSAction = new QAction(MainWindowClass);
        _stopRSAction->setObjectName(QStringLiteral("_stopRSAction"));
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _qvtkWidget = new QVTKWidget(centralWidget);
        _qvtkWidget->setObjectName(QStringLiteral("_qvtkWidget"));
        _qvtkWidget->setGeometry(QRect(30, 30, 730, 730));
        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        menuPico_Flexx = new QMenu(menuCamera);
        menuPico_Flexx->setObjectName(QStringLiteral("menuPico_Flexx"));
        menuIntel_Realsense = new QMenu(menuCamera);
        menuIntel_Realsense->setObjectName(QStringLiteral("menuIntel_Realsense"));
        MainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowClass->setStatusBar(statusBar);

        menuBar->addAction(menuCamera->menuAction());
        menuCamera->addAction(menuPico_Flexx->menuAction());
        menuCamera->addAction(menuIntel_Realsense->menuAction());
        menuPico_Flexx->addAction(_startFlexxAction);
        menuPico_Flexx->addAction(_stopFlexxAction);
        menuIntel_Realsense->addAction(_startRSAction);
        menuIntel_Realsense->addAction(_stopRSAction);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        _startFlexxAction->setText(QApplication::translate("MainWindowClass", "Open", Q_NULLPTR));
        _stopFlexxAction->setText(QApplication::translate("MainWindowClass", "Close", Q_NULLPTR));
        _startRSAction->setText(QApplication::translate("MainWindowClass", "Open", Q_NULLPTR));
        _stopRSAction->setText(QApplication::translate("MainWindowClass", "Close", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindowClass", "Camera", Q_NULLPTR));
        menuPico_Flexx->setTitle(QApplication::translate("MainWindowClass", "Pico Flexx", Q_NULLPTR));
        menuIntel_Realsense->setTitle(QApplication::translate("MainWindowClass", "Intel Realsense", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
