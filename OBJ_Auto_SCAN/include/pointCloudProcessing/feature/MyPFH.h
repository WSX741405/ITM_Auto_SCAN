#ifndef MY_PFH
#define MY_PFH

#include "FeatureProcessing.h"

class MyPFH : public FeaturePrcessing
{
public:


private:
	// Object for storing the point cloud.
	pcl::PointCloud<pcl::PointXYZ>::Ptr _cloud(new pcl::PointCloud<pcl::PointXYZ>);
	// Object for storing the normals.
	pcl::PointCloud<pcl::Normal>::Ptr _normals(new pcl::PointCloud<pcl::Normal>);
	// Object for storing the PFH descriptors for each point.
	pcl::PointCloud<pcl::PFHSignature125>::Ptr _descriptors(new pcl::PointCloud<pcl::PFHSignature125>());
};

#endif