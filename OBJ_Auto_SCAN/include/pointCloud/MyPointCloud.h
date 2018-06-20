#ifndef MY_POINT_CLOUD
#define MY_POINT_CLOID

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "PointCloudElement.h"

#include "ui/Viewer.h"

class MyPointCloud : public PointCloudElement
{
public:
	MyPointCloud(pcl::PointCloud<PointT>::Ptr cloud, std::string name = "Name")
	{
		_name = name;
		_cloud.reset(new pcl::PointCloud<PointT>(*cloud));
		_isSelected = false;		//default
	}

	~MyPointCloud()
	{
		_cloud.reset();
	}

	std::string GetName()
	{
		return _name;
	}

	void Show(Viewer& viewer)
	{
		viewer.ShowPointCloud(GetPointCloud(), GetName());
	}

	void Delete(Viewer& viewer)
	{
		viewer.DeletePointCloud(_name);
	}

	void Save(MyFile* file)
	{
		file->SaveFile(_cloud);
	}

	pcl::PointCloud<KeypointT>::Ptr GetKeyPoint()
	{
		return NULL;
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return _cloud;
	}

	pcl::PolygonMeshPtr GetMesh()
	{
		return NULL;
	}

	void SetIsSelected(bool isSelected)
	{
		_isSelected = isSelected;
	}

	bool GetIsSelected()
	{
		return _isSelected;
	}

private:
	pcl::PointCloud<PointT>::Ptr _cloud;
};

#endif