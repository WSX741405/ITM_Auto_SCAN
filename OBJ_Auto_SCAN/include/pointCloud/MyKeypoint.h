#ifndef MY_KEYPOINT
#define MY_KEYPOINT

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include "PointCloudElement.h"

#include "ui/Viewer.h"

class MyKeyPoint : public PointCloudElement
{
public:
	MyKeyPoint(pcl::PointCloud<KeypointT>::Ptr cloud, std::string name = "Name")
	{
		_name = name;
		_cloud.reset(new pcl::PointCloud<KeypointT>(*cloud));
		_isSelected = false;		//default
		_r = 255;
		_g = 0;
		_b = 0;
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

	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		pcl::PointCloud<PointT>::Ptr tmpCloud;
		tmpCloud.reset(new pcl::PointCloud<PointT>());
		for (int counter = 0; counter < _cloud->size(); counter++)
		{
			PointT point;
			point.x = _cloud->points[counter].x;
			point.y = _cloud->points[counter].y;
			point.z = _cloud->points[counter].z;

			point.r = _r;
			point.g = _g;
			point.b = _b;
			tmpCloud->push_back(point);
		}
		return tmpCloud;
	}

	pcl::PointCloud<KeypointT>::Ptr GetKeyPoint()
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
	int _r;
	int _g;
	int _b;

	pcl::PointCloud<KeypointT>::Ptr _cloud;
};

#endif