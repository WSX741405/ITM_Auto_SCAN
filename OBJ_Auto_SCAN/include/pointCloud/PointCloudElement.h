#ifndef POINT_CLOUD_ELEMENT
#define POINT_CLOUD_ELEMENT

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZI KeypointT;

#include "ui/Viewer.h"

class PointCloudElement
{
public:
	virtual std::string GetName() = 0;
	virtual void SetIsSelected(bool isSelected) = 0;
	virtual bool GetIsSelected() = 0;
	virtual void Show(Viewer& viewer) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetPointCloud() = 0;

protected:
	std::string _name;
	bool _isSelected;
};

#endif