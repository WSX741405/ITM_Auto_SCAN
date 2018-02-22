#ifndef MY_POINT_CLOUDS
#define MY_POINT_CLOUDS

#include <vector>
#include <pointCloud/MyPointCloud.h>

typedef pcl::PointXYZRGBA PointT;

class MyPointClouds
{
public:
	MyPointClouds()
	{
		_pointClouds = std::vector<MyPointCloud*>();
	}

	void AddPointCloud(boost::shared_ptr<pcl::PointCloud<PointT>> cloud, std::string name = "Name")
	{
		MyPointCloud* myCloud = new MyPointCloud(cloud, name);
		_pointClouds.push_back(myCloud);
	}

	bool IsNameExist(std::string name)
	{
		for (int counter = 0; counter < GetNumberOfPointCloud(); counter++)
		{
			if (name == _pointClouds[counter]->GetName())
				return true;
		}
		return false;
	}

	//	id = 0 ~ size - 1
	std::string GetNameById(int id)
	{
		return _pointClouds[id]->GetName();
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloudById(int id)
	{
		return _pointClouds[id]->GetCloud();
	}

	void SetIsShowById(int id, bool isShow)
	{
		_pointClouds[id]->SetIsShow(isShow);
	}

	bool GetIsShowById(int id)
	{
		return _pointClouds[id]->GetIsShow();
	}

	int GetNumberOfPointCloud()
	{
		return _pointClouds.size();
	}

private:
	std::vector<MyPointCloud*> _pointClouds;
};

#endif