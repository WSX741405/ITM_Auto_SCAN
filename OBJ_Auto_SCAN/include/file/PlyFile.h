#ifndef PLY_FILE
#define PLY_FILE

#include <pcl/io/io.h>
#include <pcl/io/ply_io.h>
#include "file/3DFile.h";

class PlyFile : ThreeDFile
{
public:
	PlyFile(std::string dir = "") : ThreeDFile(dir)
	{
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		pcl::PLYReader reader;
		reader.read(_dir, *_cloud);
		for (size_t index = 0; index < _cloud->points.size(); index++)
			_cloud->points[index].a = 255;
	}

	void SaveFile(pcl::PointCloud<PointT>::Ptr cloud)
	{
		pcl::PLYWriter writer;
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