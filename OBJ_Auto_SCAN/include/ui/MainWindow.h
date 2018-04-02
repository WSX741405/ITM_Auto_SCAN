#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/harris_3d.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointXYZI KeypointT;
#include <QMetaType>
Q_DECLARE_METATYPE(pcl::PointCloud<PointT>::Ptr);

#include <QVTKWidget.h>
#include<QMessageBox>
#include <QFileDialog>
#include<QInputDialog>
#include <QSpinBox>
#include <QCloseEvent>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "file/FileFactory.h"
#include "grabber/GrabberFactory.h"
#include "pointCloud/MyPointClouds.h"
#include "arduino/Arduino.h"
#include "Conversion.h"
#include "pointCloudProcessing/keypoint/KeypointFactory.h"
#include "pointCloudProcessing/filter/FilterFactory.h"
#include "pointCloudProcessing/correspondences/CorrespondencesFactory.h"

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

public slots:
	//****************************************************************
	//										UI
	//****************************************************************
	void UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	void TableItemChangeSlot(QTableWidgetItem* item);
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
	void KeepOneFrameSlot();
	void KeepContinueFrameSlot();
	void KeepFrameSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	//****************************************************************
	//										Keypoint
	//****************************************************************
	void ProcessKeypointSlot();
	void ChangeKeypointTabSlot (int index);
	void SetSIFTScalesSlot();
	void SetSIFTMinContrastSlot();
	void SetHarrisRadiusSlot();
	void SetHarrisRadiusSearchSlot();
	void SetHarrisMethodSlot(int index);
	//****************************************************************
	//										Filter
	//****************************************************************
	void ChangeFilterTabSlot(int index);
	void ProcessFilterSlot();
	void SetVoxelGridXYZSlot();
	void SetBoundingBoxSlot();
	//****************************************************************
	//										Correspondences
	//****************************************************************
	void ProcessCorrespondencesSlot();
	void SetFPFHDescriptorRadiusSlot(double descriptorRadius);
	void SetFPFHNormalRadiusSlot(double normalRadius);
	void SetFPFHCorrespondencesKSlot(int correspondencesK);

private:
	void InitialConnectSlots();
	void InitialPointCloudViewer();
	void InitialPointCloudTable();
	void InitialTabWidget();
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
	int _nameNumber;
	std::string _keepCloudName;
	pcl::PointCloud<PointT>::Ptr _tmpPointCloud;
	MyPointClouds* _pointClouds;
	Arduino* _arduino;
	Ui::MainWindowForm* _ui;

	KeypointFactory* _keypointFactory;
	KeypointProcessing* _keypointProcessing;
	FilterFactory* _filterFactory;
	FilterProcessing* _filterProcessing;
	CorrespondencesFactory* _correspondencesFactory;
	CorrespondencesProcessing* _correspondencesProcessing;
};

#endif