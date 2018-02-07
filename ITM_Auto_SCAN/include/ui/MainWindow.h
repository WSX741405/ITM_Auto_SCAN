#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>

typedef pcl::PointXYZRGBA PointT;
#include <QMetaType>
Q_DECLARE_METATYPE(boost::shared_ptr<pcl::PointCloud<PointT>>);

#include <QVTKWidget.h>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "grabber/GrabberFactory.h"
#include "arduino/arduino.h"

class UIObserver;
class ISubject;
class SubjectFactory;
class IGrabber;
class GrabberFactory;
class Arduino;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	//****************************************************************
	//										Camera
	//****************************************************************
	void	StartFlexxCameraSlot();
	void StopFlexxCameraSlot();
	void	StartRSCameraSlot();
	void StopRSCameraSlot();
	void UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud);
	//****************************************************************
	//										Arduino
	//****************************************************************
	void CommunicateArduinoSlot();

private:
	void ConnectSlots();
	void InitialViewer();
	void RegisterObserver();
	void closeEvent(QCloseEvent *event);

	Viewer* _viewer;
	UIObserver* _uiObserver;
	GrabberFactory* _grabberFactory;
	SubjectFactory* _subjectFactory;
	Arduino* _arduino;
	//ISubject* _subject;
	Ui::MainWindowClass* _ui;
};
