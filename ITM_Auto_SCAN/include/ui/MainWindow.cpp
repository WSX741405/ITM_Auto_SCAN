#include "ui/MainWindow.h"
#include "flexx/Flexx.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), _ui(new Ui::MainWindowClass)
{
	_ui->setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	RegisterObserver();
	InitialViewer();
	//		ui event
	connect(_ui->_openFlexxAction, SIGNAL(triggered()), this, SLOT(OpenFlexxCameraSlot()));
	connect(_ui->_closeFlexxAction, SIGNAL(triggered()), this, SLOT(CloseFlexxCameraSlot()));
}

void MainWindow::InitialViewer()
{
	_ui->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_ui->_qvtkWidget->GetInteractor(), _ui->_qvtkWidget->GetRenderWindow());
	_ui->_qvtkWidget->update();
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
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

//		UI event
void MainWindow::OpenFlexxCameraSlot()
{
	_flexx->OpenCamera();
}

void MainWindow::CloseFlexxCameraSlot()
{
	_flexx->CloseCamera();
}