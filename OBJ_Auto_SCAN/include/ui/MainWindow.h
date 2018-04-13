#ifndef MAIN_WINDOW
#define MAIN_WINDOW

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/keypoints/harris_3d.h>

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZI KeypointT;
typedef pcl::PointXYZRGBNormal SurfacePointT;

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
#include "pointCloud/PointCloudElements.h"
#include "arduino/Arduino.h"
#include "Conversion.h"
#include "pointCloudProcessing/keypoint/KeypointFactory.h"
#include "pointCloudProcessing/filter/FilterFactory.h"
#include "pointCloudProcessing/correspondences/CorrespondencesFactory.h"
#include "pointCloudProcessing/regestration/RegestrationFactory.h"
#include "pointCloudProcessing/reconstruct/ReconstructFactory.h"

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
	std::string ShowDialog(bool* ok, const char* title = "", const char* label = "", const char* text = "");

public slots:
	//****************************************************************
	//										UI
	//****************************************************************
	void UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	void TableItemChangeSlot(QTableWidgetItem* item);
	std::string ShowInputDialogSlot(bool* ok, const char* title = "", const char* label = "", const char* text = "");
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
	void KeepFrameArrivedSlot(pcl::PointCloud<PointT>::Ptr pointCloud);
	void RemoveSelectedPointCloudSlot();
	void RemoveAllPointCloudSlot();
	void SelectAllPointCloudSlot();
	void UnselectAllPointCloudSlot();
	void ProcessKeypoint2ICPSlot();
	//****************************************************************
	//										Keypoint
	//****************************************************************
	void ProcessKeypointSlot();
	void ChangeKeypointTabSlot(int index);
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
	void SetOutlierRemovalMeanKSlot(int meanK);
	void SetOutlierRemovalStddevMulThreshSlot(double stddevMulThresh);
	//****************************************************************
	//										Correspondences
	//****************************************************************
	void ChangeCorrespondencesTabSlot(int index);
	void ProcessCorrespondencesSlot();
	void SetCorrespondenceDescriptorRadiusSlot(double descriptorRadius);
	void SetCorrespondenceDescriptorKSearchSpinBoxSlot(int kSearch);
	void SetCorrespondenceNormalRadiusSlot(double normalRadius);
	void SetCorrespondencesKSlot(int correspondencesK);
	void SetRejectorInlierThresholdSlot(double rejectorInlierThreshold);
	//****************************************************************
	//										Regestration
	//****************************************************************
	void ProcessRegestrationSlot();
	void SetICPCorrespondenceDistanceSlot(double correspondenceDistance);
	void SetICPOutlierThresholdSlot(double outlierThreshold);
	void SetICPTransformationEpsilonSlot(double transformationEpsilon);
	void SetICPMaxIterationsSlot(int maxIterations);
	//****************************************************************
	//										Reconstruct
	//****************************************************************
	void ChangeReconstructTabSlot(int index);
	void ProcessReconstructSlot();
	void SetSearchRadiusSlot(double searchRadius);
	void SetMuSlot(double mu);
	void SetMaxNearestNeighborsSlot(int maxNearestNeighbors);
	void SetMaxSurfaceAngleSlot(int maxSurfaceAngle);
	void SetMinAngleSlot(int minAngle);
	void SetMaxAngleSlot(int maxAngle);
	void SetGridResolutionXYZSlot();
	void SetIsoLevelSlot(double isoLevel);
	void SetNormalSearchRadiusSlot(double normalSearchRadius);

private:
	void InitialMemberVariable();
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

	Viewer* _viewer;
	UIObserver* _uiObserver;
	FileFactory* _fileFactory;
	GrabberFactory* _grabberFactory;
	IGrabber* _grabber;
	SubjectFactory* _subjectFactory;
	int _keepFrameNumber;
	std::string _keepCloudName;
	pcl::PointCloud<PointT>::Ptr _tmpPointCloud;
	PointCloudElements* _elements;
	Arduino* _arduino;
	Ui::MainWindowForm* _ui;

	KeypointFactory* _keypointFactory;
	KeypointProcessing* _keypointProcessing;
	FilterFactory* _filterFactory;
	FilterProcessing* _filterProcessing;
	CorrespondencesFactory* _correspondencesFactory;
	CorrespondencesProcessing* _correspondencesProcessing;
	RegestrationFactory* _regestrationFactory;
	RegestrationProcessing* _regestrationProcessing;
	ReconstructFactory* _reconstructFactory;
	ReconstructProcessing* _reconstructProcessing;

	const int FRAME_PITCH = 1;	//	(sec)
	clock_t _preFrameTime;
};

#endif