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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindowForm
{
public:
    QAction *_startFlexxAction;
    QAction *_stopFlexxAction;
    QAction *_startRSAction;
    QAction *_stopRSAction;
    QAction *_getNumberOfBytesAction;
    QAction *_getCharAction;
    QAction *_getArrayAction;
    QAction *_controlMotorAction;
    QAction *_keepPointCloudAction;
    QAction *_setConfidenceAction;
    QWidget *centralWidget;
    QVTKWidget *_qvtkWidget;
    QTableWidget *_pointCloudTable;
    QMenuBar *menuBar;
    QMenu *menuCamera;
    QMenu *menuPico_Flexx;
    QMenu *menuIntel_Realsense;
    QMenu *menuArduino;
    QMenu *menucommunicate;
    QMenu *menuControl_Motor;
    QMenu *menuPointCloud;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindowForm)
    {
        if (MainWindowForm->objectName().isEmpty())
            MainWindowForm->setObjectName(QStringLiteral("MainWindowForm"));
        MainWindowForm->resize(1300, 850);
        _startFlexxAction = new QAction(MainWindowForm);
        _startFlexxAction->setObjectName(QStringLiteral("_startFlexxAction"));
        _stopFlexxAction = new QAction(MainWindowForm);
        _stopFlexxAction->setObjectName(QStringLiteral("_stopFlexxAction"));
        _startRSAction = new QAction(MainWindowForm);
        _startRSAction->setObjectName(QStringLiteral("_startRSAction"));
        _stopRSAction = new QAction(MainWindowForm);
        _stopRSAction->setObjectName(QStringLiteral("_stopRSAction"));
        _getNumberOfBytesAction = new QAction(MainWindowForm);
        _getNumberOfBytesAction->setObjectName(QStringLiteral("_getNumberOfBytesAction"));
        _getCharAction = new QAction(MainWindowForm);
        _getCharAction->setObjectName(QStringLiteral("_getCharAction"));
        _getArrayAction = new QAction(MainWindowForm);
        _getArrayAction->setObjectName(QStringLiteral("_getArrayAction"));
        _controlMotorAction = new QAction(MainWindowForm);
        _controlMotorAction->setObjectName(QStringLiteral("_controlMotorAction"));
        _keepPointCloudAction = new QAction(MainWindowForm);
        _keepPointCloudAction->setObjectName(QStringLiteral("_keepPointCloudAction"));
        _setConfidenceAction = new QAction(MainWindowForm);
        _setConfidenceAction->setObjectName(QStringLiteral("_setConfidenceAction"));
        centralWidget = new QWidget(MainWindowForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _qvtkWidget = new QVTKWidget(centralWidget);
        _qvtkWidget->setObjectName(QStringLiteral("_qvtkWidget"));
        _qvtkWidget->setGeometry(QRect(30, 30, 730, 730));
        _pointCloudTable = new QTableWidget(centralWidget);
        _pointCloudTable->setObjectName(QStringLiteral("_pointCloudTable"));
        _pointCloudTable->setGeometry(QRect(800, 30, 460, 200));
        MainWindowForm->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowForm);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1300, 21));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        menuPico_Flexx = new QMenu(menuCamera);
        menuPico_Flexx->setObjectName(QStringLiteral("menuPico_Flexx"));
        menuIntel_Realsense = new QMenu(menuCamera);
        menuIntel_Realsense->setObjectName(QStringLiteral("menuIntel_Realsense"));
        menuArduino = new QMenu(menuBar);
        menuArduino->setObjectName(QStringLiteral("menuArduino"));
        menucommunicate = new QMenu(menuArduino);
        menucommunicate->setObjectName(QStringLiteral("menucommunicate"));
        menuControl_Motor = new QMenu(menuArduino);
        menuControl_Motor->setObjectName(QStringLiteral("menuControl_Motor"));
        menuPointCloud = new QMenu(menuBar);
        menuPointCloud->setObjectName(QStringLiteral("menuPointCloud"));
        MainWindowForm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowForm);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowForm->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowForm->setStatusBar(statusBar);

        menuBar->addAction(menuCamera->menuAction());
        menuBar->addAction(menuArduino->menuAction());
        menuBar->addAction(menuPointCloud->menuAction());
        menuCamera->addAction(menuPico_Flexx->menuAction());
        menuCamera->addAction(menuIntel_Realsense->menuAction());
        menuPico_Flexx->addAction(_startFlexxAction);
        menuPico_Flexx->addAction(_stopFlexxAction);
        menuPico_Flexx->addAction(_setConfidenceAction);
        menuIntel_Realsense->addAction(_startRSAction);
        menuIntel_Realsense->addAction(_stopRSAction);
        menuArduino->addAction(menucommunicate->menuAction());
        menuArduino->addAction(menuControl_Motor->menuAction());
        menucommunicate->addAction(_getNumberOfBytesAction);
        menucommunicate->addAction(_getCharAction);
        menucommunicate->addAction(_getArrayAction);
        menuControl_Motor->addAction(_controlMotorAction);
        menuPointCloud->addAction(_keepPointCloudAction);

        retranslateUi(MainWindowForm);

        QMetaObject::connectSlotsByName(MainWindowForm);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowForm)
    {
        MainWindowForm->setWindowTitle(QApplication::translate("MainWindowForm", "MainWindow", Q_NULLPTR));
        _startFlexxAction->setText(QApplication::translate("MainWindowForm", "Open", Q_NULLPTR));
        _stopFlexxAction->setText(QApplication::translate("MainWindowForm", "Close", Q_NULLPTR));
        _startRSAction->setText(QApplication::translate("MainWindowForm", "Open", Q_NULLPTR));
        _stopRSAction->setText(QApplication::translate("MainWindowForm", "Close", Q_NULLPTR));
        _getNumberOfBytesAction->setText(QApplication::translate("MainWindowForm", "Get # Bytes Of Data", Q_NULLPTR));
        _getCharAction->setText(QApplication::translate("MainWindowForm", "Get Char", Q_NULLPTR));
        _getArrayAction->setText(QApplication::translate("MainWindowForm", "Get Array", Q_NULLPTR));
        _controlMotorAction->setText(QApplication::translate("MainWindowForm", "Control Motor", Q_NULLPTR));
        _keepPointCloudAction->setText(QApplication::translate("MainWindowForm", "Keep PointCloud", Q_NULLPTR));
        _setConfidenceAction->setText(QApplication::translate("MainWindowForm", "Set Confidence", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindowForm", "Camera", Q_NULLPTR));
        menuPico_Flexx->setTitle(QApplication::translate("MainWindowForm", "Pico Flexx", Q_NULLPTR));
        menuIntel_Realsense->setTitle(QApplication::translate("MainWindowForm", "Intel Realsense", Q_NULLPTR));
        menuArduino->setTitle(QApplication::translate("MainWindowForm", "Arduino", Q_NULLPTR));
        menucommunicate->setTitle(QApplication::translate("MainWindowForm", "Communicate", Q_NULLPTR));
        menuControl_Motor->setTitle(QApplication::translate("MainWindowForm", "Control Motor", Q_NULLPTR));
        menuPointCloud->setTitle(QApplication::translate("MainWindowForm", "PointClouds", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowForm: public Ui_MainWindowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
