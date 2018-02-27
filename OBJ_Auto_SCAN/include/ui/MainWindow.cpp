#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowForm), _grabberFactory(new GrabberFactory()), _subjectFactory(new SubjectFactory())
{
	qRegisterMetaType<boost::shared_ptr<pcl::PointCloud<PointT>>>("boost::shared_ptr<pcl::PointCloud<PointT>>");
	_ui->setupUi(this);
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	_fileFactory = new FileFactory();
	_arduino = new Arduino(COM_PORT);
	_pointClouds = new MyPointClouds();
	InitialPointCloudViewer();
	InitialPointCloudTable();
	RegisterObserver();
	InitialConnectSlots();
}

void MainWindow::InitialConnectSlots()
{
	//		File
	connect(_ui->_openFileAction, SIGNAL(triggered()), this, SLOT(OpenFileSlot()));
	connect(_ui->_saveFileAction, SIGNAL(triggered()), this, SLOT(SaveFileSlot()));
	//		Camera
	connect(_ui->_startFlexxAction, SIGNAL(triggered()), this, SLOT(StartFlexxCameraSlot()));
	connect(_ui->_stopFlexxAction, SIGNAL(triggered()), this, SLOT(StopCameraSlot()));
	connect(_ui->_startRSAction, SIGNAL(triggered()), this, SLOT(StartRSCameraSlot()));
	connect(_ui->_stopRSAction, SIGNAL(triggered()), this, SLOT(StopCameraSlot()));
	connect(_ui->_setConfidenceAction, SIGNAL(triggered()), this, SLOT(SetCameraDepthConfidenceSlot()));
	connect(this->_uiObserver, SIGNAL(UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>>)));
	//		Arduino
	connect(_ui->_getNumberOfBytesAction, SIGNAL(triggered()), this, SLOT(GetNumberOfBytesSlot()));
	connect(_ui->_getCharAction, SIGNAL(triggered()), this, SLOT(GetCharSlot()));
	connect(_ui->_getArrayAction, SIGNAL(triggered()), this, SLOT(GetArraySlot()));
	connect(_ui->_controlMotorAction, SIGNAL(triggered()), this, SLOT(ControlMotorSlot()));
	//		PointClouds
	connect(_ui->_keepOneFrameAction, SIGNAL(triggered()), this, SLOT(KeepOneFrameSlot()));
	connect(_ui->_keepContinueFrameAction, SIGNAL(triggered()), this, SLOT(KeepContinueFrameSlot()));
	connect(_ui->_IterativeClosestPointAction, SIGNAL(triggered()), this, SLOT(IterativeClosestPointSlot()));
	connect(_ui->_pointCloudTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(TableItemChangeSlot(QTableWidgetItem *)));
}

//****************************************************************
//								UI
//						Initial, Update etc
//****************************************************************

void MainWindow::InitialPointCloudViewer()
{
	_ui->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_ui->_qvtkWidget->GetInteractor(), _ui->_qvtkWidget->GetRenderWindow());
	_ui->_qvtkWidget->update();
}

void MainWindow::InitialPointCloudTable()
{
	_ui->_pointCloudTable->setRowCount(0);
	_ui->_pointCloudTable->setColumnCount(2);
	_ui->_pointCloudTable->setColumnWidth(0, 400);
	QStringList tableTitle;
	tableTitle << QString("Name") << QString("Show");
	for (int counter = 0; counter < _ui->_pointCloudTable->horizontalHeader()->count(); ++counter)
	{
		_ui->_pointCloudTable->horizontalHeader()->setSectionResizeMode(counter, QHeaderView::Stretch);
	}
	_ui->_pointCloudTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	_ui->_pointCloudTable->setHorizontalHeaderLabels(tableTitle);
}

void MainWindow::UpdatePointCloudViewer()
{
	_viewer->Clear();
	for (int counter = 0; counter < _pointClouds->GetNumberOfPointCloud(); counter++)
	{
		if (_pointClouds->GetIsSelectedById(counter))
			_viewer->Show(_pointClouds->GetPointCloudById(counter), _pointClouds->GetNameById(counter));
	}
	_ui->_qvtkWidget->update();
}

void MainWindow::UpdatePointCloudTable()
{
	disconnect(_ui->_pointCloudTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(TableItemChangeSlot(QTableWidgetItem *)));
	_ui->_pointCloudTable->setRowCount(_pointClouds->GetNumberOfPointCloud());
	for (int counter = 0; counter < _pointClouds->GetNumberOfPointCloud(); counter++)
	{
		//		Name Column
		QString name = QString::fromStdString(_pointClouds->GetNameById(counter));
		//		Show Column
		QTableWidgetItem *showPointCloudItem = new QTableWidgetItem();
		if (_pointClouds->GetIsSelectedById(counter))
			showPointCloudItem->setCheckState(Qt::Checked);
		else
			showPointCloudItem->setCheckState(Qt::Unchecked);
		//		Add into Table
		_ui->_pointCloudTable->setItem(counter, 0, new QTableWidgetItem(name));
		_ui->_pointCloudTable->setItem(counter, 1, showPointCloudItem);
	}
	connect(_ui->_pointCloudTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(TableItemChangeSlot(QTableWidgetItem *)));
}

void MainWindow::RegisterObserver()
{
	ISubject* rsSubject = _subjectFactory->GetRSSubject();
	rsSubject->RegisterObserver(_uiObserver);
	ISubject* flexxSubject = _subjectFactory->GetFlexxSubject();
	flexxSubject->RegisterObserver(_uiObserver);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	disconnect(this->_uiObserver, SIGNAL(UpdateViewer(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>>)));
	delete _grabberFactory;
}

std::string MainWindow::InputDialog(bool* ok, const char* title, const char* label, const char* text)
{
	QString input = QInputDialog::getText(this, tr(title), tr(label), QLineEdit::Normal, tr(text), ok);
	if ((*ok) && !input.isEmpty()) {
		return TypeConversion::QString2String(input);
	}
	return std::string("");
}

//****************************************************************
//								Slots : UI
//****************************************************************
void MainWindow::UpdateViewerSlot(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_tmpPointCloud = pointCloud;
	std::unique_lock<std::mutex> lock(_grabber->GetMutex());
	_viewer->Show(_tmpPointCloud = pointCloud);
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

void MainWindow::TableItemChangeSlot(QTableWidgetItem* item)
{
	_pointClouds->SetIsSelectedById(item->row(), item->checkState() == Qt::Checked);
	UpdatePointCloudViewer();
}

//****************************************************************
//								Slots : File
//****************************************************************
void MainWindow::OpenFileSlot()
{
	QFileDialog openFileDialog(this);
	openFileDialog.setWindowTitle(tr("Open File"));
	openFileDialog.setDirectory(".");
	openFileDialog.setNameFilter(tr("OBJ(*.obj);;PLY(*.ply);;PCD(*.pcd)"));
	if (openFileDialog.exec() == QDialog::Accepted)
	{
		QString dir = openFileDialog.selectedFiles()[0];
		QString filter = openFileDialog.selectedNameFilter();
		OpenFile(TypeConversion::QString2String(dir), TypeConversion::QString2String(filter));
	}
}

void MainWindow::OpenFile(std::string dir, std::string filter)
{
	ThreeDFile* file = _fileFactory->GetFileByFilter(dir, filter);
	file->LoadFile();
	_pointClouds->AddPointCloud(file->GetPointCloud(), dir);
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SaveFileSlot()
{
	if (_pointClouds->GetPointCloudsByIsSelected().size() == 1)
	{
		QString filter;
		QString dir = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("OBJ(*.obj);; PLY(*.ply);; PCD(*.pcd)"), &filter);
		if (dir.isEmpty()) return;
		else
		{
			SaveFile(TypeConversion::QString2String(dir), TypeConversion::QString2String(filter));
		}
	}
	else
	{
		QMessageBox::about(this, tr("Save File"), tr("Selected Point Cloud More Than One"));
	}
}

void MainWindow::SaveFile(std::string dir, std::string filter)
{
	std::vector<MyPointCloud*> pointClouds = _pointClouds->GetPointCloudsByIsSelected();
	ThreeDFile* file = _fileFactory->GetFileByFilter(dir, filter);
	file->SaveFile(pointClouds[0]->GetCloud());
}

//****************************************************************
//								Slots : Camera
//****************************************************************
void MainWindow::StartFlexxCameraSlot()
{
	ISubject* subject = _subjectFactory->GetFlexxSubject();
	_grabber = _grabberFactory->GetFlexxGrabber(subject);
	_grabber->StartCamera();
}

void MainWindow::StartRSCameraSlot()
{
	ISubject* subject = _subjectFactory->GetRSSubject();
	IGrabber* grabber = _grabberFactory->GetRSGrabber(subject);
	grabber->StartCamera();
}

void MainWindow::StopCameraSlot()
{
	if (_grabber == NULL)	return;
	_grabber->StopCamera();
	_viewer->Clear();
	UpdatePointCloudViewer();
}

void MainWindow::SetCameraDepthConfidenceSlot()
{
	bool ok;
	std::string str = InputDialog(&ok, "Set Camera Depth Confidence", "Depth Confidence");
	if (!ok)	return;
	if (_grabber == NULL)return;
	_grabber->SetDepthConfidence(TypeConversion::String2Int(str));
}

//****************************************************************
//								Slots : Arduino
//****************************************************************
void MainWindow::GetNumberOfBytesSlot()
{
	bool ok;
	std::string str = InputDialog(&ok, "Communicate Arduino", "Data");
	if (!ok)	return;
	int len = str.length();
	_arduino->SendData(&str[0], len);
	Sleep(ARDUINO_SLEEP_TIME);
	int numOfData = _arduino->ReceiveDataNumberOfBytes();
	char* recData = _arduino->ReceiveData();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(TypeConversion::Int2String(numOfData).c_str()));
}

void MainWindow::GetCharSlot()
{
	bool ok;
	std::string str = InputDialog(&ok, "Communicate Arduino", "Data");
	if (!ok)	return;
	_arduino->SendData(str[0]);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recData = _arduino->ReceiveData();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(recData));
}

void MainWindow::GetArraySlot()
{
	bool ok;
	std::string str = InputDialog(&ok, "Communicate Arduino", "Data");
	if (!ok)	return;
	int len = str.length();
	_arduino->SendData(&str[0], len);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recData = _arduino->ReceiveData(len);
	QMessageBox::about(this, tr("Communicate Arduino"), tr(recData));
}

void MainWindow::ControlMotorSlot()
{
	bool motorOk;
	std::string motorId = InputDialog(&motorOk, "Control Motor", "Motor Id");
	if (!motorOk)	return;
	bool degreeOk;
	std::string degree = InputDialog(&degreeOk, "Control Motor", "Degree");
	if (!degreeOk)	return;
	int motorIdLen = motorId.length();
	int degreeLen = degree.length();
	_arduino->SendData(&motorId[0], motorIdLen);
	_arduino->SendData(&degree[0], degreeLen);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recMotorId = _arduino->ReceiveData(motorIdLen);
	QMessageBox::about(this, tr("Control Motor"), tr(recMotorId));
	char* recDegree = _arduino->ReceiveData(degreeLen);
	QMessageBox::about(this, tr("Control Motor"), tr(recDegree));
}

//****************************************************************
//								Slots : Point Cloud
//****************************************************************
void MainWindow::KeepOneFrameSlot()
{
	boost::shared_ptr<pcl::PointCloud<PointT>> copyCloud;
	copyCloud.reset(new pcl::PointCloud<PointT>(*_tmpPointCloud));
	bool ok;
	std::string cloudName = InputDialog(&ok, "Keep PointCloud", "Cloud Name");
	if (!ok)	return;
	if (_pointClouds->IsNameExist(cloudName) || cloudName == "")
	{
		QMessageBox::about(this, tr("Keep PointCloud"), tr("Name is exist/empty!"));
		return;
	}
	_pointClouds->AddPointCloud(_tmpPointCloud, cloudName);
	UpdatePointCloudTable();
}

void MainWindow::KeepContinueFrameSlot()
{
	if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Continue Frame")
	{
		bool ok;
		_keepCloudName = InputDialog(&ok, "Keep PointCloud", "Cloud Name");
		if (!ok)	return;
		_keepFrameNumber = 0;
		connect(this->_uiObserver, SIGNAL(KeepFrame(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(KeepFrameSlot(boost::shared_ptr<pcl::PointCloud<PointT>>)));
		_ui->_keepContinueFrameAction->setText(QString("Stop"));
	}
	else if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Stop")
	{
		disconnect(this->_uiObserver, SIGNAL(KeepFrame(boost::shared_ptr<pcl::PointCloud<PointT>>)), this, SLOT(KeepFrameSlot(boost::shared_ptr<pcl::PointCloud<PointT>>)));
		_ui->_keepContinueFrameAction->setText(QString("Continue Frame"));
	}
}

void MainWindow::KeepFrameSlot(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_pointClouds->AddPointCloud(pointCloud, _keepCloudName + std::string("_") + TypeConversion::Int2String(_keepFrameNumber));
	UpdatePointCloudTable();
	_keepFrameNumber++;
}

void MainWindow::IterativeClosestPointSlot()
{
	bool ok;
	std::string cloudName = InputDialog(&ok, "Iterative Closest Point", "Cloud Name");
	if (!ok)	return;
	boost::shared_ptr<pcl::PointCloud<PointT>> icpPointCloud;
	std::vector<MyPointCloud*> pointClouds = _pointClouds->GetPointCloudsByIsSelected();
	if (pointClouds.size() == 0)return;
	else if (pointClouds.size() == 1)
		icpPointCloud.reset(new pcl::PointCloud<PointT>(*pointClouds[0]->GetCloud()));
	else
	{
		MyIterativeClosestPoint icpFirstTime(pointClouds[0]->GetCloud(), pointClouds[1]->GetCloud());
		icpFirstTime.SetMaxCorrespondenceDistance(0.1);
		icpFirstTime.SetTransformationEpsilon(1e-10);
		icpFirstTime.SetEuclideanFitnessEpsilon(0.01);
		icpFirstTime.SetMaximumIterations(100);
		icpFirstTime.ProcessICP();
		icpPointCloud = icpFirstTime.GetOutputPointCloud();
		for (int counter = 2; counter < pointClouds.size(); counter++)
		{
			MyIterativeClosestPoint icpElseTimes(icpPointCloud, pointClouds[counter]->GetCloud());
			icpElseTimes.SetMaxCorrespondenceDistance(0.1);
			icpElseTimes.SetTransformationEpsilon(1e-10);
			icpElseTimes.SetEuclideanFitnessEpsilon(0.01);
			icpElseTimes.SetMaximumIterations(100);
			icpElseTimes.ProcessICP();
			icpPointCloud = icpElseTimes.GetOutputPointCloud();
		}
	}
	_pointClouds->AddPointCloud(icpPointCloud, cloudName);
	UpdatePointCloudTable();
}