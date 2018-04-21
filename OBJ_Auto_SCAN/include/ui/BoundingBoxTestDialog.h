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
	BoundingBoxTestDialog();
	void SetPointCloud(PointCloudElement* cloud);

signals:
	void TestFinished(float minX, float maxX, float minY, float maxY, float minZ, float maxZ);

	public slots:
	void SetBoundingBoxSlot();
	void AcceptSlot();
	void RejectSlot();

private:
	void UpdateLabel();
	void InitialPointCloudViewer();

	float SCROLL_BAR_DIVIDE = 1000;
	Ui::BoundingBoxTestDialog* _dialog;
	Viewer* _viewer;
	FilterFactory* _filterFactory;
	FilterProcessing* _filterProcessing;
	PointCloudElement* _cloud;
	PointCloudElement* _filteredCloud;

	float _minX;
	float _maxX;
	float _minY;
	float _maxY;
	float _minZ;
	float _maxZ;
};

#endif