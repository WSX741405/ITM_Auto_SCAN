#include "ui/MainWindow.h"
#include "flexx/Flexx.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	_ui.setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	RegisterObserver();
	InitialViewer();
	//		ui event
	connect(_ui._flexxAction, SIGNAL(triggered()), this, SLOT(OpenFlexxCameraSlot));
	connect(_ui.pushButton, SIGNAL(clicked()), this, SLOT(OpenFlexxCameraSlot));
}

void MainWindow::InitialViewer()
{
	_widget = new QVTKWidget(this->centralWidget());
	_widget->setGeometry(QRect(30, 30, 370, 370));

	_widget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_widget->GetInteractor(), _widget->GetRenderWindow());
	_widget->update();
}

void MainWindow::RegisterObserver()
{
	_flexxSubject = new FlexxSubject();
	_flexxSubject->RegisterObserver(_uiObserver);
	_flexx = new Flexx(_flexxSubject);
}

void MainWindow::UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_viewer->Show(pointCloud);
}

//		UI event
void MainWindow::OpenFlexxCameraSlot()
{
	_flexx->OpenCamera();
}