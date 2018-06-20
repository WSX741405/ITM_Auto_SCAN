#ifndef PCD_FILE
#define PCD_FILE

#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include "file/MyFile.h";

class PcdFile : MyFile
{
public:
	PcdFile(std::string dir = "") : MyFile(dir)
	{
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		pcl::PCDReader reader;
		reader.read(_dir, *_cloud);
		for (int counter = 0; counter < _cloud->size(); counter++)
		{
			_cloud->points[counter].r = 255;
			_cloud->points[counter].g = 255;
			_cloud->points[counter].b = 255;
			_cloud->points[counter].a = 255;
		}
	}

	void SaveFile(pcl::PointCloud<PointT>::Ptr cloud)
	{
		pcl::io::savePCDFile(_dir, *cloud, false);
	}

	void SaveFile(pcl::PolygonMeshPtr mesh)
	{
		pcl::io::savePLYFile(_dir, *mesh);
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return _cloud;
	}

private:
	pcl::PointCloud<PointT>::Ptr _cloud;
};

#endif