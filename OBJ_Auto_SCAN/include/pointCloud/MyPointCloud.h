#ifndef MY_POINT_CLOUD
#define MY_POINT_CLOID

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZRGBA PointT;

class MyPointCloud
{
public:
	MyPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name") : _cloud(cloud), _name(name)
	{
		_isShow = false;		//default
	}

	std::string GetName()
	{
		return _name;
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetCloud()
	{
		return _cloud;
	}

	void SetIsShow(bool isShow)
	{
		_isShow = isShow;
	}

	bool GetIsShow()
	{
		return _isShow;
	}

private:
	std::string _name;
	bool _isShow;	// Display or not
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif