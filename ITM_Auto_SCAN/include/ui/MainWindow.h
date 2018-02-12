#ifndef MAIN_WINDOW
#define MAIN_WINDOW

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
#include<QMessageBox>
#include<QInputDialog>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "grabber/GrabberFactory.h"
#include "arduino/arduino.h"
#include "stringMethod.h"

class UIObserver;
class ISubject;
class SubjectFactory;
class IGrabber;
class GrabberFactory;
class Arduino;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	char* COM_PORT = "com4";
public:
	MainWindow(QWidget *parent = Q_NULLPTR);

public slots:
	//****************************************************************
	//										Camera
	//****************************************************************
	void StartFlexxCameraSlot();
	void StopFlexxCameraSlot();
	void StartRSCameraSlot();
	void StopRSCameraSlot();
	void UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud);
	//****************************************************************
	//										Arduino
	//****************************************************************
	void GetNumberOfBytesSlot();
	void GetCharSlot();
	void GetArraySlot();
	void ControlMotorSlot();

private:
	void ConnectSlots();
	void InitialViewer();
	void RegisterObserver();
	void closeEvent(QCloseEvent *event);

	std::string InputDialog(const char* title = "", const char* label = "", const char* text = "");

	Viewer* _viewer;
	UIObserver* _uiObserver;
	GrabberFactory* _grabberFactory;
	SubjectFactory* _subjectFactory;
	Arduino* _arduino;
	Ui::MainWindowClass* _ui;
};

#endif