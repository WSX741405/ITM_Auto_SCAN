#ifndef MY_FILE
#define MY_FILE

#include <string>
#include <pcl/io/io.h>

class MyFile
{
public:
	MyFile(std::string dir) : _dir(dir)
	{
	}

	virtual void LoadFile() = 0;
	virtual void SaveFile(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetPointCloud() = 0;
protected:
	std::string _dir;
};

#endif