#include "ui/MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), _ui(new Ui::MainWindowForm)
{
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
	_keepFrameNumber = 0;
	_preFrameTime = clock();
	_grabber = NULL;
	_dialog = NULL;

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
	_smoothingFactory = new SmoothingFactory();
	_filterProcessing = _filterFactory->GetVoixelGridFilter();
	_keypointProcessing = _keypointFactory->GetSIFT();
	_correspondencesProcessing = _correspondencesFactory->GetFPFH();
	_regestrationProcessing = _regestrationFactory->GetICP();
	_reconstructProcessing = _reconstructFactory->GetGreedyProjection();
	_smoothingProcessing = _smoothingFactory->GetMeshSmoothingLaplacian();

	_isTestedKinfuBoundingBox = false;
}

void MainWindow::InitialConnectSlots()
{
	connect(this, SIGNAL(ShowDialog(bool*, const char*, const char*, const char*)), this, SLOT(ShowInputDialogSlot(bool*, const char*, const char*, const char*)));
	//		File
	connect(_ui->_openFileAction, SIGNAL(triggered()), this, SLOT(OpenFileSlot()));
	connect(_ui->_saveFileAction, SIGNAL(triggered()), this, SLOT(SaveFileSlot()));
	//		Viewer
	connect(_ui->_setViewBackgroundToBlackAction, SIGNAL(triggered()), this, SLOT(SetViewBackgroundToBlackSlot()));
	connect(_ui->_setViewBackgroundToWhiteAction, SIGNAL(triggered()), this, SLOT(SetViewWhiteBackgroundToWhiteSlot()));
	//		Camera
	connect(_ui->_startFlexxAction, SIGNAL(triggered()), this, SLOT(StartFlexxCameraSlot()));
	connect(_ui->_stopFlexxAction, SIGNAL(triggered()), this, SLOT(StopCameraSlot()));
	connect(_ui->_startRSAction, SIGNAL(triggered()), this, SLOT(StartRSCameraSlot()));
	connect(_ui->_stopRSAction, SIGNAL(triggered()), this, SLOT(StopCameraSlot()));
	connect(_ui->_setConfidenceAction, SIGNAL(triggered()), this, SLOT(SetCameraDepthConfidenceSlot()));
	connect(_ui->_startXtionProAction, SIGNAL(triggered()), this, SLOT(StartXtionProCameraSlot()));
	connect(_ui->_stopXtionProAction, SIGNAL(triggered()), this, SLOT(StopCameraSlot()));
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
	connect(_ui->_removeSelectedPointCloudsAction, SIGNAL(triggered()), this, SLOT(RemoveSelectedPointCloudSlot()));
	connect(_ui->_removeAllPointCloudsAction, SIGNAL(triggered()), this, SLOT(RemoveAllPointCloudSlot()));
	connect(_ui->_selectAllPointCloudsAction, SIGNAL(triggered()), this, SLOT(SelectAllPointCloudSlot()));
	connect(_ui->_unselectAllPointCloudsAction, SIGNAL(triggered()), this, SLOT(UnselectAllPointCloudSlot()));
	connect(_ui->_combinePointCloudAction, SIGNAL(triggered()), this, SLOT(CombinePointCloudSlot()));
	connect(_ui->_getMinNegativeNumberAction, SIGNAL(triggered()), this, SLOT(GetMinNegativeNumberSlot()));
	connect(_ui->_multiplicationButton, SIGNAL(clicked()), this, SLOT(MultiplicationPointCloudSlot()));
	connect(_ui->_shiftButton, SIGNAL(clicked()), this, SLOT(ShiftPointCloudSlot()));
	connect(_ui->_removeNANAction, SIGNAL(triggered()), this, SLOT(RemoveNANSlot()));
	//		Processing
	connect(_ui->_processICP1Action, SIGNAL(triggered()), this, SLOT(ProcessICP1Slot()));
	connect(_ui->_processICP2Action, SIGNAL(triggered()), this, SLOT(ProcessICP2Slot()));
	connect(_ui->_processICP3Action, SIGNAL(triggered()), this, SLOT(ProcessICP3Slot()));
	//		Keypoint
	connect(_ui->_keypointProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessKeypointSlot()));
	connect(_ui->_keypointTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeKeypointTabSlot(int)));
	//		Keypoint : SIFT
	connect(_ui->_siftMinScaleSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetKeypointScalesSlot()));
	connect(_ui->_siftNROctavesSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetKeypointScalesSlot()));
	connect(_ui->_siftNRScalesPerOctaveSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetKeypointScalesSlot()));
	connect(_ui->_siftMinContrastSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetKeypointMinContrastSlot()));
	//		Keypoint : harris
	connect(_ui->_harrisRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetKeypointRadiusSlot()));
	connect(_ui->_harrisRadiusSearchSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetKeypointRadiusSearchSlot()));
	connect(_ui->_harrisMethodComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(SetKeypointMethodSlot(int)));
	//		Filter
	connect(_ui->_filterTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeFilterTabSlot(int)));
	connect(_ui->_filterProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessFilterSlot()));
	//		Filter : Voxel Grid
	connect(_ui->_voxelGridXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterVoxelGridXYZSlot()));
	connect(_ui->_voxelGridYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterVoxelGridXYZSlot()));
	connect(_ui->_voxelGridZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterVoxelGridXYZSlot()));
	//		Filter : Bounding Box
	connect(_ui->_boundingBoxMinXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxXSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxYSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_boundingBoxMinZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_boundingBoxMaxZSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterBoundingBoxSlot()));
	connect(_ui->_outlierMeanKSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetFilterMeanKSlot(int)));
	connect(_ui->_outlierStddevMulThreshSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetFilterStddevMulThreshSlot(double)));
	connect(_ui->_testBoundingBoxButton, SIGNAL(clicked()), this, SLOT(TestBoundingBoxSlot()));
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
	connect(_ui->_icpCorrespondenceDistanceSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRegestrationCorrespondenceDistanceSlot(double)));
	connect(_ui->_icpOutlierThresholdSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetRegestrationOutlierThresholdSlot(double)));
	//connect(_ui->_icpEuclideanFitnessEpsilonSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetEuclideanFitnessEpsilonSlot(double)));
	connect(_ui->_icpMaxIterationsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetRegestrationMaxIterationsSlot(int)));
	//		Reconstruct : Greedy Projection
	connect(_ui->_reconstructTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeReconstructTabSlot(int)));
	connect(_ui->_reconstructProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessReconstructSlot()));
	connect(_ui->_greedyProjectionSearchRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetReconstructSearchRadiusSlot(double)));
	connect(_ui->_greedyProjectionMuSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetReconstructMuSlot(double)));
	connect(_ui->_greedyProjectionMaxNearestNeighborsSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetReconstructMaxNearestNeighborsSlot(int)));
	connect(_ui->_greedyProjectionMaxSurfaceAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetReconstructMaxSurfaceAngleSlot(int)));
	connect(_ui->_greedyProjectionMinAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetReconstructMinAngleSlot(int)));
	connect(_ui->_greedyProjectionMaxAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetReconstructMaxAngleSlot(int)));
	connect(_ui->_greedyProjectNormalSearchRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetReconstructNormalSearchRadiusSlot(double)));
	connect(_ui->_poissonNormalRadiusSearchSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetReconstructNormalSearchRadiusSlot(double)));
	connect(_ui->_poissonDepthSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetReconstructDepthSlot(int)));
	/*		@@@@@@@@    Reconstruct : Marching Cubes
	connect(_ui->_marchingCubesGridResolutionXSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesGridResolutionYSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesGridResolutionZSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetGridResolutionXYZSlot()));
	connect(_ui->_marchingCubesIsoLevelSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetIsoLevelSlot(double)));
	connect(_ui->_marchingCubesNormalSearchRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetNormalSearchRadiusSlot(double)));*/
	//		Smoothing
	connect(_ui->_smoothingTabWidget, SIGNAL(currentChanged(int)), this, SLOT(ChangeSmoothingTabSlot(int)));
	connect(_ui->_smoothingProcessingButton, SIGNAL(clicked()), this, SLOT(ProcessSmoothingSlot()));
	connect(_ui->_smoothingLaplacianNumIterSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetSmoothingNumIterSlot(int)));
	connect(_ui->_smoothingLaplacianConvergenceSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSmoothingConvergenceSlot(double)));
	connect(_ui->_smoothingLaplacianRelaxationFactorSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSmoothingRelaxationFactorMaxAngleSlot(double)));
	connect(_ui->_smoothingLaplacianFeatureAngleSpinBox, SIGNAL(valueChanged(int)), this, SLOT(SetSmoothingFeatureAngleSlot(int)));
	connect(_ui->_resampleingSearchRadiusSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSmoothingSearchRadiusSlot(double)));
	connect(_ui->_concaveHullAlphaSpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetReconstructAlphaSlot(double)));
	//		Kinect Fusion
	connect(_ui->_kinfuTestBoundingBoxAction, SIGNAL(triggered()), this, SLOT(ProcessKinfuTestBoundingBoxSlot()));
	connect(_ui->_segmentedKinfuAction, SIGNAL(triggered()), this, SLOT(ProcessSegmentedKinfuCloudSlot()));
	connect(_ui->_ignoreResetKinfuAction, SIGNAL(triggered()), this, SLOT(ProcessIgnoreResetKinfuCloudSlot()));
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
	_ui->_smoothingTabWidget->setCurrentIndex(0);
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
	ISubject* openNI2 = _subjectFactory->GetOpenNI2Subject();
	openNI2->RegisterObserver(_uiObserver);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
	if (_grabber != NULL)
		_grabber->StopCamera();
	disconnect(this->_uiObserver, SIGNAL(UpdateViewer(pcl::PointCloud<PointT>::Ptr)), this, SLOT(UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr)));
	delete _grabberFactory;
}

std::string MainWindow::ShowInputDialogSlot(bool* ok, const char* title, const char* label, const char* text)
{
	QString input = QInputDialog::getText(this, tr(title), tr(label), QLineEdit::Normal, tr(text), ok);
	if ((*ok) && !input.isEmpty()) {
		return TypeConversion::QString2String(input);
	}
	return std::string("");
}

//****************************************************************
//										Slots : Viewer
//****************************************************************
void MainWindow::SetViewBackgroundToBlackSlot()
{
	_viewer->SetBackgroundColor(0, 0, 0);
	_ui->_qvtkWidget->update();
}

void MainWindow::SetViewWhiteBackgroundToWhiteSlot()
{
	_viewer->SetBackgroundColor(255, 255, 255);
	_ui->_qvtkWidget->update();
}

//****************************************************************
//								Slots : UI
//****************************************************************
void MainWindow::UpdateViewerSlot(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	if (_isTestedKinfuBoundingBox)
	{
		_filterProcessing->Processing(pointCloud);
		pointCloud = _filterProcessing->GetResult();
	}
	_tmpPointCloud = pointCloud;
	//std::unique_lock<std::mutex> lock(_grabber->GetMutex());
	_viewer->ShowPointCloud(pointCloud);
	//_viewer->ResetCamera();
	_ui->_qvtkWidget->update();
}

void MainWindow::TableItemChangeSlot(QTableWidgetItem* item)
{
	//UpdatePointCloudViewer();
	PointCloudElement* element = _elements->GetPointCloudElementById(item->row());
	element->SetIsSelected(item->checkState() == Qt::Checked);
	if (element->GetIsSelected())
	{
		element->Show(*_viewer);
	}
	else
	{
		element->Delete(*_viewer);
	}
	_ui->_qvtkWidget->update();
}

//****************************************************************
//								Slots : File
//****************************************************************
void MainWindow::OpenFileSlot()
{
	QString filter;
	QStringList filenames = QFileDialog::getOpenFileNames(this, tr("Open File"), "", tr("OBJ(*.obj);;PLY(*.ply);;PCD(*.pcd)"), &filter);
	for (int counter = 0; counter < filenames.count(); counter++)
		OpenFile(TypeConversion::QString2String(filenames.at(counter)), TypeConversion::QString2String(filter));
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::OpenFile(std::string dir, std::string filter)
{
	MyFile* file = _fileFactory->GetFileByFilter(dir, filter);
	file->LoadFile();
	//_pointClouds->AddPointCloud(file->GetPointCloud(), dir);
	MyPointCloud* cloud = new MyPointCloud(file->GetPointCloud(), dir);
	_elements->AddPointCloudElement(cloud);
}

void MainWindow::SaveFileSlot()
{
	QString filter;
	QString dir = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("OBJ(*.obj);; PLY(*.ply);; PCD(*.pcd)"), &filter);
	if (dir.isEmpty()) return;
	else
	{
		SaveFile(TypeConversion::QString2String(dir.split(".").at(0)), TypeConversion::QString2String(filter));
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SaveFile(std::string dir, std::string filter)
{
	std::string convertFilter;
	if (filter == "OBJ(*.obj)") convertFilter = ".obj";
	else if (filter == "PLY(*.ply)") convertFilter = ".ply";
	else if (filter == "PCD(*.pcd)") convertFilter = ".pcd";
	std::vector<PointCloudElement*> elements = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < elements.size(); counter++)
	{
		MyFile* file = _fileFactory->GetFileByFilter(dir + "_" + TypeConversion::Int2String(counter) + convertFilter, filter);
		//file->SaveFile(elements[counter]->GetPointCloud());
		elements[counter]->Save(file);
	}
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
	_grabber = _grabberFactory->GetRSGrabber(subject);
	_grabber->StartCamera();
}

void MainWindow::StartXtionProCameraSlot()
{
	ISubject* subject = _subjectFactory->GetOpenNI2Subject();
	_grabber = _grabberFactory->GetOpenNI2Grabber(subject);
	_grabber->StartCamera();
}

void MainWindow::StopCameraSlot()
{
	if (_grabber == NULL)	return;
	_grabber->StopCamera();
	_viewer->Clear();
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
	_grabber = NULL;
}

void MainWindow::SetCameraDepthConfidenceSlot()
{
	bool ok;
	emit std::string str = ShowDialog(&ok, "Set Camera Depth Confidence", "Depth Confidence");
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
	emit std::string str = ShowDialog(&ok, "Communicate Arduino", "Data");
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
	emit std::string str = ShowDialog(&ok, "Communicate Arduino", "Data");
	if (!ok)	return;
	_arduino->SendData(str[0]);
	Sleep(ARDUINO_SLEEP_TIME);
	char* recData = _arduino->ReceiveData();
	QMessageBox::about(this, tr("Communicate Arduino"), tr(recData));
}

void MainWindow::GetArraySlot()
{
	bool ok;
	emit std::string str = ShowDialog(&ok, "Communicate Arduino", "Data");
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
	emit std::string motorId = ShowDialog(&motorOk, "Control Motor", "Motor Id");
	if (!motorOk)	return;
	bool degreeOk;
	emit std::string degree = ShowDialog(&degreeOk, "Control Motor", "Degree");
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
	_keepFrameNumber = 0;
	if (_grabber == NULL)
	{
		QMessageBox::about(this, tr("Keep One Frame"), tr("Grabber is not open!"));
		return;
	}
	pcl::PointCloud<PointT>::Ptr copyCloud;
	copyCloud.reset(new pcl::PointCloud<PointT>(*_tmpPointCloud));
	bool ok;
	emit std::string cloudName = ShowDialog(&ok, "Keep PointCloud", "Cloud Name");
	if (!ok)	return;
	if (_elements->IsNameExist(cloudName) || cloudName == "")
	{
		QMessageBox::about(this, tr("Keep PointCloud"), tr("Name is exist/empty!"));
		return;
	}
	MyPointCloud* cloud = new MyPointCloud(_tmpPointCloud, cloudName);
	_elements->AddPointCloudElement(cloud);
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::KeepContinueFrameSlot()
{
	if (_grabber == NULL)
	{
		QMessageBox::about(this, tr("Keep Continue Frame"), tr("Grabber is not open!"));
		return;
	}
	if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Continue Frame")
	{
		bool ok;
		emit _keepCloudName = ShowDialog(&ok, "Keep PointCloud", "Cloud Name");
		if (!ok)	return;
		connect(this->_uiObserver, SIGNAL(KeepFrameArrived(pcl::PointCloud<PointT>::Ptr)), this, SLOT(KeepFrameArrivedSlot(pcl::PointCloud<PointT>::Ptr)));
		_ui->_keepContinueFrameAction->setText(QString("Stop"));
	}
	else if (TypeConversion::QString2String(_ui->_keepContinueFrameAction->text()) == "Stop")
	{
		disconnect(this->_uiObserver, SIGNAL(KeepFrameArrived(pcl::PointCloud<PointT>::Ptr)), this, SLOT(KeepFrameArrivedSlot(pcl::PointCloud<PointT>::Ptr)));
		_ui->_keepContinueFrameAction->setText(QString("Continue Frame"));
	}
}

void MainWindow::KeepFrameArrivedSlot(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	clock_t nowFrameTime = clock();
	if ((double)(nowFrameTime - _preFrameTime) / (double)(CLOCKS_PER_SEC) <= FRAME_PITCH)
		return;
	std::string cloudName = _keepCloudName + std::string("_") + TypeConversion::Int2String(_keepFrameNumber);
	if (_isTestedKinfuBoundingBox)
	{
		_filterProcessing->Processing(pointCloud);
		pointCloud = _filterProcessing->GetResult();
	}
	MyPointCloud* cloud = new MyPointCloud(pointCloud, cloudName);
	_elements->AddPointCloudElement(cloud);
	_viewer->ShowPointCloud(pointCloud);
	_ui->_qvtkWidget->update();
	UpdatePointCloudTable();
	_keepFrameNumber++;
	_preFrameTime = nowFrameTime;
}

void MainWindow::RemoveSelectedPointCloudSlot()
{
	_elements->RemoveSelectedPointCloud();
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::RemoveAllPointCloudSlot()
{
	_elements->RemoveAllPointCloud();
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SelectAllPointCloudSlot()
{
	_elements->SelectAllPointCloud();
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::UnselectAllPointCloudSlot()
{
	_elements->UnselectAllPointCloud();
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::CombinePointCloudSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() < 2)
	{
		QMessageBox::about(this, tr("Process ICP"), tr("Selecct More Than Two Point Cloud!"));
		return;
	}
	pcl::PointCloud<PointT>::Ptr combinedCloud(new pcl::PointCloud<PointT>);
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		*combinedCloud += *clouds[counter]->GetPointCloud();
	}
	std::string name = std::string("Combine");
	MyPointCloud* cloud = new MyPointCloud(combinedCloud, name);
	_elements->AddPointCloudElement(cloud);
	UpdatePointCloudTable();
}

void MainWindow::GetMinNegativeNumberSlot()
{
	double min = 0;
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>(*clouds[counter]->GetPointCloud()));
		for (int pointCounter = 0; pointCounter < temp->size(); pointCounter++)
		{
			if (temp->points[pointCounter].x < min)
				min = temp->points[pointCounter].x;
			if (temp->points[pointCounter].y < min)
				min = temp->points[pointCounter].y;
			if (temp->points[pointCounter].z < min)
				min = temp->points[pointCounter].z;
		}
	}
	QMessageBox::about(this, tr("Min Negative Number"), tr(TypeConversion::Double2String(std::abs(min)).c_str()));
}

void MainWindow::MultiplicationPointCloudSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	double magnificationX = TypeConversion::QString2Double(_ui->_multiplicationXSpinBox->text());
	double magnificationY = TypeConversion::QString2Double(_ui->_multiplicationYSpinBox->text());
	double magnificationZ = TypeConversion::QString2Double(_ui->_multiplicationZSpinBox->text());
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>(*clouds[counter]->GetPointCloud()));
		for (int pointIndex = 0; pointIndex < temp->points.size(); pointIndex++)
		{
			temp->points[pointIndex].x *= magnificationX;
			temp->points[pointIndex].y *= magnificationY;
			temp->points[pointIndex].z *= magnificationZ;
		}
		std::string name = clouds[counter]->GetName() + std::string("_Magnification");
		MyPointCloud* cloud = new MyPointCloud(temp, name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
}

void MainWindow::ShiftPointCloudSlot()
{
	double shiftX = TypeConversion::QString2Double(_ui->_shiftXSpinBox->text());
	double shiftY = TypeConversion::QString2Double(_ui->_shiftYSpinBox->text());
	double shiftZ = TypeConversion::QString2Double(_ui->_shiftZSpinBox->text());
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>(*clouds[counter]->GetPointCloud()));
		for (int pointCounter = 0; pointCounter < temp->size(); pointCounter++)
		{
			temp->points[pointCounter].x += shiftX;
			temp->points[pointCounter].y += shiftY;
			temp->points[pointCounter].z += shiftZ;
		}
		std::string name = clouds[counter]->GetName() + std::string("_Shift");
		MyPointCloud* cloud = new MyPointCloud(temp, name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
}

void MainWindow::RemoveNANSlot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>());
		std::vector<int> map;
		pcl::removeNaNFromPointCloud(*clouds[counter]->GetPointCloud(), *temp, map);
		std::string name = clouds[counter]->GetName() + std::string("_NAN");
		MyPointCloud* cloud = new MyPointCloud(temp, name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
}

//****************************************************************
//								Slots : Processing
//****************************************************************

void MainWindow::ProcessICP1Slot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() < 2)
	{
		QMessageBox::about(this, tr("Process ICP"), tr("Selecct More Than Two Point Cloud!"));
		return;
	}
	std::vector<Eigen::Matrix4f> matrices;
	for (int counter = 1; counter < clouds.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr corSource = clouds[counter - 1]->GetPointCloud();
		pcl::PointCloud<PointT>::Ptr corTarget = clouds[counter]->GetPointCloud();
		_regestrationProcessing->Processing(corSource, corTarget);
		matrices.push_back(_regestrationProcessing->GetMatrix().inverse());
		std::cout << "Process ICP : " << counter + 1 << " / " << clouds.size() << std::endl;
		std::cout << "Has Converged : " << _regestrationProcessing->HasConverged() << std::endl;
	}
	//pcl::PointCloud<PointT>::Ptr result(new pcl::PointCloud<PointT>(*clouds[0]->GetPointCloud()));
	Eigen::Matrix4f globalTransform = Eigen::Matrix4f::Identity();
	for (int counter = 0; counter < matrices.size(); counter++)
	{
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>);
		globalTransform *= matrices[counter];
		pcl::transformPointCloud(*clouds[counter + 1]->GetPointCloud(), *temp, globalTransform);
		//*result += *temp;
		std::string name = std::string("ICP_1_Transform_") + TypeConversion::Int2String(counter);
		MyPointCloud* cloud = new MyPointCloud(temp, name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
}

void MainWindow::ProcessICP2Slot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() < 2)
	{
		QMessageBox::about(this, tr("Process ICP"), tr("Selecct More Than Two Point Cloud!"));
		return;
	}
	pcl::PointCloud<PointT>::Ptr result(new pcl::PointCloud<PointT>(*clouds[0]->GetPointCloud()));
	for (int counter = 1; counter < clouds.size(); counter++)
	{
		_regestrationProcessing->Processing(result, clouds[counter]->GetPointCloud());
		result.reset(new pcl::PointCloud<PointT>(*_regestrationProcessing->GetResult()));
		std::cout << "Process ICP : " << counter + 1 << " / " << clouds.size() << std::endl;
		std::cout << "Has Converged : " << _regestrationProcessing->HasConverged() << std::endl;
		std::string name = std::string("ICP_2_Result_") + TypeConversion::Int2String(counter);
		MyPointCloud* cloud = new MyPointCloud(result, name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
}

void MainWindow::ProcessICP3Slot()
{
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() < 2)
	{
		QMessageBox::about(this, tr("Process ICP"), tr("Selecct More Than Two Point Cloud!"));
		return;
	}
	pcl::PointCloud<PointT>::Ptr result(new pcl::PointCloud<PointT>(*clouds[0]->GetPointCloud()));
	for (int counter = 1; counter < clouds.size(); counter++)
	{
		_keypointProcessing->Processing(result);
		pcl::PointCloud<KeypointT>::Ptr sourceKeypoint(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		//		Save Keypoint
		std::string keypoint1Name = std::string("ICP_3_Keypoint_") + TypeConversion::Int2String(counter) + std::string("_1");
		MyKeyPoint* keypoint1 = new MyKeyPoint(_keypointProcessing->GetResult(), keypoint1Name);
		//_elements->AddPointCloudElement(keypoint1);

		_keypointProcessing->Processing(clouds[counter]->GetPointCloud());
		pcl::PointCloud<KeypointT>::Ptr targetKeypoint(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		//		Save Keypoint
		std::string keypoint2Name = std::string("ICP_3_Keypoint_") + TypeConversion::Int2String(counter) + std::string("_2");
		MyKeyPoint* keypoint2 = new MyKeyPoint(_keypointProcessing->GetResult(), keypoint2Name);
		//_elements->AddPointCloudElement(keypoint2);

		_correspondencesProcessing->Processing(result, sourceKeypoint, clouds[counter]->GetPointCloud(), targetKeypoint);
		//		Save Correspondence
		std::string correspondencesName = std::string("ICP_3_Correspondences_") + TypeConversion::Int2String(counter);
		MyCorrespondences* correspondences = new MyCorrespondences(keypoint1, keypoint2, _correspondencesProcessing->GetCorrespondencesResult(), correspondencesName);
		_elements->AddPointCloudElement(correspondences);
		//		ICP
		pcl::PointCloud<PointT>::Ptr temp(new pcl::PointCloud<PointT>(*_correspondencesProcessing->GetResult()));
		_regestrationProcessing->Processing(clouds[counter]->GetPointCloud(), temp);
		result = _regestrationProcessing->GetResult();
		std::string name = std::string("ICP_3_Result_") + TypeConversion::Int2String(counter);
		MyPointCloud* cloud = new MyPointCloud(result, name);
		_elements->AddPointCloudElement(cloud);
		std::cout << "Process ICP3 : " << counter + 1 << " / " << clouds.size() << std::endl;
	}
	UpdatePointCloudTable();
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
	else if (index == 2)
	{
		_filterProcessing = _filterFactory->GetOutlierRemovalFilter();
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
		std::cout << "Process Filter : " << counter + 1 << " / " << clouds.size() << std::endl;
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SetFilterVoxelGridXYZSlot()
{
	float x = TypeConversion::QString2Float(_ui->_voxelGridXSpinBox->text());
	float y = TypeConversion::QString2Float(_ui->_voxelGridYSpinBox->text());
	float z = TypeConversion::QString2Float(_ui->_voxelGridZSpinBox->text());
	_filterProcessing->SetLeafSize(x, y, z);
}

void MainWindow::SetFilterBoundingBoxSlot()
{
	float minX = TypeConversion::QString2Float(_ui->_boundingBoxMinXSpinBox->text());
	float maxX = TypeConversion::QString2Float(_ui->_boundingBoxMaxXSpinBox->text());
	float minY = TypeConversion::QString2Float(_ui->_boundingBoxMinYSpinBox->text());
	float maxY = TypeConversion::QString2Float(_ui->_boundingBoxMaxYSpinBox->text());
	float minZ = TypeConversion::QString2Float(_ui->_boundingBoxMinZSpinBox->text());
	float maxZ = TypeConversion::QString2Float(_ui->_boundingBoxMaxZSpinBox->text());
	_filterProcessing->SetBoundingBox(minX, maxX, minY, maxY, minZ, maxZ);
}

void MainWindow::SetFilterMeanKSlot(int meanK)
{
	_filterProcessing->SetMeanK(meanK);
}

void MainWindow::SetFilterStddevMulThreshSlot(double stddevMulThresh)
{
	_filterProcessing->SetStddevMulThresh(stddevMulThresh);
}

void MainWindow::TestBoundingBoxSlot()
{
	if (_dialog != NULL)	delete _dialog;
	_dialog = new BoundingBoxTestDialog(_filterFactory->GetBoundingBoxFilter(), 0);
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() != 1)
	{
		QMessageBox::about(this, tr("Bounding Box Test"), tr("Selecct One Point Cloud!"));
		return;
	}
	_dialog->SetPointCloud(clouds[0]);
	_dialog->show();
	connect(_dialog, SIGNAL(TestFinished(float, float, float, float, float, float)), this, SLOT(GetDialogResultSlot(float, float, float, float, float, float)));
}

void MainWindow::GetDialogResultSlot(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
{
	_ui->_boundingBoxMinXSpinBox->setValue(minX);
	_ui->_boundingBoxMaxXSpinBox->setValue(maxX);
	_ui->_boundingBoxMinYSpinBox->setValue(minY);
	_ui->_boundingBoxMaxYSpinBox->setValue(maxY);
	_ui->_boundingBoxMinZSpinBox->setValue(minZ);
	_ui->_boundingBoxMaxZSpinBox->setValue(maxZ);
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
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
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

void MainWindow::SetKeypointScalesSlot()
{
	float minScale = TypeConversion::QString2Float(_ui->_siftMinScaleSpinBox->text());
	int nrOctaves = TypeConversion::QString2Int(_ui->_siftNROctavesSpinBox->text());
	int nrScalesPerOctave = TypeConversion::QString2Int(_ui->_siftNRScalesPerOctaveSpinBox->text());
	_keypointProcessing->SetScales(minScale, nrOctaves, nrScalesPerOctave);
}

void MainWindow::SetKeypointMinContrastSlot()
{
	float siftMinContrast = TypeConversion::QString2Float(_ui->_siftMinContrastSpinBox->text());
	_keypointProcessing->SetMinContrast(siftMinContrast);
}

void MainWindow::SetKeypointMethodSlot(int index)
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
	else if (index == 3)
	{
		_keypointProcessing = _keypointFactory->Lowe();
	}
	else
	{
		_keypointProcessing = _keypointFactory->Curvature();
	}
}

void MainWindow::SetKeypointRadiusSlot()
{
	float harrisRadius = TypeConversion::QString2Float(_ui->_harrisRadiusSpinBox->text());
	_keypointProcessing->SetRadius(harrisRadius);
}

void MainWindow::SetKeypointRadiusSearchSlot()
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
		pcl::PointCloud<KeypointT>::Ptr sourceKeypoint(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		std::string sourceName = clouds[0]->GetName() + std::string("_Correspondence_Keypoint");
		MyKeyPoint* sourceMyKpt = new MyKeyPoint(sourceKeypoint, sourceName);
		_keypointProcessing->Processing(targetCloud);
		pcl::PointCloud<KeypointT>::Ptr targetKeypoint(new pcl::PointCloud<KeypointT>(*_keypointProcessing->GetResult()));
		std::string targetName = clouds[1]->GetName() + std::string("_Correspondence_Keypoint");
		MyKeyPoint* targetMyKpt = new MyKeyPoint(targetKeypoint, targetName);
		_correspondencesProcessing->Processing(sourceCloud, sourceKeypoint, targetCloud, targetKeypoint);
		std::string name = clouds[0]->GetName() + "_" + std::string("_Correspondence_PointCloud");
		MyPointCloud* cloud = new MyPointCloud(_correspondencesProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
		std::string correspondencesName = clouds[0]->GetName() + "_" + clouds[1]->GetName() + "_" + TypeConversion::Int2String(_keepFrameNumber) + std::string("_Correspondence_Correspondences");
		MyCorrespondences* correspondences = new MyCorrespondences(sourceMyKpt, targetMyKpt, _correspondencesProcessing->GetCorrespondencesResult(), correspondencesName);
		_elements->AddPointCloudElement(correspondences);
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
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
		std::string name = clouds[0]->GetName() + "_" + clouds[1]->GetName() + std::string("_Regestration");
		MyPointCloud* cloud = new MyPointCloud(_regestrationProcessing->GetResult(), name);
		_elements->AddPointCloudElement(cloud);
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SetRegestrationCorrespondenceDistanceSlot(double correspondenceDistance)
{
	_regestrationProcessing->SetCorrespondenceDistance(correspondenceDistance);
}

void MainWindow::SetRegestrationOutlierThresholdSlot(double outlierThreshold)
{
	_regestrationProcessing->SetRansacOutlierRejectionThreshold(outlierThreshold);
}

void MainWindow::SetEuclideanFitnessEpsilonSlot(double euclideanFitnessEpsilon)
{
	_regestrationProcessing->SetEuclideanFitnessEpsilon(euclideanFitnessEpsilon);
}

void MainWindow::SetRegestrationMaxIterationsSlot(int maxIterations)
{
	_regestrationProcessing->SetMaximumIterations(maxIterations);
}

//****************************************************************
//								Slots : Reconstruct
//****************************************************************
void MainWindow::ChangeReconstructTabSlot(int index)
{
	if (index == 0)
	{
		_reconstructProcessing = _reconstructFactory->GetGreedyProjection();
	}
	else if (index == 1)
	{
		_reconstructProcessing = _reconstructFactory->GetPoisson();
	}
	else if (index == 2)
	{
		_reconstructProcessing = _reconstructFactory->GetConcaveHull();
	}
}

void MainWindow::ProcessReconstructSlot()
{
	int index = _ui->_reconstructTabWidget->currentIndex();
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		_reconstructProcessing->Processing(clouds[counter]->GetPointCloud());
		std::string name = clouds[0]->GetName() + "_" + std::string("_Reconstruct");
		if (index == 0 || index == 1)
		{
			MySurface* surface = new MySurface(_reconstructProcessing->GetMesh(), name);
			_elements->AddPointCloudElement(surface);
		}
		else
		{
			MyPointCloud* cloud = new MyPointCloud(_reconstructProcessing->GetCloud(), name);
			_elements->AddPointCloudElement(cloud);
		}
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::SetReconstructSearchRadiusSlot(double searchRadius)
{
	_reconstructProcessing->SetSearchRadius(searchRadius);
}

void MainWindow::SetReconstructMuSlot(double mu)
{
	_reconstructProcessing->SetMu(mu);
}

void MainWindow::SetReconstructMaxNearestNeighborsSlot(int maxNearestNeighbors)
{
	_reconstructProcessing->SetMaxNearestNeighbors(maxNearestNeighbors);
}

void MainWindow::SetReconstructMaxSurfaceAngleSlot(int maxSurfaceAngle)
{
	_reconstructProcessing->SetMaxSurfaceAngle(maxSurfaceAngle);
}

void MainWindow::SetReconstructMinAngleSlot(int minAngle)
{
	_reconstructProcessing->SetMinAngle(minAngle);
}

void MainWindow::SetReconstructMaxAngleSlot(int maxAngle)
{
	_reconstructProcessing->SetMaxAngle(maxAngle);
}

void MainWindow::SetReconstructGridResolutionXYZSlot()
{
	/*
	float x = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionXSpinBox->text());
	float y = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionYSpinBox->text());
	float z = TypeConversion::QString2Float(_ui->_marchingCubesGridResolutionZSpinBox->text());
	_reconstructProcessing->SetGridResolution(x, y, z);
	*/
}

void MainWindow::SetReconstructIsoLevelSlot(double isoLevel)
{
	_reconstructProcessing->SetIsoLevel(isoLevel);
}

void MainWindow::SetReconstructNormalSearchRadiusSlot(double normalSearchRadius)
{
	_reconstructProcessing->SetNormalSearchRadius(normalSearchRadius);
}

void MainWindow::SetReconstructDepthSlot(int depth)
{
	_reconstructProcessing->SetReconstructDepth(depth);
}

void MainWindow::SetReconstructAlphaSlot(double alpha)
{
	_reconstructProcessing->SetReconstructAlpha(alpha);
}

//****************************************************************
//								Slots : Smoothing Processing
//****************************************************************
void MainWindow::ProcessSmoothingSlot()
{
	int index = _ui->_smoothingTabWidget->currentIndex();
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		if (index == 0)
		{
			_smoothingProcessing->Processing(clouds[counter]->GetMesh());
			std::string name = clouds[0]->GetName() + "_" + std::string("_Smoothing");
			MySurface* surface = new MySurface(_smoothingProcessing->GetMesh(), name);
			_elements->AddPointCloudElement(surface);
		}
		else
		{
			_smoothingProcessing->Processing(clouds[counter]->GetPointCloud());
			std::string name = clouds[0]->GetName() + "_" + std::string("_Smoothing");
			MyPointCloud* cloud = new MyPointCloud(_smoothingProcessing->GetCloud(), name);
			_elements->AddPointCloudElement(cloud);
		}
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::ChangeSmoothingTabSlot(int index)
{
	if (index == 0)
	{
		_smoothingProcessing = _smoothingFactory->GetMeshSmoothingLaplacian();
	}
	else if (index == 1)
	{
		_smoothingProcessing = _smoothingFactory->GetResampling();
	}
}

void MainWindow::SetSmoothingNumIterSlot(int numIter)
{
	_smoothingProcessing->SetNumIter(numIter);
}

void MainWindow::SetSmoothingConvergenceSlot(double convergence)
{
	_smoothingProcessing->SetConvergence(convergence);
}

void MainWindow::SetSmoothingRelaxationFactorMaxAngleSlot(double relaxationFactor)
{
	_smoothingProcessing->SetRelaxationFactor(relaxationFactor);
}

void MainWindow::SetSmoothingFeatureAngleSlot(int featureAngle)
{
	_smoothingProcessing->SetFeatureAngle(featureAngle);
}

void MainWindow::SetSmoothingSearchRadiusSlot(double searchRadius)
{
	_smoothingProcessing->SetSearchRadius(searchRadius);
}

//****************************************************************
//								Slots : Kinfu
//****************************************************************

void MainWindow::ProcessSegmentedKinfuCloudSlot()
{
	bool firstFrame = true;
	float volumeSize = 1.f;
	int icp = 1, visualization = 0;
	boost::shared_ptr<CameraPoseProcessor> poseProcessor;
	KinFuApp kinfu(volumeSize, icp, visualization, poseProcessor);
	//kinfu.startMainLoop();
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() == 0)return;
	std::vector<int> resetFrames;
	resetFrames.push_back(-1);
	//kinfu.registration_ = true;
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		kinfu.source_cb3(clouds[counter]->GetPointCloud());
		bool kinfuOK = kinfu.execute();
		if (!kinfuOK)
		{
			if (firstFrame)
			{
				firstFrame = false;
			}
			else
			{
				resetFrames.push_back(counter);
				std::cout << "Process Kinfu : Reset frame number " << counter + 1 << std::endl;
				firstFrame = true;
			}
		}
	}
	resetFrames.push_back(clouds.size());
	std::cout << "---------------------------------------------------------" << std::endl;
	for (int resetIndex = 0; resetIndex < resetFrames.size() - 1; resetIndex++)
	{
		if (resetFrames[resetIndex] + 1 == resetFrames[resetIndex + 1])
			continue;
		KinFuApp kinfuSeg(volumeSize, icp, visualization, poseProcessor);
		for (int segIndex = resetFrames[resetIndex] + 1; segIndex < resetFrames[resetIndex + 1]; segIndex++)
		{
			std::cout << "Process Kinfu : Frame number " << segIndex + 1 << std::endl;
			if (segIndex == resetFrames[resetIndex + 1] - 1)
			{
				kinfuSeg.scan_ = true;
				kinfuSeg.scan_mesh_ = true;
			}
			kinfuSeg.source_cb3(clouds[segIndex]->GetPointCloud());
			bool kinfuOK = kinfuSeg.execute();
		}
		std::string cloudName = std::string("Kinfu_PointCloud_") + TypeConversion::Int2String(resetIndex);
		MyPointCloud* cloud = new MyPointCloud(kinfuSeg.GetPointCloud(), cloudName);
		_elements->AddPointCloudElement(cloud);
		std::string meshName = std::string("Kinfu_Mesh_") + TypeConversion::Int2String(resetIndex);
		MySurface* mesh = new MySurface(kinfuSeg.GetMesh(), meshName);
		_elements->AddPointCloudElement(mesh);
	}
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::ProcessIgnoreResetKinfuCloudSlot()
{
	bool firstFrame = true;
	bool noReset = true;
	float volumeSize = 1.f;
	int icp = 1, visualization = 0;
	boost::shared_ptr<CameraPoseProcessor> poseProcessor;
	std::vector<PointCloudElement*> clouds = _elements->GetElementsByIsSelected();
	if (clouds.size() == 0)return;
	//std::vector<int> resetFrames;

	Eigen::Matrix<float, 3, 3, Eigen::RowMajor> globalR = Eigen::Matrix3f::Identity();
	Eigen::Vector3f  globalT(0, 0, 0);

	std::vector<Eigen::Matrix<float, 3, 3, Eigen::RowMajor>> rs;
	std::vector<Eigen::Vector3f> ts;
	
	KinFuApp kinfu(volumeSize, icp, visualization, poseProcessor);
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		kinfu.source_cb3(clouds[counter]->GetPointCloud());
		bool kinfuOK = kinfu.execute();
		if (!kinfuOK)
		{
			if (firstFrame)
			{
				firstFrame = false;
				if (!noReset)
				{
					kinfu.SetInitalCameraPose(rs.at(rs.size() - 1), ts.at(ts.size() - 1));
				}
				else
				{
					rs.push_back(kinfu.GetR());
					ts.push_back(kinfu.GetT());
				}
			}
			else
			{
				globalR = rs.at(rs.size() - 1);
				globalT = ts.at(ts.size() - 1);
				std::cout << "Frame number : " << counter << ", " << counter + 1 << "tracking lost !" << std::endl;
				
				Eigen::Matrix4f globalRT = RTConversion::RT(globalR, globalT);
				pcl::PointCloud<PointT>::Ptr source(new pcl::PointCloud<PointT>);
				pcl::PointCloud<PointT>::Ptr target(new pcl::PointCloud<PointT>);
				pcl::transformPointCloud(*clouds[counter - 1]->GetPointCloud(), *source, globalRT);
				pcl::transformPointCloud(*clouds[counter]->GetPointCloud(), *target, globalRT);
				_regestrationProcessing->Processing(source, target);
				Eigen::Matrix4f rt = _regestrationProcessing->GetMatrix();
				Eigen::Matrix<float, 3, 3, Eigen::RowMajor> r;
				Eigen::Vector3f t;
				RTConversion::RT(r, t, rt);
				
				rs.push_back(globalR);
				ts.push_back(globalT);
				counter--;
				firstFrame = true;
				noReset = false;
			}
		}
		else
		{
			rs.push_back(kinfu.GetR());
			ts.push_back(kinfu.GetT());
		}
	}
	SaveRTMatrix(rs, ts);
	
	std::cout << "---------------------------------------------------------" << std::endl;
	KinFuApp kinfuRes(volumeSize, 0, visualization, poseProcessor);
	kinfuRes.SetRMatrix(rs);
	kinfuRes.SetTVector(ts);
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		std::cout << "Process Kinfu : Frame number " << counter + 1 << std::endl;
		//if (counter == clouds.size() - 1)
		//{
			kinfuRes.scan_ = true;
			kinfuRes.scan_mesh_ = true;
		//}
		kinfuRes.source_cb3(clouds[counter]->GetPointCloud());
		bool kinfuOK = kinfuRes.execute();
		if (!kinfuOK)
			std::cout << "Frame number : " << counter << ", " << counter + 1 << "tracking lost !" << std::endl;

		std::string cloudName = std::string("Kinfu_PointCloud") + TypeConversion::Int2String(counter);
		MyPointCloud* cloud = new MyPointCloud(kinfuRes.GetPointCloud(), cloudName);
		_elements->AddPointCloudElement(cloud);
		std::string meshName = std::string("Kinfu_Mesh") + TypeConversion::Int2String(counter);
		MySurface* mesh = new MySurface(kinfuRes.GetMesh(), meshName);
		_elements->AddPointCloudElement(mesh);
	}
	/*  Check camera pose
	for (int counter = 0; counter < clouds.size(); counter++)
	{
		Eigen::Matrix4f rt = RTConversion::RT(rs[counter], ts[counter]);

		pcl::PointCloud<PointT>::Ptr  temp(new pcl::PointCloud<PointT>);
		pcl::transformPointCloud(*clouds[counter]->GetPointCloud(), *temp, rt);
		std::string cloudName = std::string("Kinfu_PointCloud_") + TypeConversion::Int2String(counter);
		MyPointCloud* cloud = new MyPointCloud(temp, cloudName);
		_elements->AddPointCloudElement(cloud);
	}*/
	UpdatePointCloudTable();
	UpdatePointCloudViewer();
}

void MainWindow::GetKinfuTestBoundingBoxSlot()
{
	if (TypeConversion::QString2String(_ui->_kinfuTestBoundingBoxAction->text()) == "Test Bounding Box")
	{
		_isTestedKinfuBoundingBox = true;
		_ui->_kinfuTestBoundingBoxAction->setText(QString("Reset"));
	}
	else
	{
		_isTestedKinfuBoundingBox = false;
		_ui->_kinfuTestBoundingBoxAction->setText(QString("Test Bounding Box"));
	}
}

void MainWindow::ProcessKinfuTestBoundingBoxSlot()
{
	_filterProcessing = _filterFactory->GetDepthImageBoundingBoxFilter();
	if (_dialog != NULL)	delete _dialog;
	_dialog = new BoundingBoxTestDialog(_filterProcessing, 1);
	_dialog->SetScrollBarX(0, _tmpPointCloud->width, 1, 1);
	_dialog->SetScrollBarY(0, _tmpPointCloud->height, 1, 1);
	_dialog->SetScrollBarZ(-200, 200, 1, 100);
	_dialog->SetPointCloud(new MyPointCloud(_tmpPointCloud));
	_dialog->show();
	connect(_dialog, SIGNAL(TestKinfuFinished()), this, SLOT(GetKinfuTestBoundingBoxSlot()));
}

void MainWindow::SaveRTMatrix(std::vector<Eigen::Matrix<float, 3, 3, Eigen::RowMajor>> r, std::vector<Eigen::Vector3f> t)
{
	QString filter;
	QString dir = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("TXT(*.txt)"), &filter);
	if (dir.isEmpty()) return;
	else
	{
		fstream fp;
		fp.open(TypeConversion::QString2String(dir), ios::out);//開啟檔案
		if (fp)
		{//如果開啟檔案失敗，fp為0；成功，fp為非0
			for (int counter = 0; counter < r.size(); counter++)
			{
				fp << counter << std::string(" :") << std::endl;
				fp << "R : " << std::endl << r.at(counter) << std::endl;
				fp << "T : " << std::endl << t.at(counter) << std::endl;
				fp << std::endl;
			}
		}
		fp.close();
	}
}