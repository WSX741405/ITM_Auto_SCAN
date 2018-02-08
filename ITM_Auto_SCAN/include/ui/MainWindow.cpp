#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowClass), _grabberFactory(new GrabberFactory()), _subjectFactory(new SubjectFactory())
{
	qRegisterMetaType<boost::shared_ptr<pcl::PointCloud<PointT>>>("boost::shared_ptr<pcl::PointCloud<PointT>>");
	_ui->setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	_arduino = new Arduino("com4");
	InitialViewer();
	RegisterObserver();
	ConnectSlots();
}

void MainWindow::ConnectSlots()
{
	connect(_ui->_startFlexxAction, SIGNAL(triggered()), this, SLOT(StartFlexxCameraSlot()));
	connect(_ui->_stopFlexxAction, SIGNAL(triggered()), this, SLOT(StopFlexxCameraSlot()));
	connect(_ui->_startRSAction, SIGNAL(triggered()), this, SLOT(StartRSCameraSlot()));
	connect(_ui->_stopRSAction, SIGNAL(triggered()), this, SLOT(StopRSCameraSlot()));
	connect(this->_uiObserver, SIGNAL(UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>>)));
	connect(_ui->_communicateArduinoAction, SIGNAL(triggered()), this, SLOT(CommunicateArduinoSlot()));
}

void MainWindow::InitialViewer()
{
	_ui->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_ui->_qvtkWidget->GetInteractor(), _ui->_qvtkWidget->GetRenderWindow());
	_ui->_qvtkWidget->update();
}

void MainWindow::RegisterObserver()
{
	ISubject* rsSubject = _subjectFactory->GetRSSubject();
	rsSubject->RegisterObserver(_uiObserver);
	ISubject* flexxSubject = _subjectFactory->GetFlexxSubject();
	flexxSubject->RegisterObserver(_uiObserver);
}


void MainWindow::UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_viewer->Show(pointCloud);
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	delete _grabberFactory;
}

//****************************************************************
//								Slots : Camera
//****************************************************************
void MainWindow::StartFlexxCameraSlot()
{
	ISubject* subject = _subjectFactory->GetFlexxSubject();
	IGrabber* grabber = _grabberFactory->GetFlexxGrabber(subject);
	grabber->StartCamera();
}

void MainWindow::StopFlexxCameraSlot()
{
	IGrabber* grabber = _grabberFactory->GetFlexxGrabber();
	grabber->StopCamera();
}

void MainWindow::StartRSCameraSlot()
{
	ISubject* subject = _subjectFactory->GetRSSubject();
	IGrabber* grabber = _grabberFactory->GetRSGrabber(subject);
	grabber->StartCamera();
}

void MainWindow::StopRSCameraSlot()
{
	IGrabber* grabber = _grabberFactory->GetRSGrabber();
	grabber->StopCamera();
}

//****************************************************************
//								Slots : Arduino
//****************************************************************
void MainWindow::CommunicateArduinoSlot()
{
	static unsigned int numOfRecData = 0;
	std::string str = InputDialog("Communicate Arduino", "Input Data");
	int len = StringMethod::GetStringLength(&str[0u]);
	_arduino->SendData(&str[0u], len);
	while (_arduino->ReceiveDataNumberOfBytes() != numOfRecData)
		numOfRecData += _arduino->ReceiveDataNumberOfBytes();
	char* data = _arduino->ReceiveData(len);
	QMessageBox::about(this, tr("Communicate Arduino"), tr(data));
}

std::string MainWindow::InputDialog(const char* title, const char* label, const char* text)
{
	bool ok;
	QString input = QInputDialog::getText(this, tr(title), tr(label), QLineEdit::Normal, tr(text), &ok);
	if (ok && !input.isEmpty()) {
		return StringMethod::QString2String(input);
	}
	return std::string("");
}