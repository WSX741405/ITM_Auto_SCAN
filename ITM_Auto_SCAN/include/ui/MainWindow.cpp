#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), _ui(new Ui::MainWindowClass)
{
	_ui->setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	InitialViewer();
	//		ui event
	connect(_ui->_startFlexxAction, SIGNAL(triggered()), this, SLOT(StartFlexxCameraSlot()));
	connect(_ui->_stopFlexxAction, SIGNAL(triggered()), this, SLOT(StopFlexxCameraSlot()));
	connect(_ui->_startRSAction, SIGNAL(triggered()), this, SLOT(StartRSCameraSlot()));
	connect(_ui->_stopRSAction, SIGNAL(triggered()), this, SLOT(StopRSCameraSlot()));
}

void MainWindow::InitialViewer()
{
	_ui->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_ui->_qvtkWidget->GetInteractor(), _ui->_qvtkWidget->GetRenderWindow());
	_ui->_qvtkWidget->update();
}

/*
void MainWindow::RegisterObserver()
{
	_subject = new _subject();
	_subject->RegisterObserver(_uiObserver);
	_flexx = new Flexx(_subject);
}
*/

void MainWindow::UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_viewer->Show(pointCloud);
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

//		UI event
void MainWindow::StartFlexxCameraSlot()
{
	_flexx->StartCamera();
}

void MainWindow::StopFlexxCameraSlot()
{
	_flexx->StopCamera();
}

void MainWindow::StartRSCameraSlot()
{
}

void MainWindow::StopRSCameraSlot()
{
}