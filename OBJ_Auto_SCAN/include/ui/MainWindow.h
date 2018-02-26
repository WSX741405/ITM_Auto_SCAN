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
#include <QFileDialog>
#include<QInputDialog>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "file/FileFactory.h"
#include "grabber/GrabberFactory.h"
#include "pointCloud/MyPointClouds.h"
#include "pointCloud/MyICP.h"
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
	char* COM_PORT = "com4";
public:
	MainWindow(QWidget *parent = Q_NULLPTR);

signals:
	void OutputDialog(const char* title, const char* context);

public slots:
	//****************************************************************
	//										File
	//****************************************************************
	void OpenFileSlot();
	void SaveFileSlot();
	//****************************************************************
	//										Camera
	//****************************************************************
	void StartFlexxCameraSlot();
	void StartRSCameraSlot();
	void StopCameraSlot();
	void SetCameraDepthConfidenceSlot();
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
	void IterativeClosestPointSlot();
	void TableItemChangeSlot(QTableWidgetItem* item);

private:
	void InitialConnectSlots();
	void InitialPointCloudViewer();
	void InitialPointCloudTable();
	void UpdatePointCloudViewer();
	void UpdatePointCloudTable();
	void RegisterObserver();
	void closeEvent(QCloseEvent *event);
	void OpenFile(std::string dir, std::string filter);
	void SaveFile(std::string dir, std::string filter);

	std::string InputDialog(bool* ok, const char* title = "", const char* label = "", const char* text = "");

	Viewer* _viewer;
	UIObserver* _uiObserver;
	FileFactory* _fileFactory;
	GrabberFactory* _grabberFactory;
	IGrabber* _grabber;
	SubjectFactory* _subjectFactory;
	boost::shared_ptr<pcl::PointCloud<PointT>> _tmpPointCloud;
	MyPointClouds* _pointClouds;
	Arduino* _arduino;
	Ui::MainWindowForm* _ui;
};

#endif