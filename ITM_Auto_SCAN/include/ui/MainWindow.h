#pragma once

#include <vtkAutoInit.h>
VTK_MODULE_INIT(vtkRenderingOpenGL);
VTK_MODULE_INIT(vtkInteractionStyle);
#include <QtWidgets/QMainWindow>
#include <QVTKWidget.h>

#include "ui_MainWindow.h"
#include "ui/Viewer.h"
#include "observer/IObserver.h"
#include "flexx/Flexx.h"

class UIObserver;
class Flexx;
class ISubject;

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
	//void RegisterObserver();

	Flexx* _flexx;
	Viewer* _viewer;
	//QVTKWidget* _widget;
	UIObserver* _uiObserver;
	ISubject* _subject;
	Ui::MainWindowClass* _ui;
};
