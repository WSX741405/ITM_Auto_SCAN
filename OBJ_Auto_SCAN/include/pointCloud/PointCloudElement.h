#ifndef POINT_CLOUD_ELEMENT
#define POINT_CLOUD_ELEMENT

#include "ui/Viewer.h"
#include "file/MyFile.h"

class PointCloudElement
{
public:
	virtual std::string GetName() = 0;
	virtual void SetIsSelected(bool isSelected) = 0;
	virtual bool GetIsSelected() = 0;
	virtual void Show(Viewer& viewer) = 0;
	virtual void Delete(Viewer& viewer) = 0;
	virtual void Save(MyFile* file) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetPointCloud() = 0;
	virtual pcl::PolygonMeshPtr GetMesh() = 0;
	virtual pcl::PointCloud<KeypointT>::Ptr GetKeyPoint() = 0;

protected:
	std::string _name;
	bool _isSelected;
};

#endif