#ifndef MY_POINT_CLOUD
#define MY_POINT_CLOID

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class MyPointCloud
{
public:
	MyPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name") : _name(name)
	{
		_cloud.reset(new pcl::PointCloud<PointT>(*cloud));
		_isSelected = false;		//default
	}

	std::string GetName()
	{
		return _name;
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetCloud()
	{
		return _cloud;
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
	std::string _name;
	bool _isSelected;
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif