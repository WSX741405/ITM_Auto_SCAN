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
		for (size_t index = 0; index < _cloud->points.size(); index++)
			_cloud->points[index].a = 255;
	}

	void SaveFile(pcl::PointCloud<PointT>::Ptr cloud)
	{
		pcl::PCDWriter writer;
		writer.write(_dir, *cloud);
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return _cloud;
	}

private:
	pcl::PointCloud<PointT>::Ptr _cloud;
};

#endif