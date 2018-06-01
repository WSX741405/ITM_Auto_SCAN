#include "BoundingBoxTestDialog.h"

BoundingBoxTestDialog::BoundingBoxTestDialog(FilterProcessing* filter, int mode) : _dialog(new Ui::BoundingBoxTestDialog)
{
	_dialog->setupUi(this);
	_mode = mode;
	_cloud = NULL;
	//		Initialize Variable
	_viewer = new Viewer();
	_filterProcessing = filter;
	//		Initialize Component
	InitialPointCloudViewer();
	//		Connect Slots
	connect(_dialog->_minXScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxXScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_minYScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxYScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_minZScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_maxZScrollBar, SIGNAL(valueChanged(int)), this, SLOT(SetBoundingBoxSlot()));
	connect(_dialog->_minXLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_maxXLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_minYLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_maxYLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_minZLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_maxZLineEdit, SIGNAL(editingFinished()), this, SLOT(EditLineBoundingBoxSlot()));
	connect(_dialog->_acceptButton, SIGNAL(clicked()), this, SLOT(AcceptSlot()));
	connect(_dialog->_rejectButton, SIGNAL(clicked()), this, SLOT(RejectSlot()));
}

BoundingBoxTestDialog::~BoundingBoxTestDialog()
{
	delete _viewer;
	delete _filteredCloud;
}

void BoundingBoxTestDialog::SetPointCloud(PointCloudElement* cloud)
{
	_viewer->Clear();
	_cloud = cloud;
	UpdateDisplay();
}

void BoundingBoxTestDialog::InitialPointCloudViewer()
{
	_dialog->_qvtkWidget->SetRenderWindow(_viewer->GetRenderWindow());
	_viewer->SetupInteractor(_dialog->_qvtkWidget->GetInteractor(), _dialog->_qvtkWidget->GetRenderWindow());
	_viewer->AddCoordinateSystem(1, -1, -1, -1);
	_dialog->_qvtkWidget->update();
}

void BoundingBoxTestDialog::SetScrollBarX(double xBarMin, double xBarMax, double xSingleStep, double scrollDivideX)
{
	_dialog->_minXScrollBar->setRange(xBarMin, xBarMax);
	_dialog->_minXScrollBar->setValue(xBarMin);
	_dialog->_minXScrollBar->setSingleStep(xSingleStep);

	_dialog->_maxXScrollBar->setRange(xBarMin, xBarMax);
	_dialog->_maxXScrollBar->setValue(xBarMax);
	_dialog->_maxXScrollBar->setSingleStep(xSingleStep);
	_scrollDivideX = scrollDivideX;
}

void BoundingBoxTestDialog::SetScrollBarY(double yBarMin, double yBarMax, double ySingleStep, double scrollDivideY)
{
	_dialog->_minYScrollBar->setRange(yBarMin, yBarMax);
	_dialog->_minYScrollBar->setValue(yBarMin);
	_dialog->_minYScrollBar->setSingleStep(ySingleStep);

	_dialog->_maxYScrollBar->setRange(yBarMin, yBarMax);
	_dialog->_maxYScrollBar->setValue(yBarMax);
	_dialog->_maxYScrollBar->setSingleStep(ySingleStep);
	_scrollDivideY = scrollDivideY;
}

void BoundingBoxTestDialog::SetScrollBarZ(double zBarMin, double zBarMax, double zSingleStep, double scrollDivideZ)
{
	_dialog->_minZScrollBar->setRange(zBarMin, zBarMax);
	_dialog->_minZScrollBar->setValue(zBarMin);
	_dialog->_minZScrollBar->setSingleStep(zSingleStep);

	_dialog->_maxZScrollBar->setRange(zBarMin, zBarMax);
	_dialog->_maxZScrollBar->setValue(zBarMax);
	_dialog->_maxZScrollBar->setSingleStep(zSingleStep);
	_scrollDivideZ = scrollDivideZ;
}

void BoundingBoxTestDialog::UpdateDisplay()
{
	_minX = (float)(_dialog->_minXScrollBar->value()) / _scrollDivideX;
	_maxX = (float)(_dialog->_maxXScrollBar->value()) / _scrollDivideX;
	_minY = (float)(_dialog->_minYScrollBar->value()) / _scrollDivideY;
	_maxY = (float)(_dialog->_maxYScrollBar->value()) / _scrollDivideY;
	_minZ = (float)(_dialog->_minZScrollBar->value()) / _scrollDivideZ;
	_maxZ = (float)(_dialog->_maxZScrollBar->value()) / _scrollDivideZ;
	if (_minX >= _maxX)
	{
		//_dialog->_maxXScrollBar->setValue(_dialog->_minXScrollBar->value() + 1);
		//_maxX = _minX + (1 / _scrollDivideX);
		_dialog->_maxXScrollBar->setValue(_scrollDivideX * TypeConversion::QString2Int(_dialog->_maxXLineEdit->text()) * _scrollDivideX);
		_dialog->_minXScrollBar->setValue(_scrollDivideX * TypeConversion::QString2Int(_dialog->_minXLineEdit->text()) * _scrollDivideX);
	}
	if (_minY >= _maxY)
	{
		//_dialog->_maxYScrollBar->setValue(_dialog->_minYScrollBar->value() + 1);
		//_maxY = _minY + (1 / _scrollDivideY);
		_dialog->_maxYScrollBar->setValue(_scrollDivideY * TypeConversion::QString2Int(_dialog->_maxYLineEdit->text()) * _scrollDivideY);
		_dialog->_minYScrollBar->setValue(_scrollDivideY * TypeConversion::QString2Int(_dialog->_minYLineEdit->text()) * _scrollDivideY);
	}
	if (_minZ >= _maxZ)
	{
		//_dialog->_maxZScrollBar->setValue(_dialog->_minZScrollBar->value() + 1);
		//_maxZ = _minZ + (1 / _scrollDivideZ);
		_dialog->_maxZScrollBar->setValue(_scrollDivideZ * TypeConversion::QString2Int(_dialog->_maxZLineEdit->text()) * _scrollDivideZ);
		_dialog->_minZScrollBar->setValue(_scrollDivideZ * TypeConversion::QString2Int(_dialog->_minZLineEdit->text()) * _scrollDivideZ);
	}
	_dialog->_minXLineEdit->setText(QString::number(_minX));
	_dialog->_maxXLineEdit->setText(QString::number(_maxX));
	_dialog->_minYLineEdit->setText(QString::number(_minY));
	_dialog->_maxYLineEdit->setText(QString::number(_maxY));
	_dialog->_minZLineEdit->setText(QString::number(_minZ));
	_dialog->_maxZLineEdit->setText(QString::number(_maxZ));
	_filterProcessing->SetBoundingBox(_minX, _maxX, _minY, _maxY, _minZ, _maxZ);
	if (_cloud == NULL)
		return;
	_filterProcessing->Processing(_cloud->GetPointCloud());
	_filteredCloud = new MyPointCloud(_filterProcessing->GetResult(), _cloud->GetName());
	_filteredCloud->Show(*_viewer);
	_dialog->_qvtkWidget->update();
}

void BoundingBoxTestDialog::EditLineBoundingBoxSlot()
{
	_minX = TypeConversion::QString2Double(_dialog->_minXLineEdit->text());
	_maxX = TypeConversion::QString2Double(_dialog->_maxXLineEdit->text());
	_minY = TypeConversion::QString2Double(_dialog->_minYLineEdit->text());
	_maxY = TypeConversion::QString2Double(_dialog->_maxYLineEdit->text());
	_minZ = TypeConversion::QString2Double(_dialog->_minZLineEdit->text());
	_maxZ = TypeConversion::QString2Double(_dialog->_maxZLineEdit->text());
	if (_minX >= _maxX)
	{
		//_dialog->_maxXScrollBar->setValue(_dialog->_minXScrollBar->value() + 1);
		//_maxX = _minX + (1 / _scrollDivideX);
		_dialog->_minXLineEdit->setText(QString::number(_scrollDivideX * _dialog->_minXScrollBar->value() / _scrollDivideX));
		_dialog->_maxXLineEdit->setText(QString::number(_scrollDivideX * _dialog->_minXScrollBar->value() / _scrollDivideX));
	}
	if (_minY >= _maxY)
	{
		//_dialog->_maxYScrollBar->setValue(_dialog->_minYScrollBar->value() + 1);
		//_maxY = _minY + (1 / _scrollDivideY);
		_dialog->_maxYLineEdit->setText(QString::number(_scrollDivideY * _dialog->_maxYScrollBar->value() / _scrollDivideY));
		_dialog->_minYLineEdit->setText(QString::number(_scrollDivideY * _dialog->_minYScrollBar->value() / _scrollDivideY));
	}
	if (_minZ >= _maxZ)
	{
		//_dialog->_maxZScrollBar->setValue(_dialog->_minZScrollBar->value() + 1);
		//_maxZ = _minZ + (1 / _scrollDivideZ);
		_dialog->_maxZLineEdit->setText(QString::number(_scrollDivideZ * _dialog->_maxZScrollBar->value() / _scrollDivideZ));
		_dialog->_minZLineEdit->setText(QString::number(_scrollDivideZ * _dialog->_minZScrollBar->value() / _scrollDivideZ));
	}
	_dialog->_minXScrollBar->setValue(_minX * _scrollDivideX);
	_dialog->_maxXScrollBar->setValue(_maxX * _scrollDivideX);
	_dialog->_minYScrollBar->setValue(_minY * _scrollDivideY);
	_dialog->_maxYScrollBar->setValue(_maxY * _scrollDivideY);
	_dialog->_minZScrollBar->setValue(_minZ * _scrollDivideZ);
	_dialog->_maxZScrollBar->setValue(_maxZ * _scrollDivideZ);
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
	UpdateDisplay();
}

void BoundingBoxTestDialog::AcceptSlot()
{
	if (_mode == 0)
		emit BoundingBoxTestDialog::TestFinished(_minX, _maxX, _minY, _maxY, _minZ, _maxZ);
	else if (_mode == 1)
		emit BoundingBoxTestDialog::TestKinfuFinished();
	this->close();
}

void BoundingBoxTestDialog::RejectSlot()
{
	this->close();
}