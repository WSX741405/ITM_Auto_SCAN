#include "BoundingBoxTestDialog.h"

BoundingBoxTestDialog::BoundingBoxTestDialog() : _dialog(new Ui::BoundingBoxTestDialog)
{
	_dialog->setupUi(this);
	_cloud = NULL;
	//		Initialize Variable
	_viewer = new Viewer();
	_filterFactory = new FilterFactory();
	_filterProcessing = _filterFactory->GetBoundingBoxFilter();
	//		Initialize Component
	InitialPointCloudViewer();
	//		Connect Slots
	connect(_dialog->_minXScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxXScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_minYScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxYScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_minZScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxZScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_acceptButton, SIGNAL(clicked()), this, SLOT(AcceptSlot()));
	connect(_dialog->_rejectButton, SIGNAL(clicked()), this, SLOT(RejectSlot()));
}

void BoundingBoxTestDialog::SetPointCloud(PointCloudElement* cloud)
{
	_cloud = cloud;
	UpdateLabel();
}

void BoundingBoxTestDialog::InitialPointCloudViewer()
{
	_dialog->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_dialog->_qvtkWidget->GetInteractor(), _dialog->_qvtkWidget->GetRenderWindow());
	_dialog->_qvtkWidget->update();
}

void BoundingBoxTestDialog::UpdateLabel()
{
	_minX = (float)(_dialog->_minXScrollBar->value()) / SCROLL_BAR_DIVIDE;
	_maxX = (float)(_dialog->_maxXScrollBar->value()) / SCROLL_BAR_DIVIDE;
	_minY = (float)(_dialog->_minYScrollBar->value()) / SCROLL_BAR_DIVIDE;
	_maxY = (float)(_dialog->_maxYScrollBar->value()) / SCROLL_BAR_DIVIDE;
	_minZ = (float)(_dialog->_minZScrollBar->value()) / SCROLL_BAR_DIVIDE;
	_maxZ = (float)(_dialog->_maxZScrollBar->value()) / SCROLL_BAR_DIVIDE;
	if (_minX >= _maxX)
	{
		_dialog->_maxXScrollBar->setValue(_dialog->_minXScrollBar->value() + 1);
		_maxX = _minX + (1 / SCROLL_BAR_DIVIDE);
	}
	if (_minY >= _maxY)
	{
		_dialog->_maxYScrollBar->setValue(_dialog->_minYScrollBar->value() + 1);
		_maxY = _minY + (1 / SCROLL_BAR_DIVIDE);
	}
	if (_minZ >= _maxZ)
	{
		_dialog->_maxZScrollBar->setValue(_dialog->_minZScrollBar->value() + 1);
		_maxZ = _minZ + (1 / SCROLL_BAR_DIVIDE);
	}
	_dialog->_minXDisplayLabel->setText(QString::number(_minX));
	_dialog->_maxXDisplayLabel->setText(QString::number(_maxX));
	_dialog->_minYDisplayLabel->setText(QString::number(_minY));
	_dialog->_maxYDisplayLabel->setText(QString::number(_maxY));
	_dialog->_minZDisplayLabel->setText(QString::number(_minZ));
	_dialog->_maxZDisplayLabel->setText(QString::number(_maxZ));
	_filterProcessing->SetBoundingBox(_minX, _maxX, _minY, _maxY, _minZ, _maxZ);
	if (_cloud == NULL)
		return;
	_filterProcessing->Processing(_cloud->GetPointCloud());
	_filteredCloud = new MyPointCloud(_filterProcessing->GetResult(), _cloud->GetName());
	_filteredCloud->Show(*_viewer);
	_dialog->_qvtkWidget->update();
}

//--------------------------------------------------------------------------------------------
//														SLOTS
//--------------------------------------------------------------------------------------------

void BoundingBoxTestDialog::SetBoundingBoxSlot()
{
	UpdateLabel();
}

void BoundingBoxTestDialog::AcceptSlot()
{
	emit BoundingBoxTestDialog::TestFinished(_minX, _maxX, _minY, _maxY, _minZ, _maxZ);
	this->close();
}

void BoundingBoxTestDialog::RejectSlot()
{
	this->close();
}