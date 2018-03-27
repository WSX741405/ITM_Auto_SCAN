#ifndef MY_PFH
#define MY_PFH

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "FeatureProcessing.h"

class MyPFH : public FeatureProcessing
{
public:


private:
	// Object for storing the point cloud.
	pcl::PointCloud<PointT>::Ptr _cloud;
	// Object for storing the normals.
	pcl::PointCloud<pcl::Normal>::Ptr _normals;
	// Object for storing the PFH descriptors for each point.
	pcl::PointCloud<pcl::PFHSignature125>::Ptr _descriptors;
};

#endif