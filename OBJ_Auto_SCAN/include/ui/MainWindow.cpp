#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowForm)
{
	_nameNumber = 0;
	qRegisterMetaType<pcl::PointCloud<PointT>::Ptr>("pcl::PointCloud<PointT>::Ptr");
	_ui->setupUi(this);
	InitialMemberVariable();
	InitialPointCloudViewer();
	InitialPointCloudTable();
	InitialTabWidget();
	RegisterObserver();
	InitialConnectSlots();
}

void MainWindow::InitialMemberVariable()
{
	_viewer = new Viewer();
	_uiObserver = new UIObserver(this);
	_fileFactory = new FileFactory();
	_arduino = new Arduino(COM_PORT);
	_elements = new PointCloudElements();
	_grabberFactory = new GrabberFactory();
	_subjectFactory = new SubjectFactory();
	_keypointFactory = new KeypointFactory();
	_filterFactory = new FilterFactory();
	_correspondencesFactory = new CorrespondencesFactory();
	_regestrationFactory = new RegestrationFactory();
	_reconstructFactory = new ReconstructFactory();
	_filterProcessing = _filterFactory->GetVoixelGridFilter();
	_keypointProcessing = _keypointFactory->GetSIFT();
	_correspondencesProcessing = _correspondencesFactory->GetFPFH();
	_regestrationProcessing = _regestrationFactory->GetICP();
	_reconstructProcessing = _reconstructFactory->GetGreedyProjection();
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
	connect(_ui->_boundingBoxMinXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetBoundingBoxSlot()));
	//		Correspondences
	connect(_ui->_correspondencesTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeCorrespondencesTabSlot(int)));
	connect(_ui->_correspondencesProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessCorrespondencesSlot()));
	//		Correspondences : FPFH
	connect(_ui->_fpfhDescriptorRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceDescriptorRadiusSlot(double)));
	connect(_ui->_fpfhNormalRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceNormalRadiusSlot(double)));
	connect(_ui->_fpfhCorrespondencesKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondencesKSlot(int)));
	connect(_ui->_fpfhRejectorInlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRejectorInlierThresholdSlot(double)));
	//		Correspondences : SHOT
	connect(_ui->_shotDescriptorRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceDescriptorRadiusSlot(double)));
	connect(_ui->_shotNormalRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceNormalRadiusSlot(double)));
	connect(_ui->_shotCorrespondencesKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondencesKSlot(int)));
	connect(_ui->_shotRejectorInlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRejectorInlierThresholdSlot(double)));
	//		Correspondences : PFH
	connect(_ui->_pfhDescriptorKSearchSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondenceDescriptorKSearchSpinBoxSlot(int)));
	connect(_ui->_pfhNormalRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceNormalRadiusSlot(double)));
	connect(_ui->_pfhCorrespondencesKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondencesKSlot(int)));
	connect(_ui->_pfhRejectorInlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRejectorInlierThresholdSlot(double)));
	//		Correspondences : PFHRGB
	connect(_ui->_pfhrgbDescriptorKSearchSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondenceDescriptorKSearchSpinBoxSlot(int)));
	connect(_ui->_pfhrgbNormalRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetCorrespondenceNormalRadiusSlot(double)));
	connect(_ui->_pfhrgbCorrespondencesKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetCorrespondencesKSlot(int)));
	connect(_ui->_pfhrgbRejectorInlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRejectorInlierThresholdSlot(double)));
	//		Regestration : ICP
	connect(_ui->_regestrationProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessRegestrationSlot()));
	connect(_ui->_icpCorrespondenceDistanceSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetICPCorrespondenceDistanceSlot(double)));
	connect(_ui->_icpOutlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetICPOutlierThresholdSlot(double)));
	connect(_ui->_icpTransformationEpsilonSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetICPTransformationEpsilonSlot(double)));
	connect(_ui->_icpMaxIterationsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetICPMaxIterationsSlot(int)));
	//		Reconstruct : Greedy Projection
	connect(_ui->_reconstructProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessReconstructSlot()));
	connect(_ui->_greedyProjectionSearchRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSearchRadiusSlot(double)));
	connect(_ui->_greedyProjectionMuSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetMuSlot(double)));
	connect(_ui->_greedyProjectionMaxNearestNeighborsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMaxNearestNeighborsSlot(int)));
	connect(_ui->_greedyProjectionMaxSurfaceAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMaxSurfaceAngleSlot(int)));
	connect(_ui->_greedyProjectionMinAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMinAngleSlot(int)));
	connect(_ui->_greedyProjectionMaxAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMaxAngleSlot(int)));
	//		Reconstruct : Marching Cubes
	connect(_ui->_marchingCubesGridResolutionXSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMarchingCubesGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesGridResolutionYSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMarchingCubesGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesGridResolutionZSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetMarchingCubesGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesIsoLevelSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetMarchingCubesIsoLevelSlot(double)));
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
	_ui->_regestrationTabWidget->setCurrentIndex(0);
	_ui->_reconstructTabWidget->setCurrentIndex(0);
}

void MainWindow::UpdatePointCloudViewer()
{
	_viewer->Clear();
	for (int counter = 0; counter < _elements->GetNumberOfElements(); counter++)
	{
		if (_elements->GetIsSelectedById(counter))
			_elements->ShowPointCloudElementById(*_viewer, counter);
	}
	_ui->_qvtkWidget->update();
}

void MainWindow::UpdatePointCloudTable()
{
	disconnect(_ui->_pointCloudTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(TableItemChangeSlot(QTableWidgetItem *)));
	_ui->_pointCloudTable->setRowCount(_elements->GetNumberOfElements());
	for (int counter = 0; counter < _elements->GetNumberOfElements(); counter++)
	{
		//		Name Column
		QString name = QString::fromStdString(_elements->GetNameById(counter));
		//		Show Column
		QTableWidgetItem *showPointCloudItem = new QTableWidgetItem();
		if (_elements->GetIsSelectedById(counter))
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
	_viewer->ShowPointCloud(_tmpPointCloud = pointCloud);
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

void MainWindow::TableItemChangeSlot(QTableWidgetItem* item)
{
	_elements->SetIsSelectedById(item->row(), item->checkState() == Qt::Checked);
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
	//_pointClouds->AddPointCloud(file->GetPointCloud(), dir);
	MyPointCloud* cloud = new MyPointCloud(file->GetPointCloud(), dir);
	_elements->AddPointCloudElement(cloud);
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SaveFileSlot()
{
	if (_elements->GetElementsByIsSelected().size() == 1)
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
	std::vector<PointCloudElement*> elements = _elements->GetElementsByIsSelected();
	MyFile* file = _fileFactory->GetFileByFilter(dir, filter);
	file->SaveFile(elements[0]->GetPointCloud());
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
	if (_elements->IsNameExist(cloudName) || cloudName == "")
	{
		QMessageBox::about(this, tr("Keep PointCloud"), tr("Name is exist/empty!"));
		return;
	}
	MyPointCloud* cloud = new MyPointCloud(_tmpPointCloud, cloudName);
	_elements->AddPointCloudElement(cloud);
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
	std::string cloudName = _keepCloudName + std::string("_") + TypeConversion::Int2String(_nameNumber);
	MyPointCloud* cloud = new MyPointCloud(_tmpPointCloud, cloudName);
	_elements->AddPointCloudElement(cloud);
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
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		_filterProcessing->Processing(clouds[counter]->GetPointCloud());
		std::string name = clouds[counter]->GetName() + std::string("_Filter");
		MyPointCloud* cloud = new MyPointCloud(_filterProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
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
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		_keypointProcessing->Processing(clouds[counter]->GetPointCloud());
		std::string name = clouds[counter]->GetName() + std::string("_Keypoint");
		MyKeyPoint* cloud = new MyKeyPoint(_keypointProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
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
void MainWindow::ChangeCorrespondencesTabSlot(int index)
{
	if (index == 0)
	{
		_correspondencesProcessing = _correspondencesFactory->GetFPFH();
	}
	else if (index == 1)
	{
		_correspondencesProcessing = _correspondencesFactory->GetSHOTRGB();
	}
	else if (index == 2)
	{
		_correspondencesProcessing = _correspondencesFactory->GetPFH();
	}
	else if (index == 3)
	{
		_correspondencesProcessing = _correspondencesFactory->GetPFHRGB();
	}
}

void MainWindow::ProcessCorrespondencesSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	pcl::PointCloud<PointT>::Ptr sourceCloud = clouds[0]->GetPointCloud();
	pcl::PointCloud<PointT>::Ptr targetCloud = clouds[1]->GetPointCloud();
	if (clouds.size() != 2)
	{
		QMessageBox::about(this, tr("Process Correspondences"), tr("Selecct Two Point Cloud!"));
		return;
	}
	else
	{
		_keypointProcessing->Processing(sourceCloud);
		pcl::PointCloud<KeypointT>::Ptr sourceKeypoint;
		sourceKeypoint.reset(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		_keypointProcessing->Processing(targetCloud);
		pcl::PointCloud<KeypointT>::Ptr targetKeypoint;
		targetKeypoint.reset(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		_correspondencesProcessing->Processing(sourceCloud, sourceKeypoint, targetCloud, targetKeypoint);
		std::string name = clouds[0]->GetName() + "_" + std::string("_Transform");
		MyPointCloud* cloud = new MyPointCloud(_correspondencesProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
		//std::string correspondencesName = clouds[0]->GetName() + "_" + clouds[1]->GetName() + "_" + TypeConversion::Int2String(_nameNumber) + std::string("_Correspondences");
		//_viewer->Show(sourceCloud, targetCloud, _correspondencesProcessing->GetCorrespondencesResult(), correspondencesName);
		UpdatePointCloudTable();
	}
}

void MainWindow::SetCorrespondenceDescriptorRadiusSlot(double descriptorRadius)
{
	_correspondencesProcessing->SetDescriptorRadius(descriptorRadius);
}

void MainWindow::SetCorrespondenceNormalRadiusSlot(double normalRadius)
{
	_correspondencesProcessing->SetNormalRadius(normalRadius);
}

void MainWindow::SetCorrespondencesKSlot(int correspondencesK)
{
	_correspondencesProcessing->SetCorrespondencesK(correspondencesK);
}

void MainWindow::SetRejectorInlierThresholdSlot(double rejectorInlierThreshold)
{
	_correspondencesProcessing->SetRejectorInlierThreshold(rejectorInlierThreshold);
}

void MainWindow::SetCorrespondenceDescriptorKSearchSpinBoxSlot(int kSearch)
{
	_correspondencesProcessing->SetDescriptorKSearch(kSearch);
}

//****************************************************************
//								Slots : Regestration
//****************************************************************
void MainWindow::ProcessRegestrationSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	pcl::PointCloud<PointT>::Ptr sourceCloud = clouds[0]->GetPointCloud();
	pcl::PointCloud<PointT>::Ptr targetCloud = clouds[1]->GetPointCloud();
	if (clouds.size() != 2)
	{
		QMessageBox::about(this, tr("Process Regestration"), tr("Selecct Two Point Cloud!"));
		return;
	}
	else
	{
		_regestrationProcessing->Processing(sourceCloud, targetCloud);
		std::string name = clouds[0]->GetName() + "_" + std::string("_Regestration");
		MyPointCloud* cloud = new MyPointCloud(_regestrationProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
		UpdatePointCloudTable();
	}
}

void MainWindow::SetICPCorrespondenceDistanceSlot(double correspondenceDistance)
{
	_regestrationProcessing->SetCorrespondenceDistance(correspondenceDistance);
}

void MainWindow::SetICPOutlierThresholdSlot(double outlierThreshold)
{
	_regestrationProcessing->SetRansacOutlierRejectionThreshold(outlierThreshold);
}

void MainWindow::SetICPTransformationEpsilonSlot(double transformationEpsilon)
{
	_regestrationProcessing->SetTransformationEpsilon(transformationEpsilon);
}

void MainWindow::SetICPMaxIterationsSlot(int maxIterations)
{
	_regestrationProcessing->SetMaximumIterations(maxIterations);
}

//****************************************************************
//								Slots : Reconstruct
//****************************************************************
void MainWindow::ProcessReconstructSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	pcl::PointCloud<PointT>::Ptr sourceCloud = clouds[0]->GetPointCloud();
	pcl::PointCloud<PointT>::Ptr targetCloud = clouds[1]->GetPointCloud();
	if (clouds.size() != 2)
	{
		QMessageBox::about(this, tr("Process Regestration"), tr("Selecct Two Point Cloud!"));
		return;
	}
	else
	{
		_reconstructProcessing->Processing(sourceCloud, targetCloud);
		std::string name = clouds[0]->GetName() + "_" + std::string("_Reconstruct");
		MySurface* surface = new MySurface(_reconstructProcessing->GetSurface(), name);
		_elements->AddPointCloudElement(surface);
		UpdatePointCloudTable();
	}
}

void MainWindow::SetSearchRadiusSlot(double searchRadius)
{
	_reconstructProcessing->SetSearchRadius(searchRadius);
}

void MainWindow::SetMuSlot(double mu)
{
	_reconstructProcessing->SetMu(mu);
}

void MainWindow::SetMaxNearestNeighborsSlot(int maxNearestNeighbors)
{
	_reconstructProcessing->SetMaxNearestNeighbors(maxNearestNeighbors);
}

void MainWindow::SetMaxSurfaceAngleSlot(int maxSurfaceAngle)
{
	_reconstructProcessing->SetMaxSurfaceAngle(maxSurfaceAngle);
}

void MainWindow::SetMinAngleSlot(int minAngle)
{
	_reconstructProcessing->SetMinAngle(minAngle);
}

void MainWindow::SetMaxAngleSlot(int maxAngle)
{
	_reconstructProcessing->SetMaxAngle(maxAngle);
}

void MainWindow::SetMarchingCubesGridResolutionXYZSlot()
{
	float x = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionXSpinBox->text());
	float y = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionYSpinBox->text());
	float z = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionZSpinBox->text());
	_reconstructProcessing->SetGridResolution(x, y, z);
}

void MainWindow::SetMarchingCubesIsoLevelSlot(double isoLevel)
{
	_reconstructProcessing->SetIsoLevel(isoLevel);
}