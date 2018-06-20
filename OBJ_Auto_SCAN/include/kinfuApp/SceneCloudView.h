#ifndef SCENE_CLOUD_VIEW
#define SCENE_CLOUD_VIEW

#include "kinfuApp/KinfuCommon.h"

struct SceneCloudView
{
	enum { GPU_Connected6 = 0, CPU_Connected6 = 1, CPU_Connected26 = 2 };

	SceneCloudView(int viz) : viz_(viz), extraction_mode_(GPU_Connected6), compute_normals_(false), valid_combined_(false), cube_added_(false)
	{
		cloud_ptr_ = pcl::PointCloud<pcl::PointXYZ>::Ptr(new pcl::PointCloud<pcl::PointXYZ>);
		normals_ptr_ = pcl::PointCloud<pcl::Normal>::Ptr(new pcl::PointCloud<pcl::Normal>);
		combined_ptr_ = pcl::PointCloud<pcl::PointNormal>::Ptr(new pcl::PointCloud<pcl::PointNormal>);
		point_colors_ptr_ = pcl::PointCloud<pcl::RGB>::Ptr(new pcl::PointCloud<pcl::RGB>);

		if (viz_)
		{
			cloud_viewer_ = pcl::visualization::PCLVisualizer::Ptr(new pcl::visualization::PCLVisualizer("Scene Cloud Viewer"));

			cloud_viewer_->setBackgroundColor(0, 0, 0);
			cloud_viewer_->addCoordinateSystem(1.0, "global");
			cloud_viewer_->initCameraParameters();
			cloud_viewer_->setPosition(0, 500);
			cloud_viewer_->setSize(640, 480);
			cloud_viewer_->setCameraClipDistances(0.01, 10.01);

			cloud_viewer_->addText("H: print help", 2, 15, 20, 34, 135, 246);
		}
	}

	void
		show(pcl::gpu::KinfuTracker& kinfu, bool integrate_colors)
	{
		viewer_pose_ = kinfu.getCameraPose();

		ScopeTimeT time("PointCloud Extraction");

		valid_combined_ = false;

		if (extraction_mode_ != GPU_Connected6)     // So use CPU
		{
			kinfu.volume().fetchCloudHost(*cloud_ptr_, extraction_mode_ == CPU_Connected26);
		}
		else
		{
			pcl::gpu::DeviceArray<pcl::PointXYZ> extracted = kinfu.volume().fetchCloud(cloud_buffer_device_);

			if (compute_normals_)
			{
				kinfu.volume().fetchNormals(extracted, normals_device_);
				pcl::gpu::mergePointNormal(extracted, normals_device_, combined_device_);
				combined_device_.download(combined_ptr_->points);
				combined_ptr_->width = (int)combined_ptr_->points.size();
				combined_ptr_->height = 1;

				valid_combined_ = true;
			}
			else
			{
				extracted.download(cloud_ptr_->points);
				cloud_ptr_->width = (int)cloud_ptr_->points.size();
				cloud_ptr_->height = 1;
			}

			if (integrate_colors)
			{
				kinfu.colorVolume().fetchColors(extracted, point_colors_device_);
				point_colors_device_.download(point_colors_ptr_->points);
				point_colors_ptr_->width = (int)point_colors_ptr_->points.size();
				point_colors_ptr_->height = 1;
			}
			else
				point_colors_ptr_->points.clear();
		}
		size_t points_size = valid_combined_ ? combined_ptr_->points.size() : cloud_ptr_->points.size();
		cout << "Done.  Cloud size: " << points_size / 1000 << "K" << endl;

		if (viz_)
		{
			cloud_viewer_->removeAllPointClouds();
			if (valid_combined_)
			{
				pcl::visualization::PointCloudColorHandlerRGBCloud<pcl::PointNormal> rgb(combined_ptr_, point_colors_ptr_);
				cloud_viewer_->addPointCloud<pcl::PointNormal>(combined_ptr_, rgb, "Cloud");
				cloud_viewer_->addPointCloudNormals<pcl::PointNormal>(combined_ptr_, 50);
			}
			else
			{
				pcl::visualization::PointCloudColorHandlerRGBCloud<pcl::PointXYZ> rgb(cloud_ptr_, point_colors_ptr_);
				cloud_viewer_->addPointCloud<pcl::PointXYZ>(cloud_ptr_, rgb);
			}
		}
	}

	void
		toggleCube(const Eigen::Vector3f& size)
	{
		if (!viz_)
			return;

		if (cube_added_)
			cloud_viewer_->removeShape("cube");
		else
			cloud_viewer_->addCube(size*0.5, Eigen::Quaternionf::Identity(), size(0), size(1), size(2));
		

		cube_added_ = !cube_added_;
	}

	void
		toggleExtractionMode()
	{
		extraction_mode_ = (extraction_mode_ + 1) % 3;

		switch (extraction_mode_)
		{
		case 0: cout << "Cloud exctraction mode: GPU, Connected-6" << endl; break;
		case 1: cout << "Cloud exctraction mode: CPU, Connected-6    (requires a lot of memory)" << endl; break;
		case 2: cout << "Cloud exctraction mode: CPU, Connected-26   (requires a lot of memory)" << endl; break;
		}
		;
	}

	void
		toggleNormals()
	{
		compute_normals_ = !compute_normals_;
		cout << "Compute normals: " << (compute_normals_ ? "On" : "Off") << endl;
	}

	void
		clearClouds(bool print_message = false)
	{
		if (!viz_)
			return;

		cloud_viewer_->removeAllPointClouds();
		cloud_ptr_->points.clear();
		normals_ptr_->points.clear();
		if (print_message)
			cout << "Clouds/Meshes were cleared" << endl;
	}

	void
		showMesh(pcl::gpu::KinfuTracker& kinfu, bool /*integrate_colors*/)
	{
		if (!marching_cubes_)
			marching_cubes_ = pcl::gpu::MarchingCubes::Ptr(new pcl::gpu::MarchingCubes());

		pcl::gpu::DeviceArray<pcl::PointXYZ> triangles_device = marching_cubes_->run(kinfu.volume(), triangles_buffer_device_);
		mesh_ptr_ = KinFuAppMethos::convertToMesh(triangles_device);

		cout << "Done.  Triangles number: " << triangles_device.size() / pcl::gpu::MarchingCubes::POINTS_PER_TRIANGLE / 1000 << "K" << endl;

		if (!viz_)
			return;

		ScopeTimeT time("Mesh Extraction");

		cloud_viewer_->removeAllPointClouds();
		if (mesh_ptr_)
			cloud_viewer_->addPolygonMesh(*mesh_ptr_);
	}

	int viz_;
	int extraction_mode_;
	bool compute_normals_;
	bool valid_combined_;
	bool cube_added_;

	Eigen::Affine3f viewer_pose_;

	pcl::visualization::PCLVisualizer::Ptr cloud_viewer_;

	pcl::PointCloud<pcl::PointXYZ > ::Ptr cloud_ptr_;
	pcl::PointCloud<pcl::Normal>::Ptr normals_ptr_;

	pcl::gpu::DeviceArray<pcl::PointXYZ> cloud_buffer_device_;
	pcl::gpu::DeviceArray<pcl::Normal> normals_device_;

	pcl::PointCloud<pcl::PointNormal>::Ptr combined_ptr_;
	pcl::gpu::DeviceArray<pcl::PointNormal> combined_device_;

	pcl::gpu::DeviceArray<pcl::RGB> point_colors_device_;
	pcl::PointCloud<pcl::RGB>::Ptr point_colors_ptr_;

	pcl::gpu::MarchingCubes::Ptr marching_cubes_;
	pcl::gpu::DeviceArray<pcl::PointXYZ> triangles_buffer_device_;

	boost::shared_ptr<pcl::PolygonMesh> mesh_ptr_;
};
#endif