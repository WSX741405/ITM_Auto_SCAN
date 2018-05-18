#ifndef IMAGE_VIEW
#define IMAGE_VIEW

#include "kinfuApp/KinfuCommon.h"

struct ImageView
{
	ImageView(int viz) : viz_(viz), paint_image_(false), accumulate_views_(false)
	{
		if (viz_)
		{
			viewerScene_ = pcl::visualization::ImageViewer::Ptr(new pcl::visualization::ImageViewer);
			viewerDepth_ = pcl::visualization::ImageViewer::Ptr(new pcl::visualization::ImageViewer);

			viewerScene_->setWindowTitle("View3D from ray tracing");
			viewerScene_->setPosition(0, 0);
			viewerDepth_->setWindowTitle("Kinect Depth stream");
			viewerDepth_->setPosition(640, 0);
			//viewerColor_.setWindowTitle ("Kinect RGB stream");
		}
	}

	void
		showScene(pcl::gpu::KinfuTracker& kinfu, const pcl::gpu::PtrStepSz<const pcl::gpu::KinfuTracker::PixelRGB>& rgb24, bool registration, Eigen::Affine3f* pose_ptr = 0)
	{
		if (pose_ptr)
		{
			raycaster_ptr_->run(kinfu.volume(), *pose_ptr);
			raycaster_ptr_->generateSceneView(view_device_);
		}
		else
			kinfu.getImage(view_device_);

		if (paint_image_ && registration && !pose_ptr)
		{
			colors_device_.upload(rgb24.data, rgb24.step, rgb24.rows, rgb24.cols);
			paint3DView(colors_device_, view_device_);
		}


		int cols;
		view_device_.download(view_host_, cols);
		if (viz_)
			viewerScene_->showRGBImage(reinterpret_cast<unsigned char*> (&view_host_[0]), view_device_.cols(), view_device_.rows(), "rgb_image");

		//viewerColor_.showRGBImage ((unsigned char*)&rgb24.data, rgb24.cols, rgb24.rows);

	}

	void
		showDepth(const pcl::gpu::PtrStepSz<const unsigned short>& depth)
	{
		if (viz_)
			viewerDepth_->showShortImage(depth.data, depth.cols, depth.rows, 0, 5000, true, "short_image");
	}

	void
		showGeneratedDepth(pcl::gpu::KinfuTracker& kinfu, const Eigen::Affine3f& pose)
	{
		raycaster_ptr_->run(kinfu.volume(), pose);
		raycaster_ptr_->generateDepthImage(generated_depth_);

		int c;
		std::vector<unsigned short> data;
		generated_depth_.download(data, c);

		if (viz_)
			viewerDepth_->showShortImage(&data[0], generated_depth_.cols(), generated_depth_.rows(), 0, 5000, true, "short_image");
	}

	void
		toggleImagePaint()
	{
		paint_image_ = !paint_image_;
		cout << "Paint image: " << (paint_image_ ? "On   (requires registration mode)" : "Off") << endl;
	}

	int viz_;
	bool paint_image_;
	bool accumulate_views_;

	pcl::visualization::ImageViewer::Ptr viewerScene_;
	pcl::visualization::ImageViewer::Ptr viewerDepth_;
	//visualization::ImageViewer viewerColor_;

	pcl::gpu::KinfuTracker::View view_device_;
	pcl::gpu::KinfuTracker::View colors_device_;
	std::vector<pcl::gpu::KinfuTracker::PixelRGB> view_host_;

	pcl::gpu::RayCaster::Ptr raycaster_ptr_;

	pcl::gpu::KinfuTracker::DepthMap generated_depth_;

};

#endif