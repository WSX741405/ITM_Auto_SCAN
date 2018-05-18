#ifndef CURRENT_FRAME_CLOUD_VIEW
#define CURRENT_FRAME_CLOUD_VIEW

#include "kinfuApp/KinfuCommon.h"

struct CurrentFrameCloudView
{
	CurrentFrameCloudView() : cloud_device_(480, 640), cloud_viewer_("Frame Cloud Viewer")
	{
		cloud_ptr_ = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);

		cloud_viewer_.setBackgroundColor(0, 0, 0.15);
		cloud_viewer_.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1);
		cloud_viewer_.addCoordinateSystem(1.0, "global");
		cloud_viewer_.initCameraParameters();
		cloud_viewer_.setPosition(0, 500);
		cloud_viewer_.setSize(640, 480);
		cloud_viewer_.setCameraClipDistances(0.01, 10.01);
	}

	void
		show(const pcl::gpu::KinfuTracker& kinfu)
	{
		kinfu.getLastFrameCloud(cloud_device_);

		int c;
		cloud_device_.download(cloud_ptr_->points, c);
		cloud_ptr_->width = cloud_device_.cols();
		cloud_ptr_->height = cloud_device_.rows();
		cloud_ptr_->is_dense = false;

		cloud_viewer_.removeAllPointClouds();
		cloud_viewer_.addPointCloud<pcl::PointXYZ>(cloud_ptr_);
		cloud_viewer_.spinOnce();
	}

	void
		setViewerPose(const Eigen::Affine3f& viewer_pose) {
		::KinFuAppMethos::setViewerPose(cloud_viewer_, viewer_pose);
	}

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr_;
	pcl::gpu::DeviceArray2D<pcl::PointXYZ> cloud_device_;
	pcl::visualization::PCLVisualizer cloud_viewer_;
};
#endif