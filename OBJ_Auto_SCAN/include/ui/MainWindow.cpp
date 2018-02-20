#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowClass), _grabberFactory(new GrabberFactory()), _subjectFactory(new SubjectFactory())
{
	qRegisterMetaType<boost::shared_ptr<pcl::PointCloud<PointT>>>("boost::shared_ptr<pcl::PointCloud<PointT>>");
	_ui->setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	_arduino = new Arduino(COM_PORT);
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
	connect(this->_uiObserver, SIGNAL(UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>>)));
	connect(_ui->_getNumberOfBytesAction, SIGNAL(triggered()), this, SLOT(GetNumberOfBytesSlot()));
	connect(_ui->_getCharAction, SIGNAL(triggered()), this, SLOT(GetCharSlot()));
	connect(_ui->_getArrayAction, SIGNAL(triggered()), this, SLOT(GetArraySlot()));
	connect(_ui->_controlMotorAction, SIGNAL(triggered()), this, SLOT(ControlMotorSlot()));
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

void MainWindow::UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
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
//								UI Component
//****************************************************************

std::string MainWindow::InputDialog(const char* title, const char* label, const char* text)
{
	bool ok;
	QString input = QInputDialog::getText(this, tr(title), tr(label), QLineEdit::Normal, tr(text), &ok);
	if (ok && !input.isEmpty()) {
		return TypeConversion::QString2String(input);
	}
	return std::string("");
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
void MainWindow::GetNumberOfBytesSlot()
{
	std::string str = InputDialog("Communicate Arduino", "Input Data");
	int len = str.length();
	_arduino->SendData(&str[0], len);
	Sleep(ARDUINO_SLEEP_TIME);
	int numOfData = _arduino->ReceiveDataNumberOfBytes();
	char* recData = _arduino->ReceiveData();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(TypeConversion::Int2String(numOfData).c_str()));
}

void MainWindow::GetCharSlot()
{
	std::string str = InputDialog("Communicate Arduino", "Input Data");
	_arduino->SendData(str[0]);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recData = _arduino->ReceiveData();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(recData));
}

void MainWindow::GetArraySlot()
{
	std::string str = InputDialog("Communicate Arduino", "Input Data");
	int len = str.length();
	_arduino->SendData(&str[0], len);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recData = _arduino->ReceiveData(len);
	QMessageBox::about(this, tr("Communicate Arduino"), tr(recData));
}

void MainWindow::ControlMotorSlot()
{
	std::string motorId = InputDialog("Control Motor", "Input Motor Id");
	std::string degree = InputDialog("Control Motor", "Input Degree");
	int motorIdLen = motorId.length();
	int degreeLen = degree.length();
	_arduino->SendData(&motorId[0], motorIdLen);
	_arduino->SendData(&degree[0], degreeLen);
	Sleep(ARDUINO_SLEEP_TIME); 
	int numOfData = _arduino->ReceiveDataNumberOfBytes();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(TypeConversion::Int2String(numOfData).c_str()));
	char* recMotorId = _arduino->ReceiveData(motorIdLen);
	QMessageBox::about(this, tr("Control Motor"), tr(recMotorId));
	char* recDegree = _arduino->ReceiveData(degreeLen);
	QMessageBox::about(this, tr("Control Motor"), tr(recDegree));
}