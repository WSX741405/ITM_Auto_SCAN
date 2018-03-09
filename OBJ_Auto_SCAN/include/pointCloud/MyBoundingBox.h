#pragma once
#include <pcl/features/moment_of_inertia_estimation.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>

typedef pcl::PointXYZRGBA PointT;

class MyBoundingBox
{
public:
	MyBoundingBox(boost::shared_ptr<pcl::PointCloud<PointT>> cloud)
	{
		_cloud = cloud;
	}

	void ProcessBoundingBox()
	{
		pcl::MomentOfInertiaEstimation <PointT> feature_extractor;
		feature_extractor.setInputCloud(_cloud);
		feature_extractor.compute();

		PointT position_OBB;

		std::vector <float> moment_of_inertia;
		std::vector <float> eccentricity;
		
		Eigen::Matrix3f rotational_matrix_OBB;
		float major_value, middle_value, minor_value;
		Eigen::Vector3f major_vector, middle_vector, minor_vector;
		Eigen::Vector3f mass_center;

		feature_extractor.getMomentOfInertia(moment_of_inertia);
		feature_extractor.getEccentricity(eccentricity);
		feature_extractor.getAABB(_min_point_AABB, _max_point_AABB);
		feature_extractor.getOBB(_min_point_OBB, _max_point_OBB, position_OBB, rotational_matrix_OBB);
		feature_extractor.getEigenValues(major_value, middle_value, minor_value);
		feature_extractor.getEigenVectors(major_vector, middle_vector, minor_vector);
		feature_extractor.getMassCenter(mass_center);
		_position = Eigen::Vector3f(position_OBB.x, position_OBB.y, position_OBB.z);
		_quat = Eigen::Quaternionf(rotational_matrix_OBB);
		/*
		boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer(new pcl::visualization::PCLVisualizer("3D Viewer"));
		viewer->setBackgroundColor(0, 0, 0);
		viewer->addCoordinateSystem(1.0);
		viewer->initCameraParameters();
		viewer->addPointCloud<pcl::PointT>(cloud, "sample cloud");
		viewer->addCube(min_point_AABB.x, max_point_AABB.x, min_point_AABB.y, max_point_AABB.y, min_point_AABB.z, max_point_AABB.z, 1.0, 1.0, 0.0, "AABB");
		*/
		//viewer->addCube(position, quat, max_point_OBB.x - min_point_OBB.x, max_point_OBB.y - min_point_OBB.y, max_point_OBB.z - min_point_OBB.z, "OBB");
	}

private:
	boost::shared_ptr<pcl::PointCloud<PointT>> _cloud;

	PointT _min_point_AABB;
	PointT _max_point_AABB;
	PointT _min_point_OBB;
	PointT _max_point_OBB;

	Eigen::Vector3f _position;
	Eigen::Quaternionf _quat;
};