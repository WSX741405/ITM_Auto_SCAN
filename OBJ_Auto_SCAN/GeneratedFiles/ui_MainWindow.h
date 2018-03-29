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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
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
    QAction *_setConfidenceAction;
    QAction *_IterativeClosestPointAction;
    QAction *_openFileAction;
    QAction *_saveFileAction;
    QAction *_keepOneFrameAction;
    QAction *_keepContinueFrameAction;
    QAction *actionFeature;
    QWidget *centralWidget;
    QVTKWidget *_qvtkWidget;
    QTableWidget *_pointCloudTable;
    QTabWidget *_processingTabWidget;
    QWidget *tab_3;
    QTabWidget *_filterTabWidget;
    QWidget *tab;
    QLabel *label;
    QLabel *label_2;
    QDoubleSpinBox *_voxelGridYSpinBox;
    QDoubleSpinBox *_voxelGridZSpinBox;
    QDoubleSpinBox *_voxelGridXSpinBox;
    QLabel *label_3;
    QWidget *_boundingBoxTab;
    QDoubleSpinBox *_boundingBoxMinYSpinBox;
    QLabel *label_5;
    QDoubleSpinBox *_boundingBoxMinXSpinBox;
    QLabel *label_6;
    QDoubleSpinBox *_boundingBoxMinZSpinBox;
    QLabel *label_7;
    QDoubleSpinBox *_boundingBoxMaxXSpinBox;
    QDoubleSpinBox *_boundingBoxMaxZSpinBox;
    QDoubleSpinBox *_boundingBoxMaxYSpinBox;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *_filterProcessingButton;
    QWidget *tab_4;
    QTabWidget *_keypointTabWidget;
    QWidget *tab_5;
    QLabel *_siftMinScaleLabel;
    QLabel *_siftNROctavesLabel;
    QLabel *_siftNRScalesPerOctaveLabel;
    QDoubleSpinBox *_siftMinScaleSpinBox;
    QLabel *_siftMinContrastLabel;
    QDoubleSpinBox *_siftMinContrastSpinBox;
    QSpinBox *_siftNROctavesSpinBox;
    QSpinBox *_siftNRScalesPerOctaveSpinBox;
    QWidget *tab_6;
    QLabel *_harrisSetRadiusSearchLabel;
    QLabel *_harrisRadiusLabel;
    QDoubleSpinBox *_harrisRadiusSpinBox;
    QDoubleSpinBox *_harrisRadiusSearchSpinBox;
    QLabel *label_4;
    QComboBox *_harrisMethodComboBox;
    QPushButton *_keypointProcessingButton;
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
        _pointCloudTable = new QTableWidget(centralWidget);
        _pointCloudTable->setObjectName(QStringLiteral("_pointCloudTable"));
        _pointCloudTable->setGeometry(QRect(790, 30, 460, 200));
        _processingTabWidget = new QTabWidget(centralWidget);
        _processingTabWidget->setObjectName(QStringLiteral("_processingTabWidget"));
        _processingTabWidget->setGeometry(QRect(790, 270, 460, 490));
        QFont font;
        font.setPointSize(20);
        _processingTabWidget->setFont(font);
        _processingTabWidget->setDocumentMode(false);
        _processingTabWidget->setTabsClosable(false);
        _processingTabWidget->setMovable(false);
        _processingTabWidget->setTabBarAutoHide(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        _filterTabWidget = new QTabWidget(tab_3);
        _filterTabWidget->setObjectName(QStringLiteral("_filterTabWidget"));
        _filterTabWidget->setGeometry(QRect(20, 20, 420, 360));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 50, 30));
        label->setFont(font);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 50, 30));
        label_2->setFont(font);
        _voxelGridYSpinBox = new QDoubleSpinBox(tab);
        _voxelGridYSpinBox->setObjectName(QStringLiteral("_voxelGridYSpinBox"));
        _voxelGridYSpinBox->setGeometry(QRect(80, 70, 80, 30));
        _voxelGridYSpinBox->setFont(font);
        _voxelGridYSpinBox->setMinimum(0.01);
        _voxelGridYSpinBox->setMaximum(1);
        _voxelGridYSpinBox->setSingleStep(0.01);
        _voxelGridYSpinBox->setValue(0.01);
        _voxelGridZSpinBox = new QDoubleSpinBox(tab);
        _voxelGridZSpinBox->setObjectName(QStringLiteral("_voxelGridZSpinBox"));
        _voxelGridZSpinBox->setGeometry(QRect(80, 120, 80, 30));
        _voxelGridZSpinBox->setFont(font);
        _voxelGridZSpinBox->setMinimum(0.01);
        _voxelGridZSpinBox->setMaximum(1);
        _voxelGridZSpinBox->setSingleStep(0.01);
        _voxelGridZSpinBox->setValue(0.01);
        _voxelGridXSpinBox = new QDoubleSpinBox(tab);
        _voxelGridXSpinBox->setObjectName(QStringLiteral("_voxelGridXSpinBox"));
        _voxelGridXSpinBox->setGeometry(QRect(80, 20, 80, 30));
        _voxelGridXSpinBox->setFont(font);
        _voxelGridXSpinBox->setMinimum(0.01);
        _voxelGridXSpinBox->setMaximum(1);
        _voxelGridXSpinBox->setSingleStep(0.01);
        _voxelGridXSpinBox->setValue(0.01);
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 50, 30));
        label_3->setFont(font);
        _filterTabWidget->addTab(tab, QString());
        _boundingBoxTab = new QWidget();
        _boundingBoxTab->setObjectName(QStringLiteral("_boundingBoxTab"));
        _boundingBoxMinYSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMinYSpinBox->setObjectName(QStringLiteral("_boundingBoxMinYSpinBox"));
        _boundingBoxMinYSpinBox->setGeometry(QRect(80, 70, 80, 30));
        _boundingBoxMinYSpinBox->setFont(font);
        _boundingBoxMinYSpinBox->setMinimum(0.01);
        _boundingBoxMinYSpinBox->setMaximum(1);
        _boundingBoxMinYSpinBox->setSingleStep(0.01);
        _boundingBoxMinYSpinBox->setValue(0.01);
        label_5 = new QLabel(_boundingBoxTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 120, 50, 30));
        label_5->setFont(font);
        _boundingBoxMinXSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMinXSpinBox->setObjectName(QStringLiteral("_boundingBoxMinXSpinBox"));
        _boundingBoxMinXSpinBox->setGeometry(QRect(80, 20, 80, 30));
        _boundingBoxMinXSpinBox->setFont(font);
        _boundingBoxMinXSpinBox->setMinimum(0.01);
        _boundingBoxMinXSpinBox->setMaximum(1);
        _boundingBoxMinXSpinBox->setSingleStep(0.01);
        _boundingBoxMinXSpinBox->setValue(0.01);
        label_6 = new QLabel(_boundingBoxTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 20, 50, 30));
        label_6->setFont(font);
        _boundingBoxMinZSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMinZSpinBox->setObjectName(QStringLiteral("_boundingBoxMinZSpinBox"));
        _boundingBoxMinZSpinBox->setGeometry(QRect(80, 120, 80, 30));
        _boundingBoxMinZSpinBox->setFont(font);
        _boundingBoxMinZSpinBox->setMinimum(0.01);
        _boundingBoxMinZSpinBox->setMaximum(1);
        _boundingBoxMinZSpinBox->setSingleStep(0.01);
        _boundingBoxMinZSpinBox->setValue(0.01);
        label_7 = new QLabel(_boundingBoxTab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 70, 50, 30));
        label_7->setFont(font);
        _boundingBoxMaxXSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMaxXSpinBox->setObjectName(QStringLiteral("_boundingBoxMaxXSpinBox"));
        _boundingBoxMaxXSpinBox->setGeometry(QRect(230, 20, 80, 30));
        _boundingBoxMaxXSpinBox->setFont(font);
        _boundingBoxMaxXSpinBox->setMinimum(0.01);
        _boundingBoxMaxXSpinBox->setMaximum(1);
        _boundingBoxMaxXSpinBox->setSingleStep(0.01);
        _boundingBoxMaxXSpinBox->setValue(0.09);
        _boundingBoxMaxZSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMaxZSpinBox->setObjectName(QStringLiteral("_boundingBoxMaxZSpinBox"));
        _boundingBoxMaxZSpinBox->setGeometry(QRect(230, 120, 80, 30));
        _boundingBoxMaxZSpinBox->setFont(font);
        _boundingBoxMaxZSpinBox->setMinimum(0.01);
        _boundingBoxMaxZSpinBox->setMaximum(1);
        _boundingBoxMaxZSpinBox->setSingleStep(0.01);
        _boundingBoxMaxZSpinBox->setValue(0.09);
        _boundingBoxMaxYSpinBox = new QDoubleSpinBox(_boundingBoxTab);
        _boundingBoxMaxYSpinBox->setObjectName(QStringLiteral("_boundingBoxMaxYSpinBox"));
        _boundingBoxMaxYSpinBox->setGeometry(QRect(230, 70, 80, 30));
        _boundingBoxMaxYSpinBox->setFont(font);
        _boundingBoxMaxYSpinBox->setMinimum(0.01);
        _boundingBoxMaxYSpinBox->setMaximum(1);
        _boundingBoxMaxYSpinBox->setSingleStep(0.01);
        _boundingBoxMaxYSpinBox->setValue(0.09);
        label_8 = new QLabel(_boundingBoxTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(190, 20, 50, 30));
        label_8->setFont(font);
        label_9 = new QLabel(_boundingBoxTab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(190, 70, 50, 30));
        label_9->setFont(font);
        label_10 = new QLabel(_boundingBoxTab);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(190, 120, 50, 30));
        label_10->setFont(font);
        _filterTabWidget->addTab(_boundingBoxTab, QString());
        _filterProcessingButton = new QPushButton(tab_3);
        _filterProcessingButton->setObjectName(QStringLiteral("_filterProcessingButton"));
        _filterProcessingButton->setGeometry(QRect(20, 400, 150, 40));
        QFont font1;
        font1.setPointSize(16);
        _filterProcessingButton->setFont(font1);
        _processingTabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        _keypointTabWidget = new QTabWidget(tab_4);
        _keypointTabWidget->setObjectName(QStringLiteral("_keypointTabWidget"));
        _keypointTabWidget->setGeometry(QRect(20, 20, 420, 360));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        _siftMinScaleLabel = new QLabel(tab_5);
        _siftMinScaleLabel->setObjectName(QStringLiteral("_siftMinScaleLabel"));
        _siftMinScaleLabel->setGeometry(QRect(30, 20, 130, 30));
        _siftNROctavesLabel = new QLabel(tab_5);
        _siftNROctavesLabel->setObjectName(QStringLiteral("_siftNROctavesLabel"));
        _siftNROctavesLabel->setGeometry(QRect(30, 70, 160, 30));
        _siftNRScalesPerOctaveLabel = new QLabel(tab_5);
        _siftNRScalesPerOctaveLabel->setObjectName(QStringLiteral("_siftNRScalesPerOctaveLabel"));
        _siftNRScalesPerOctaveLabel->setGeometry(QRect(30, 120, 250, 30));
        _siftMinScaleSpinBox = new QDoubleSpinBox(tab_5);
        _siftMinScaleSpinBox->setObjectName(QStringLiteral("_siftMinScaleSpinBox"));
        _siftMinScaleSpinBox->setGeometry(QRect(280, 20, 80, 30));
        _siftMinScaleSpinBox->setMinimum(0.01);
        _siftMinScaleSpinBox->setMaximum(1);
        _siftMinScaleSpinBox->setSingleStep(0.01);
        _siftMinScaleSpinBox->setValue(0.01);
        _siftMinContrastLabel = new QLabel(tab_5);
        _siftMinContrastLabel->setObjectName(QStringLiteral("_siftMinContrastLabel"));
        _siftMinContrastLabel->setGeometry(QRect(30, 170, 160, 30));
        _siftMinContrastSpinBox = new QDoubleSpinBox(tab_5);
        _siftMinContrastSpinBox->setObjectName(QStringLiteral("_siftMinContrastSpinBox"));
        _siftMinContrastSpinBox->setGeometry(QRect(280, 170, 80, 30));
        _siftMinContrastSpinBox->setSingleStep(0.1);
        _siftNROctavesSpinBox = new QSpinBox(tab_5);
        _siftNROctavesSpinBox->setObjectName(QStringLiteral("_siftNROctavesSpinBox"));
        _siftNROctavesSpinBox->setGeometry(QRect(280, 70, 80, 30));
        _siftNROctavesSpinBox->setMinimum(1);
        _siftNROctavesSpinBox->setValue(3);
        _siftNRScalesPerOctaveSpinBox = new QSpinBox(tab_5);
        _siftNRScalesPerOctaveSpinBox->setObjectName(QStringLiteral("_siftNRScalesPerOctaveSpinBox"));
        _siftNRScalesPerOctaveSpinBox->setGeometry(QRect(280, 120, 80, 30));
        _siftNRScalesPerOctaveSpinBox->setMinimum(1);
        _siftNRScalesPerOctaveSpinBox->setValue(2);
        _keypointTabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        _harrisSetRadiusSearchLabel = new QLabel(tab_6);
        _harrisSetRadiusSearchLabel->setObjectName(QStringLiteral("_harrisSetRadiusSearchLabel"));
        _harrisSetRadiusSearchLabel->setGeometry(QRect(30, 120, 200, 30));
        _harrisRadiusLabel = new QLabel(tab_6);
        _harrisRadiusLabel->setObjectName(QStringLiteral("_harrisRadiusLabel"));
        _harrisRadiusLabel->setGeometry(QRect(30, 70, 130, 30));
        _harrisRadiusSpinBox = new QDoubleSpinBox(tab_6);
        _harrisRadiusSpinBox->setObjectName(QStringLiteral("_harrisRadiusSpinBox"));
        _harrisRadiusSpinBox->setGeometry(QRect(280, 70, 80, 30));
        _harrisRadiusSpinBox->setMinimum(0.01);
        _harrisRadiusSpinBox->setMaximum(1);
        _harrisRadiusSpinBox->setSingleStep(0.01);
        _harrisRadiusSpinBox->setValue(0.01);
        _harrisRadiusSearchSpinBox = new QDoubleSpinBox(tab_6);
        _harrisRadiusSearchSpinBox->setObjectName(QStringLiteral("_harrisRadiusSearchSpinBox"));
        _harrisRadiusSearchSpinBox->setGeometry(QRect(280, 120, 80, 30));
        _harrisRadiusSearchSpinBox->setMinimum(0.01);
        _harrisRadiusSearchSpinBox->setMaximum(1);
        _harrisRadiusSearchSpinBox->setSingleStep(0.01);
        _harrisRadiusSearchSpinBox->setValue(0.01);
        label_4 = new QLabel(tab_6);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 20, 130, 30));
        _harrisMethodComboBox = new QComboBox(tab_6);
        _harrisMethodComboBox->setObjectName(QStringLiteral("_harrisMethodComboBox"));
        _harrisMethodComboBox->setGeometry(QRect(190, 20, 170, 30));
        _keypointTabWidget->addTab(tab_6, QString());
        _keypointProcessingButton = new QPushButton(tab_4);
        _keypointProcessingButton->setObjectName(QStringLiteral("_keypointProcessingButton"));
        _keypointProcessingButton->setGeometry(QRect(20, 400, 150, 40));
        _keypointProcessingButton->setFont(font1);
        _processingTabWidget->addTab(tab_4, QString());
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

        _processingTabWidget->setCurrentIndex(0);
        _filterTabWidget->setCurrentIndex(0);
        _keypointTabWidget->setCurrentIndex(0);


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
        label->setText(QApplication::translate("MainWindowForm", "X\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindowForm", "Y\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindowForm", "Z\357\274\232", Q_NULLPTR));
        _filterTabWidget->setTabText(_filterTabWidget->indexOf(tab), QApplication::translate("MainWindowForm", "Voxel Grid", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindowForm", "Z\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindowForm", "X\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindowForm", "Y\357\274\232", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindowForm", "~", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindowForm", "~", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindowForm", "~", Q_NULLPTR));
        _filterTabWidget->setTabText(_filterTabWidget->indexOf(_boundingBoxTab), QApplication::translate("MainWindowForm", "Bounding Box", Q_NULLPTR));
        _filterProcessingButton->setText(QApplication::translate("MainWindowForm", "Processing", Q_NULLPTR));
        _processingTabWidget->setTabText(_processingTabWidget->indexOf(tab_3), QApplication::translate("MainWindowForm", "Filter", Q_NULLPTR));
        _siftMinScaleLabel->setText(QApplication::translate("MainWindowForm", "Min Scale\357\274\232", Q_NULLPTR));
        _siftNROctavesLabel->setText(QApplication::translate("MainWindowForm", "NR Octaves\357\274\232", Q_NULLPTR));
        _siftNRScalesPerOctaveLabel->setText(QApplication::translate("MainWindowForm", "NR Scales Per Octave\357\274\232", Q_NULLPTR));
        _siftMinContrastLabel->setText(QApplication::translate("MainWindowForm", "Min Contrast\357\274\232", Q_NULLPTR));
        _keypointTabWidget->setTabText(_keypointTabWidget->indexOf(tab_5), QApplication::translate("MainWindowForm", "SIFT3D", Q_NULLPTR));
        _harrisSetRadiusSearchLabel->setText(QApplication::translate("MainWindowForm", "Set Radius Search\357\274\232", Q_NULLPTR));
        _harrisRadiusLabel->setText(QApplication::translate("MainWindowForm", "Set Radius\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindowForm", "Method\357\274\232", Q_NULLPTR));
        _harrisMethodComboBox->clear();
        _harrisMethodComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindowForm", "Harris3D", Q_NULLPTR)
         << QApplication::translate("MainWindowForm", "Tomasi3D", Q_NULLPTR)
         << QApplication::translate("MainWindowForm", "Noble3D", Q_NULLPTR)
         << QApplication::translate("MainWindowForm", "Lowe3D", Q_NULLPTR)
         << QApplication::translate("MainWindowForm", "Curvature3D", Q_NULLPTR)
        );
        _keypointTabWidget->setTabText(_keypointTabWidget->indexOf(tab_6), QApplication::translate("MainWindowForm", "Harris3D", Q_NULLPTR));
        _keypointProcessingButton->setText(QApplication::translate("MainWindowForm", "Processing", Q_NULLPTR));
        _processingTabWidget->setTabText(_processingTabWidget->indexOf(tab_4), QApplication::translate("MainWindowForm", "Keypoint", Q_NULLPTR));
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
