#pragma once

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/ObserverFactory.h"
#include "grabber/GrabberFactory.h"

class UIObserver;
class ISubject;
class SubjectFactory;
class IGrabber;
class GrabberFactory;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	void UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud);

public slots:
	void	StartFlexxCameraSlot();
	void StopFlexxCameraSlot();
	void	StartRSCameraSlot();
	void StopRSCameraSlot();

private:
	void InitialViewer();
	void RegisterObserver();

	Viewer* _viewer;
	UIObserver* _uiObserver;
	GrabberFactory* _grabberFactory;
	SubjectFactory* _subjectFactory;
	//ISubject* _subject;
	Ui::MainWindowClass* _ui;
};
