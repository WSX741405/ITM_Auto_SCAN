#ifndef MY_POINT_pointClouds
#define MY_POINT_pointClouds

#include <vector>
#include <pointCloud/MyPointCloud.h>

class MyPointClouds
{
public:
	MyPointClouds()
	{
		_pointClouds = std::vector<MyPointCloud*>();
	}

	void AddPointCloud(pcl::PointCloud<PointT>::Ptr cloud, std::string name = "Name")
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

	std::vector<MyPointCloud*> GetPointCloudsByIsSelected()
	{
		std::vector<MyPointCloud*> outputClouds;
		for (int counter = 0; counter < GetNumberOfPointCloud(); counter++)
		{
			if (_pointClouds[counter]->GetIsSelected())
			{
				outputClouds.push_back(_pointClouds[counter]);
			}
		}
		return outputClouds;
	}

	//	id = 0 ~ size - 1
	std::string GetNameById(int id)
	{
		return _pointClouds[id]->GetName();
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloudById(int id)
	{
		return _pointClouds[id]->GetCloud();
	}

	void SetIsSelectedById(int id, bool isShow)
	{
		_pointClouds[id]->SetIsSelected(isShow);
	}

	bool GetIsSelectedById(int id)
	{
		return _pointClouds[id]->GetIsSelected();
	}

	int GetNumberOfPointCloud()
	{
		return _pointClouds.size();
	}

private:
	std::vector<MyPointCloud*> _pointClouds;
};

#endif