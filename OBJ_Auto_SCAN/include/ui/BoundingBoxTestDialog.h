#ifndef BOUNDING_BOX_TEST_DIALOG
#define BOUNDING_BOX_TEST_DIALOG

#include <QWidget>
#include <QDialog>
#include "ui_BoundingBoxTestDialog.h"
#include "Typedef.h"
#include "ui/viewer.h"
#include "pointCloud/PointCloudElements.h"
#include "pointCloudProcessing/filter/FilterFactory.h"
#include "pointCloudProcessing/filter/FilterProcessing.h"

class BoundingBoxTestDialog : public QDialog
{
	Q_OBJECT
public:
	BoundingBoxTestDialog(FilterProcessing* filter, int mode);
	~BoundingBoxTestDialog();
	void SetPointCloud(PointCloudElement* cloud);
	void SetScrollBarX(double xBarMin, double xBarMax, double xSingleStep, double scrollDivideX);
	void SetScrollBarY(double yBarMin, double yBarMax, double ySingleStep, double scrollDivideY);
	void SetScrollBarZ(double zBarMin, double zBarMax, double zSingleStep, double scrollDivideZ);

signals:
	void TestFinished(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);
	void TestKinfuFinished();

	public slots:
	void SetBoundingBoxSlot();
	void EditLineBoundingBoxSlot();
	void AcceptSlot();
	void RejectSlot();

private:
	void UpdateDisplay();
	void InitialPointCloudViewer();

	float _scrollDivideX = 1000;
	float _scrollDivideY = 1000;
	float _scrollDivideZ = 1000;
	Ui::BoundingBoxTestDialog* _dialog;
	Viewer* _viewer;
	FilterFactory* _filterFactory;
	FilterProcessing* _filterProcessing;
	PointCloudElement* _cloud;
	PointCloudElement* _filteredCloud;

	int _mode;
	float _minX;
	float _maxX;
	float _minY;
	float _maxY;
	float _minZ;
	float _maxZ;
};

#endif