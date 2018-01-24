#include "ui/UIObserver.h"

void UIObserver::Update(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
{
	_mainWindow->UpdateViewer(pointCloud);
}