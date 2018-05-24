#ifndef OBJ_FILE
#define OBJ_FILE

#include <string>
#include <pcl/TextureMesh.h>
#include <pcl/io/io.h>
#include <pcl/io/obj_io.h>
#include <pcl/io/vtk_lib_io.h>
#include "file/MyFile.h";

class ObjFile : MyFile
{
public:
	ObjFile(std::string dir = "") : MyFile(dir)
	{
		_cloud.reset(new pcl::PointCloud<PointT>);
	}

	void LoadFile()
	{
		pcl::OBJReader reader;
		reader.read(_dir, *_cloud);
		for (int counter = 0; counter < _cloud->points.size(); counter++)
		{
			_cloud->points[counter].r = 255;
			_cloud->points[counter].g = 255;
			_cloud->points[counter].b = 255;
			_cloud->points[counter].a = 255;
		}
	}

	void SaveFile(pcl::PointCloud<PointT>::Ptr cloud)
	{
		pcl::PolygonMesh mesh;
		toPCLPointCloud2(*cloud, mesh.cloud);
		pcl::io::saveOBJFile(_dir, mesh);
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		return _cloud;
	}

private:
	pcl::PointCloud<PointT>::Ptr _cloud;
};

#endif