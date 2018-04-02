#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowForm), _grabberFactory(new GrabberFactory()), _subjectFactory(new SubjectFactory()), _keypointFactory(new KeypointFactory()), _filterFactory(new FilterFactory()), _correspondencesFactory(new CorrespondencesFactory())
{
	_nameNumber = 0;
	qRegisterMetaType<pcl::PointCloud<PointT>::Ptr>("pcl::PointCloud<PointT>::Ptr");
	_filterProcessing = _filterFactory->GetVoixelGridFilter();
	_keypointProcessing = _keypointFactory->GetSIFT();
	_correspondencesProcessing = _correspondencesFactory->GetFPFH();
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	_fileFactory = new FileFactory();
	_arduino = new Arduino(COM_PORT);
	_pointClouds = new MyPointClouds();
	_ui->setupUi(this);
	InitialPointCloudViewer();
	InitialPointCloudTable();
	InitialTabWidget();
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
	connect(this->_uiObserver, SIGNAL(UpdateViewer(pcl::PointCloud<PointT>::Ptr)), this, SLOT(UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr)));
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
	//		Keypoint
	connect(_ui->_keypointProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessKeypointSlot()));
	connect(_ui->_keypointTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeKeypointTabSlot(int)));
	//		Keypoint : SIFT
	connect(_ui->_siftMinScaleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSIFTScalesSlot()));
	connect(_ui->_siftNROctavesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetSIFTScalesSlot()));
	connect(_ui->_siftNRScalesPerOctaveSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetSIFTScalesSlot()));
	connect(_ui->_siftMinContrastSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSIFTMinContrastSlot()));
	//		Keypoint : harris
	connect(_ui->_harrisRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetHarrisRadiusSlot()));
	connect(_ui->_harrisRadiusSearchSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetHarrisRadiusSearchSlot()));
	connect(_ui->_harrisMethodComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SetHarrisMethodSlot(int)));
	//		Filter
	connect(_ui->_filterTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeFilterTabSlot(int)));
	connect(_ui->_filterProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessFilterSlot()));
	//		Filter : Voxel Grid
	connect(_ui->_voxelGridXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetVoxelGridXYZSlot()));
	connect(_ui->_voxelGridYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetVoxelGridXYZSlot()));
	connect(_ui->_voxelGridZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetVoxelGridXYZSlot()));
	//		Filter : Bounding Box
	connect(_ui->_boundingBoxMinXSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxXSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinYSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxYSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinZSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxZSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	//		Correspondences : FPFH
	connect(_ui->_correspondencesProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessCorrespondencesSlot()));
	connect(_ui->_fpfhDescriptorRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFPFHDescriptorRadiusSlot(double)));
	connect(_ui->_fpfhNormalRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFPFHNormalRadiusSlot(double)));
	connect(_ui->_fpfhCorrespondencesKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetFPFHCorrespondencesKSlot(int)));
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

void MainWindow::InitialTabWidget()
{
	_ui->_processingTabWidget->setCurrentIndex(0);
	_ui->_filterTabWidget->setCurrentIndex(0);
	_ui->_keypointTabWidget->setCurrentIndex(0);
	_ui->_correspondencesTabWidget->setCurrentIndex(0);
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
	disconnect(this->_uiObserver, SIGNAL(UpdateViewer(pcl::PointCloud<PointT>::Ptr)), this, SLOT(UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr)));
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
void MainWindow::UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr pointCloud)
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
	MyFile* file = _fileFactory->GetFileByFilter(dir, filter);
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
		QMessageBox::about(this, tr("Save File"), tr("Select Only One Point Cloud"));
	}
}

void MainWindow::SaveFile(std::string dir, std::string filter)
{
	std::vector<MyPointCloud*> pointClouds = _pointClouds->GetPointCloudsByIsSelected();
	MyFile* file = _fileFactory->GetFileByFilter(dir, filter);
	file->SaveFile(pointClouds[0]->GetPointCloud());
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
	if (_grabber == NULL)	return;
	pcl::PointCloud<PointT>::Ptr copyCloud;
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
	if (_grabber == NULL)	return;
	if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Continue Frame")
	{
		bool ok;
		_keepCloudName = InputDialog(&ok, "Keep PointCloud", "Cloud Name");
		if (!ok)	return;
		connect(this->_uiObserver, SIGNAL(KeepFrame(pcl::PointCloud<PointT>::Ptr)), this, SLOT(KeepFrameSlot(pcl::PointCloud<PointT>::Ptr)));
		_ui->_keepContinueFrameAction->setText(QString("Stop"));
	}
	else if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Stop")
	{
		disconnect(this->_uiObserver, SIGNAL(KeepFrame(pcl::PointCloud<PointT>::Ptr)), this, SLOT(KeepFrameSlot(pcl::PointCloud<PointT>::Ptr)));
		_ui->_keepContinueFrameAction->setText(QString("Continue Frame"));
	}
}

void MainWindow::KeepFrameSlot(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	_pointClouds->AddPointCloud(pointCloud, _keepCloudName + std::string("_") + TypeConversion::Int2String(_nameNumber));
	UpdatePointCloudTable();
	_nameNumber++;
}

//****************************************************************
//								Slots : Filter Processing
//****************************************************************
void MainWindow::ChangeFilterTabSlot(int index)
{
	if (index == 0)
	{
		_filterProcessing = _filterFactory->GetVoixelGridFilter();
	}
	else if (index == 1)
	{
		_filterProcessing = _filterFactory->GetBoundingBoxFilter();
	}
}

void MainWindow::ProcessFilterSlot()
{
	std::vector<MyPointCloud*> clouds = _pointClouds->GetPointCloudsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		_filterProcessing->Processing(clouds[counter]->GetPointCloud());
		std::string name = clouds[counter]->GetName() + "_" + TypeConversion::Int2String(_nameNumber) + std::string("_Filter");
		_pointClouds->AddPointCloud(_filterProcessing->GetResult(), name);
		_nameNumber++;
		UpdatePointCloudTable();
	}
}

void MainWindow::SetVoxelGridXYZSlot()
{
	float x = TypeConversion::QString2Float(_ui->_voxelGridXSpinBox->text());
	float y = TypeConversion::QString2Float(_ui->_voxelGridYSpinBox->text());
	float z = TypeConversion::QString2Float(_ui->_voxelGridZSpinBox->text());
	_filterProcessing->SetLeafSize(x, y, z);
}

void MainWindow::SetBoundingBoxSlot()
{
	int minX = TypeConversion::QString2Float(_ui->_boundingBoxMinXSpinBox->text());
	int maxX = TypeConversion::QString2Float(_ui->_boundingBoxMaxXSpinBox->text());
	int minY = TypeConversion::QString2Float(_ui->_boundingBoxMinYSpinBox->text());
	int maxY = TypeConversion::QString2Float(_ui->_boundingBoxMaxYSpinBox->text());
	int minZ = TypeConversion::QString2Float(_ui->_boundingBoxMinZSpinBox->text());
	int maxZ = TypeConversion::QString2Float(_ui->_boundingBoxMaxZSpinBox->text());
	_filterProcessing->SetBoundingBox(minX, maxX, minY, maxY, minZ, maxZ);
}

//****************************************************************
//								Slots : Keypoint Processing
//****************************************************************
void MainWindow::ProcessKeypointSlot()
{
	//		default
	int r = 255;
	int g = 0;
	int b = 0;
	std::vector<MyPointCloud*> clouds = _pointClouds->GetPointCloudsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		_keypointProcessing->Processing(clouds[counter]->GetPointCloud());
		std::string name = clouds[counter]->GetName() + "_" + TypeConversion::Int2String(_nameNumber) + std::string("_keypoint");
		_pointClouds->AddPointCloud(_keypointProcessing->GetResult(), r, g, b, name);
		_nameNumber++;
		UpdatePointCloudTable();
	}
}

void MainWindow::ChangeKeypointTabSlot(int index)
{
	if (index == 0)
	{
		_keypointProcessing = _keypointFactory->GetSIFT();
	}
	else if (index == 1)
	{
		_keypointProcessing = _keypointFactory->GetHarris();
	}
}

void MainWindow::SetSIFTScalesSlot()
{
	float minScale = TypeConversion::QString2Float(_ui->_siftMinScaleSpinBox->text());
	int nrOctaves = TypeConversion::QString2Int(_ui->_siftNROctavesSpinBox->text());
	int nrScalesPerOctave = TypeConversion::QString2Int(_ui->_siftNRScalesPerOctaveSpinBox->text());
	_keypointProcessing->SetScales(minScale, nrOctaves, nrScalesPerOctave);
}

void MainWindow::SetSIFTMinContrastSlot()
{
	float siftMinContrast = TypeConversion::QString2Float(_ui->_siftMinContrastSpinBox->text());
	_keypointProcessing->SetMinContrast(siftMinContrast);
}

void MainWindow::SetHarrisMethodSlot(int index)
{
	if (index == 0)
	{
		_keypointProcessing = _keypointFactory->GetHarris();
	}
	else if (index == 1)
	{
		_keypointProcessing = _keypointFactory->GetTomasi();
	}
	else if (index == 2)
	{
		_keypointProcessing = _keypointFactory->GetNoble();
	}
	else if(index == 3)
	{
		_keypointProcessing = _keypointFactory->Lowe();
	}
	else
	{
		_keypointProcessing = _keypointFactory->Curvature();
	}
}

void MainWindow::SetHarrisRadiusSlot()
{
	float harrisRadius = TypeConversion::QString2Float(_ui->_harrisRadiusSpinBox->text());
	_keypointProcessing->SetRadius(harrisRadius);
}

void MainWindow::SetHarrisRadiusSearchSlot()
{
	float harrisRadiusSearch = TypeConversion::QString2Float(_ui->_harrisRadiusSearchSpinBox->text());
	_keypointProcessing->SetRadiusSearch(harrisRadiusSearch);
}

//****************************************************************
//								Slots : Correspondences Processing
//****************************************************************

void MainWindow::ProcessCorrespondencesSlot()
{

}

void MainWindow::SetFPFHDescriptorRadiusSlot(double descriptorRadius)
{
	_correspondencesProcessing->SetDescriptorRadius(descriptorRadius);
}

void MainWindow::SetFPFHNormalRadiusSlot(double normalRadius)
{
	_correspondencesProcessing->SetNormalRadius(normalRadius);
}

void MainWindow::SetFPFHCorrespondencesKSlot(int correspondencesK)
{
	_correspondencesProcessing->SetCorrespondencesK(correspondencesK);
}