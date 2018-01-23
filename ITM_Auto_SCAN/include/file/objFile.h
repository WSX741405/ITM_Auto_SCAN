#ifndef OBJ_FILE
#define OBJ_FILE

#include <string>
#include <pcl/TextureMesh.h>
#include <pcl/io/io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>
#include "file/3DFile.h";

class ObjFile : ThreeDFile
{
public:
	ObjFile(std::string dir = "") : ThreeDFile(dir)
	{
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		pcl::OBJReader reader;
		reader.read(_dir, *_cloud);
		for (size_t index = 0; index < _cloud->points.size(); index++)
		{
			_cloud->points[index].r = 255;
			_cloud->points[index].g = 255;
			_cloud->points[index].b = 255;
		}
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetPointCloud()
	{
		return _cloud;
	}

private:
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;
};

#endif