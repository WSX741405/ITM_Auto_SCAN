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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
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
    QAction *_setConfidenceAction;
    QAction *_IterativeClosestPointAction;
    QAction *_openFileAction;
    QAction *_saveFileAction;
    QAction *_keepOneFrameAction;
    QAction *_keepContinueFrameAction;
    QAction *actionFeature;
    QWidget *centralWidget;
    QVTKWidget *_qvtkWidget;
    QToolBox *toolBox;
    QWidget *_filterProcessingPage;
    QPushButton *_filterProcessingButton;
    QComboBox *comboBox;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *_filterXSpinBox;
    QDoubleSpinBox *_filterYSpinBox;
    QDoubleSpinBox *_filterZSpinBox;
    QLabel *label_4;
    QWidget *_featureProcessingPage;
    QComboBox *_selectedProcessComboBox;
    QPushButton *_featureProcessingButton;
    QTableWidget *_pointCloudTable;
    QMenuBar *menuBar;
    QMenu *menuCamera;
    QMenu *menuPico_Flexx;
    QMenu *menuIntel_Realsense;
    QMenu *menuArduino;
    QMenu *menucommunicate;
    QMenu *menuControl_Motor;
    QMenu *menuFile;
    QMenu *menuPointCloud;
    QMenu *menuKeep_PointCloud;
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
        _setConfidenceAction = new QAction(MainWindowForm);
        _setConfidenceAction->setObjectName(QStringLiteral("_setConfidenceAction"));
        _IterativeClosestPointAction = new QAction(MainWindowForm);
        _IterativeClosestPointAction->setObjectName(QStringLiteral("_IterativeClosestPointAction"));
        _openFileAction = new QAction(MainWindowForm);
        _openFileAction->setObjectName(QStringLiteral("_openFileAction"));
        _saveFileAction = new QAction(MainWindowForm);
        _saveFileAction->setObjectName(QStringLiteral("_saveFileAction"));
        _keepOneFrameAction = new QAction(MainWindowForm);
        _keepOneFrameAction->setObjectName(QStringLiteral("_keepOneFrameAction"));
        _keepContinueFrameAction = new QAction(MainWindowForm);
        _keepContinueFrameAction->setObjectName(QStringLiteral("_keepContinueFrameAction"));
        actionFeature = new QAction(MainWindowForm);
        actionFeature->setObjectName(QStringLiteral("actionFeature"));
        centralWidget = new QWidget(MainWindowForm);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _qvtkWidget = new QVTKWidget(centralWidget);
        _qvtkWidget->setObjectName(QStringLiteral("_qvtkWidget"));
        _qvtkWidget->setGeometry(QRect(30, 30, 730, 730));
        toolBox = new QToolBox(centralWidget);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(790, 270, 460, 490));
        _filterProcessingPage = new QWidget();
        _filterProcessingPage->setObjectName(QStringLiteral("_filterProcessingPage"));
        _filterProcessingPage->setGeometry(QRect(0, 0, 460, 438));
        _filterProcessingButton = new QPushButton(_filterProcessingPage);
        _filterProcessingButton->setObjectName(QStringLiteral("_filterProcessingButton"));
        _filterProcessingButton->setGeometry(QRect(30, 300, 150, 40));
        QFont font;
        font.setPointSize(20);
        _filterProcessingButton->setFont(font);
        comboBox = new QComboBox(_filterProcessingPage);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(140, 30, 150, 40));
        comboBox->setFont(font);
        label_3 = new QLabel(_filterProcessingPage);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 200, 50, 30));
        label_3->setFont(font);
        label = new QLabel(_filterProcessingPage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 100, 50, 30));
        label->setFont(font);
        label_2 = new QLabel(_filterProcessingPage);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 150, 50, 30));
        label_2->setFont(font);
        _filterXSpinBox = new QDoubleSpinBox(_filterProcessingPage);
        _filterXSpinBox->setObjectName(QStringLiteral("_filterXSpinBox"));
        _filterXSpinBox->setGeometry(QRect(80, 100, 80, 30));
        _filterXSpinBox->setFont(font);
        _filterXSpinBox->setSingleStep(0.01);
        _filterXSpinBox->setValue(0.01);
        _filterYSpinBox = new QDoubleSpinBox(_filterProcessingPage);
        _filterYSpinBox->setObjectName(QStringLiteral("_filterYSpinBox"));
        _filterYSpinBox->setGeometry(QRect(80, 150, 80, 30));
        _filterYSpinBox->setFont(font);
        _filterYSpinBox->setSingleStep(0.01);
        _filterYSpinBox->setValue(0.01);
        _filterZSpinBox = new QDoubleSpinBox(_filterProcessingPage);
        _filterZSpinBox->setObjectName(QStringLiteral("_filterZSpinBox"));
        _filterZSpinBox->setGeometry(QRect(80, 200, 80, 30));
        _filterZSpinBox->setFont(font);
        _filterZSpinBox->setSingleStep(0.01);
        _filterZSpinBox->setValue(0.01);
        label_4 = new QLabel(_filterProcessingPage);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 35, 100, 30));
        label_4->setFont(font);
        toolBox->addItem(_filterProcessingPage, QStringLiteral("Filter Processing"));
        _featureProcessingPage = new QWidget();
        _featureProcessingPage->setObjectName(QStringLiteral("_featureProcessingPage"));
        _featureProcessingPage->setGeometry(QRect(0, 0, 460, 438));
        _selectedProcessComboBox = new QComboBox(_featureProcessingPage);
        _selectedProcessComboBox->setObjectName(QStringLiteral("_selectedProcessComboBox"));
        _selectedProcessComboBox->setGeometry(QRect(30, 30, 150, 40));
        _selectedProcessComboBox->setFont(font);
        _featureProcessingButton = new QPushButton(_featureProcessingPage);
        _featureProcessingButton->setObjectName(QStringLiteral("_featureProcessingButton"));
        _featureProcessingButton->setGeometry(QRect(30, 300, 150, 40));
        _featureProcessingButton->setFont(font);
        toolBox->addItem(_featureProcessingPage, QStringLiteral("Feature Processing"));
        _pointCloudTable = new QTableWidget(centralWidget);
        _pointCloudTable->setObjectName(QStringLiteral("_pointCloudTable"));
        _pointCloudTable->setGeometry(QRect(790, 30, 460, 200));
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
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPointCloud = new QMenu(menuBar);
        menuPointCloud->setObjectName(QStringLiteral("menuPointCloud"));
        menuKeep_PointCloud = new QMenu(menuPointCloud);
        menuKeep_PointCloud->setObjectName(QStringLiteral("menuKeep_PointCloud"));
        MainWindowForm->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindowForm);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindowForm->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindowForm);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindowForm->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
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
        menuFile->addAction(_openFileAction);
        menuFile->addAction(_saveFileAction);
        menuPointCloud->addAction(menuKeep_PointCloud->menuAction());
        menuKeep_PointCloud->addAction(_keepOneFrameAction);
        menuKeep_PointCloud->addAction(_keepContinueFrameAction);

        retranslateUi(MainWindowForm);

        toolBox->setCurrentIndex(0);


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
        _setConfidenceAction->setText(QApplication::translate("MainWindowForm", "Set Confidence", Q_NULLPTR));
        _IterativeClosestPointAction->setText(QApplication::translate("MainWindowForm", "PCL IterativeClosestPoint", Q_NULLPTR));
        _openFileAction->setText(QApplication::translate("MainWindowForm", "Open File", Q_NULLPTR));
        _saveFileAction->setText(QApplication::translate("MainWindowForm", "Save File", Q_NULLPTR));
        _keepOneFrameAction->setText(QApplication::translate("MainWindowForm", "One Frame", Q_NULLPTR));
        _keepContinueFrameAction->setText(QApplication::translate("MainWindowForm", "Continue Frame", Q_NULLPTR));
        actionFeature->setText(QApplication::translate("MainWindowForm", "Feature", Q_NULLPTR));
        _filterProcessingButton->setText(QApplication::translate("MainWindowForm", "Processing", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowForm", "Voxel Grid", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindowForm", "Z\357\274\232", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindowForm", "X\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowForm", "Y\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowForm", "Method\357\274\232", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(_filterProcessingPage), QApplication::translate("MainWindowForm", "Filter Processing", Q_NULLPTR));
        _selectedProcessComboBox->clear();
        _selectedProcessComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowForm", "SIFT3D", Q_NULLPTR)
        );
        _selectedProcessComboBox->setCurrentText(QApplication::translate("MainWindowForm", "SIFT3D", Q_NULLPTR));
        _featureProcessingButton->setText(QApplication::translate("MainWindowForm", "Processing", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(_featureProcessingPage), QApplication::translate("MainWindowForm", "Feature Processing", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindowForm", "Camera", Q_NULLPTR));
        menuPico_Flexx->setTitle(QApplication::translate("MainWindowForm", "Pico Flexx", Q_NULLPTR));
        menuIntel_Realsense->setTitle(QApplication::translate("MainWindowForm", "Intel Realsense", Q_NULLPTR));
        menuArduino->setTitle(QApplication::translate("MainWindowForm", "Arduino", Q_NULLPTR));
        menucommunicate->setTitle(QApplication::translate("MainWindowForm", "Communicate", Q_NULLPTR));
        menuControl_Motor->setTitle(QApplication::translate("MainWindowForm", "Control Motor", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindowForm", "File", Q_NULLPTR));
        menuPointCloud->setTitle(QApplication::translate("MainWindowForm", "PointClouds", Q_NULLPTR));
        menuKeep_PointCloud->setTitle(QApplication::translate("MainWindowForm", "Keep PointCloud", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowForm: public Ui_MainWindowForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
