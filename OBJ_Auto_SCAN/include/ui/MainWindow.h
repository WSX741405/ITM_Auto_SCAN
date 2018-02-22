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
#include "pointCloud/MyPointClouds.h"
#include "arduino/Arduino.h"
#include "Conversion.h"

class UIObserver;
class ISubject;
class SubjectFactory;
class IGrabber;
class GrabberFactory;
class Arduino;

class MainWindow : public QMainWindow
{
	Q_OBJECT
	int ARDUINO_SLEEP_TIME = 300;
	char* COM_PORT = "com3";
public:
	MainWindow(QWidget *parent = Q_NULLPTR);

signals:
	void OutputDialog(const char* title, const char* context);

public slots:
	//****************************************************************
	//										Camera
	//****************************************************************
	void StartFlexxCameraSlot();
	void StopFlexxCameraSlot();
	void StartRSCameraSlot();
	void StopRSCameraSlot();
	void UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud);
	//****************************************************************
	//										Arduino
	//****************************************************************
	void GetNumberOfBytesSlot();
	void GetCharSlot();
	void GetArraySlot();
	void ControlMotorSlot();
	//****************************************************************
	//										Point Cloud
	//****************************************************************
	void KeepPointCloudSlot();
	void TableItemChangeSlot(QTableWidgetItem* item);

private:
	void ConnectSlots();
	void InitialPointCloudViewer();
	void InitialPointCloudTable();
	void UpdatePointCloudViewer();
	void UpdatePointCloudTable();
	void RegisterObserver();
	void closeEvent(QCloseEvent *event);

	std::string InputDialog(bool* ok, const char* title = "", const char* label = "", const char* text = "");

	Viewer* _viewer;
	UIObserver* _uiObserver;
	GrabberFactory* _grabberFactory;
	SubjectFactory* _subjectFactory;
	boost::shared_ptr<pcl::PointCloud<PointT>> _tmpPointCloud;
	MyPointClouds* _pointClouds;
	Arduino* _arduino;
	Ui::MainWindowForm* _ui;
};

#endif