#ifndef THREE_D_FILE
#define THREE_D_FILE

#include <string>
#include <pcl/io/io.h>

class ThreeDFile
{
public:
	ThreeDFile(std::string dir) : _dir(dir)
	{
	}

	virtual void LoadFile() = 0;
	virtual void SaveFile(pcl::PointCloud<PointT>::Ptr cloud) = 0;
	virtual pcl::PointCloud<PointT>::Ptr GetPointCloud() = 0;
protected:
	std::string _dir;
};

#endif