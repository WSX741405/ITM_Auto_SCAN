#ifndef KINFU_APP
#define KINFU_APP

#include "Typedef.h"
#include "kinfuApp/KinfuCommon.h"

#include "kinfuApp/SampledScopeTime.h"
#include "kinfuApp/ImageView.h"
#include "kinfuApp/SceneCloudView.h"
#include "kinfuApp/CurrentFrameCloudView.h"

struct KinFuApp
{
	enum { PCD_BIN = 1, PCD_ASCII = 2, PLY = 3, MESH_PLY = 7, MESH_VTK = 8 };

	KinFuApp(float vsz, int icp, int viz, boost::shared_ptr<CameraPoseProcessor> pose_processor = boost::shared_ptr<CameraPoseProcessor>()) : exit_(false), scan_(false), scan_mesh_(false), scan_volume_(false), independent_camera_(false),
		registration_(false), integrate_colors_(false), pcd_source_(false), focal_length_(-1.f), scene_cloud_view_(viz), image_view_(viz), time_ms_(0), icp_(icp), viz_(viz), pose_processor_(pose_processor)
	{
		//Init Kinfu Tracker
		Eigen::Vector3f volume_size = Eigen::Vector3f::Constant(vsz/*meters*/);
		kinfu_.volume().setSize(volume_size);

		Eigen::Matrix3f R = Eigen::Matrix3f::Identity();   // * AngleAxisf( pcl::deg2rad(-30.f), Vector3f::UnitX());
		Eigen::Vector3f t = volume_size * 0.5f - Eigen::Vector3f(0, 0, volume_size(2) / 2 * 1.2f);

		Eigen::Affine3f pose = Eigen::Translation3f(t) * Eigen::AngleAxisf(R);

		kinfu_.setInitalCameraPose(pose);
		kinfu_.volume().setTsdfTruncDist(0.030f/*meters*/);
		kinfu_.setIcpCorespFilteringParams(0.1f/*meters*/, sin(pcl::deg2rad(20.f)));
		//kinfu_.setDepthTruncationForICP(5.f/*meters*/);
		kinfu_.setCameraMovementThreshold(0.001f);

		if (!icp)
			kinfu_.disableIcp();

		//Init KinfuApp            
		tsdf_cloud_ptr_ = pcl::PointCloud<pcl::PointXYZI>::Ptr(new pcl::PointCloud<pcl::PointXYZI>);
		image_view_.raycaster_ptr_ = pcl::gpu::RayCaster::Ptr(new pcl::gpu::RayCaster(kinfu_.rows(), kinfu_.cols()));

		if (viz_)
		{
			scene_cloud_view_.cloud_viewer_->registerKeyboardCallback(keyboard_callback, (void*)this);
			image_view_.viewerScene_->registerKeyboardCallback(keyboard_callback, (void*)this);
			image_view_.viewerDepth_->registerKeyboardCallback(keyboard_callback, (void*)this);

			scene_cloud_view_.toggleCube(volume_size);
		}
	}

	~KinFuApp()
	{
		//if (evaluation_ptr_)
			//evaluation_ptr_->saveAllPoses(kinfu_);
	}

	void initCurrentFrameView()
	{
		current_frame_cloud_view_ = boost::shared_ptr<CurrentFrameCloudView>(new CurrentFrameCloudView());
		current_frame_cloud_view_->cloud_viewer_.registerKeyboardCallback(keyboard_callback, (void*)this);
		current_frame_cloud_view_->setViewerPose(kinfu_.getCameraPose());
	}
	/*
	void initRegistration()
	{
		registration_ = capture_.providesCallback<pcl::ONIGrabber::sig_cb_openni_image_depth_image>();
		cout << "Registration mode: " << (registration_ ? "On" : "Off (not supported by source)") << endl;
		if (registration_)
			kinfu_.setDepthIntrinsics(KINFU_DEFAULT_RGB_FOCAL_X, KINFU_DEFAULT_RGB_FOCAL_Y);
	}
	*/
	void setDepthIntrinsics(std::vector<float> depth_intrinsics)
	{
		float fx = depth_intrinsics[0];
		float fy = depth_intrinsics[1];

		if (depth_intrinsics.size() == 4)
		{
			float cx = depth_intrinsics[2];
			float cy = depth_intrinsics[3];
			kinfu_.setDepthIntrinsics(fx, fy, cx, cy);
			cout << "Depth intrinsics changed to fx=" << fx << " fy=" << fy << " cx=" << cx << " cy=" << cy << endl;
		}
		else {
			kinfu_.setDepthIntrinsics(fx, fy);
			cout << "Depth intrinsics changed to fx=" << fx << " fy=" << fy << endl;
		}
	}

	void toggleColorIntegration()
	{
		if (registration_)
		{
			const int max_color_integration_weight = 2;
			kinfu_.initColorIntegration(max_color_integration_weight);
			integrate_colors_ = true;
		}
		cout << "Color integration: " << (integrate_colors_ ? "On" : "Off ( requires registration mode )") << endl;
	}

	void enableTruncationScaling()
	{
		kinfu_.volume().setTsdfTruncDist(kinfu_.volume().getSize()(0) / 100.0f);
	}

	void toggleIndependentCamera()
	{
		independent_camera_ = !independent_camera_;
		cout << "Camera mode: " << (independent_camera_ ? "Independent" : "Bound to Kinect pose") << endl;
	}

	void toggleEvaluationMode(const std::string& eval_folder, const std::string& match_file = std::string())
	{
		evaluation_ptr_ = Evaluation::Ptr(new Evaluation(eval_folder));
		if (!match_file.empty())
			evaluation_ptr_->setMatchFile(match_file);

		kinfu_.setDepthIntrinsics(evaluation_ptr_->fx, evaluation_ptr_->fy, evaluation_ptr_->cx, evaluation_ptr_->cy);
		image_view_.raycaster_ptr_ = pcl::gpu::RayCaster::Ptr(new pcl::gpu::RayCaster(kinfu_.rows(), kinfu_.cols(),
			evaluation_ptr_->fx, evaluation_ptr_->fy, evaluation_ptr_->cx, evaluation_ptr_->cy));
	}

	void execute()
	{
		bool has_image = false;

		//if (has_data)
		{
			depth_device_.upload(depth_.data, depth_.step, depth_.rows, depth_.cols);
			if (integrate_colors_)
				image_view_.colors_device_.upload(rgb24_.data, rgb24_.step, rgb24_.rows, rgb24_.cols);

			{
				//SampledScopeTime fps(time_ms_);

				//run kinfu algorithm
				if (integrate_colors_)
					has_image = kinfu_(depth_device_, image_view_.colors_device_);
				else
					has_image = kinfu_(depth_device_);
				if (has_image)
					std::cout << "true" << std::endl;
				else
					std::cout << "fasle" << std::endl;
			}

			// process camera pose
			if (pose_processor_)
			{
				pose_processor_->processPose(kinfu_.getCameraPose());
			}

			image_view_.showDepth(depth_);
			//image_view_.showGeneratedDepth(kinfu_, kinfu_.getCameraPose());
		}

		if (scan_)
		{
			scan_ = false;
			scene_cloud_view_.show(kinfu_, integrate_colors_);

			if (scan_volume_)
			{
				cout << "Downloading TSDF volume from device ... " << std::flush;
				kinfu_.volume().downloadTsdfAndWeighs(tsdf_volume_.volumeWriteable(), tsdf_volume_.weightsWriteable());
				tsdf_volume_.setHeader(Eigen::Vector3i(pcl::device::VOLUME_X, pcl::device::VOLUME_Y, pcl::device::VOLUME_Z), kinfu_.volume().getSize());
				cout << "done [" << tsdf_volume_.size() << " voxels]" << endl << endl;

				cout << "Converting volume to TSDF cloud ... " << std::flush;
				tsdf_volume_.convertToTsdfCloud(tsdf_cloud_ptr_);
				cout << "done [" << tsdf_cloud_ptr_->size() << " points]" << endl << endl;
			}
			else
				cout << "[!] tsdf volume download is disabled" << endl << endl;
		}

		if (scan_mesh_)
		{
			scan_mesh_ = false;
			scene_cloud_view_.showMesh(kinfu_, integrate_colors_);
		}

		if (viz_)
		{
			Eigen::Affine3f viewer_pose = KinFuAppMethos::getViewerPose(*scene_cloud_view_.cloud_viewer_);
			image_view_.showScene(kinfu_, rgb24_, registration_, independent_camera_ ? &viewer_pose : 0);
		}

		if (current_frame_cloud_view_)
			current_frame_cloud_view_->show(kinfu_);

		if (viz_ && !independent_camera_)
			KinFuAppMethos::setViewerPose(*scene_cloud_view_.cloud_viewer_, kinfu_.getCameraPose());
	}
	/*
	void source_cb1_device(const boost::shared_ptr<openni_wrapper::DepthImage>& depth_wrapper)
	{
		{
			boost::mutex::scoped_try_lock lock(data_ready_mutex_);
			if (exit_ || !lock)
				return;

			depth_.cols = depth_wrapper->getWidth();
			depth_.rows = depth_wrapper->getHeight();
			depth_.step = depth_.cols * depth_.elemSize();

			source_depth_data_.resize(depth_.cols * depth_.rows);
			depth_wrapper->fillDepthImageRaw(depth_.cols, depth_.rows, &source_depth_data_[0]);
			depth_.data = &source_depth_data_[0];
		}
		data_ready_cond_.notify_one();
	}

	void source_cb2_device(const boost::shared_ptr<openni_wrapper::Image>& image_wrapper, const boost::shared_ptr<openni_wrapper::DepthImage>& depth_wrapper, float)
	{
		{
			boost::mutex::scoped_try_lock lock(data_ready_mutex_);
			if (exit_ || !lock)
				return;

			depth_.cols = depth_wrapper->getWidth();
			depth_.rows = depth_wrapper->getHeight();
			depth_.step = depth_.cols * depth_.elemSize();

			source_depth_data_.resize(depth_.cols * depth_.rows);
			depth_wrapper->fillDepthImageRaw(depth_.cols, depth_.rows, &source_depth_data_[0]);
			depth_.data = &source_depth_data_[0];

			rgb24_.cols = image_wrapper->getWidth();
			rgb24_.rows = image_wrapper->getHeight();
			rgb24_.step = rgb24_.cols * rgb24_.elemSize();

			source_image_data_.resize(rgb24_.cols * rgb24_.rows);
			image_wrapper->fillRGB(rgb24_.cols, rgb24_.rows, (unsigned char*)&source_image_data_[0]);
			rgb24_.data = &source_image_data_[0];
		}
		data_ready_cond_.notify_one();
	}


	void source_cb1_oni(const boost::shared_ptr<openni_wrapper::DepthImage>& depth_wrapper)
	{
		{
			boost::mutex::scoped_lock lock(data_ready_mutex_);
			if (exit_)
				return;

			depth_.cols = depth_wrapper->getWidth();
			depth_.rows = depth_wrapper->getHeight();
			depth_.step = depth_.cols * depth_.elemSize();

			source_depth_data_.resize(depth_.cols * depth_.rows);
			depth_wrapper->fillDepthImageRaw(depth_.cols, depth_.rows, &source_depth_data_[0]);
			depth_.data = &source_depth_data_[0];
		}
		data_ready_cond_.notify_one();
	}

	void source_cb2_oni(const boost::shared_ptr<openni_wrapper::Image>& image_wrapper, const boost::shared_ptr<openni_wrapper::DepthImage>& depth_wrapper, float)
	{
		{
			boost::mutex::scoped_lock lock(data_ready_mutex_);
			if (exit_)
				return;

			depth_.cols = depth_wrapper->getWidth();
			depth_.rows = depth_wrapper->getHeight();
			depth_.step = depth_.cols * depth_.elemSize();

			source_depth_data_.resize(depth_.cols * depth_.rows);
			depth_wrapper->fillDepthImageRaw(depth_.cols, depth_.rows, &source_depth_data_[0]);
			depth_.data = &source_depth_data_[0];

			rgb24_.cols = image_wrapper->getWidth();
			rgb24_.rows = image_wrapper->getHeight();
			rgb24_.step = rgb24_.cols * rgb24_.elemSize();

			source_image_data_.resize(rgb24_.cols * rgb24_.rows);
			image_wrapper->fillRGB(rgb24_.cols, rgb24_.rows, (unsigned char*)&source_image_data_[0]);
			rgb24_.data = &source_image_data_[0];
		}
		data_ready_cond_.notify_one();
	}
	*/

	void source_cb3(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr & DC3)
	{
		{
			/*
			boost::mutex::scoped_try_lock lock(data_ready_mutex_);
			if (exit_ || !lock)
				return;
				*/
			int width = DC3->width;
			int height = DC3->height;
			depth_.cols = width;
			depth_.rows = height;
			depth_.step = depth_.cols * depth_.elemSize();
			source_depth_data_.resize(depth_.cols * depth_.rows);

			rgb24_.cols = width;
			rgb24_.rows = height;
			rgb24_.step = rgb24_.cols * rgb24_.elemSize();
			source_image_data_.resize(rgb24_.cols * rgb24_.rows);

			unsigned char *rgb = (unsigned char *)&source_image_data_[0];
			unsigned short *depth = (unsigned short *)&source_depth_data_[0];

			for (int i = 0; i < width*height; i++)
			{
				pcl::PointXYZRGB pt = DC3->at(i);
				rgb[3 * i + 0] = pt.r;
				rgb[3 * i + 1] = pt.g;
				rgb[3 * i + 2] = pt.b;
				depth[i] = pt.z / 0.001;
			}
			rgb24_.data = &source_image_data_[0];
			depth_.data = &source_depth_data_[0];
		}
		//data_ready_cond_.notify_one();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void startMainLoop()
	{
		/*
		using namespace openni_wrapper;
		typedef boost::shared_ptr<DepthImage> DepthImagePtr;
		typedef boost::shared_ptr<Image> ImagePtr;

		boost::function<void(const ImagePtr&, const DepthImagePtr&, float constant)> func1_dev = boost::bind(&KinFuApp::source_cb2_device, this, _1, _2, _3);
		boost::function<void(const DepthImagePtr&)> func2_dev = boost::bind(&KinFuApp::source_cb1_device, this, _1);

		boost::function<void(const ImagePtr&, const DepthImagePtr&, float constant)> func1_oni = boost::bind(&KinFuApp::source_cb2_oni, this, _1, _2, _3);
		boost::function<void(const DepthImagePtr&)> func2_oni = boost::bind(&KinFuApp::source_cb1_oni, this, _1);

		bool is_oni = dynamic_cast<pcl::ONIGrabber*>(&capture_) != 0;
		boost::function<void(const ImagePtr&, const DepthImagePtr&, float constant)> func1 = is_oni ? func1_oni : func1_dev;
		boost::function<void(const DepthImagePtr&)> func2 = is_oni ? func2_oni : func2_dev;

		boost::function<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&) > func3 = boost::bind(&KinFuApp::source_cb3, this, _1);

		bool need_colors = integrate_colors_ || registration_;
		if (pcd_source_ && !capture_.providesCallback<void(const pcl::PointCloud<pcl::PointXYZRGBA>::ConstPtr&)>())
		{
			std::cout << "grabber doesn't provide pcl::PointCloud<pcl::PointXYZRGBA> callback !\n";
		}
		boost::signals2::connection c = pcd_source_ ? capture_.registerCallback(func3) : need_colors ? capture_.registerCallback(func1) : capture_.registerCallback(func2);
		*/
		{
			boost::unique_lock<boost::mutex> lock(data_ready_mutex_);
			/*
			if (!triggered_capture)
				capture_.start(); // Start stream
			*/
			bool scene_view_not_stopped = viz_ ? !scene_cloud_view_.cloud_viewer_->wasStopped() : true;
			bool image_view_not_stopped = viz_ ? !image_view_.viewerScene_->wasStopped() : true;

			while (!exit_ && scene_view_not_stopped && image_view_not_stopped)
			{
				/*
				if (triggered_capture)
					capture_.start(); // Triggers new frame
					*/
				bool has_data = data_ready_cond_.timed_wait(lock, boost::posix_time::millisec(100));

				try { this->execute(); }
				catch (const std::bad_alloc& /*e*/) { cout << "Bad alloc" << endl; break; }
				catch (const std::exception& /*e*/) { cout << "Exception" << endl; break; }

				if (viz_)
					scene_cloud_view_.cloud_viewer_->spinOnce(3);
			}
			/*
			if (!triggered_capture)
				capture_.stop(); // Stop stream
				*/
		}
		//c.disconnect();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	template<typename CloudPtr>
	void writeCloudFile(int format, const CloudPtr& cloud_prt)
	{
		if (format == KinFuApp::PCD_BIN)
		{
			cout << "Saving point cloud to 'cloud_bin.pcd' (binary)... " << std::flush;
			pcl::io::savePCDFile("cloud_bin.pcd", *cloud_prt, true);
		}
		else
			if (format == KinFuApp::PCD_ASCII)
			{
				cout << "Saving point cloud to 'cloud.pcd' (ASCII)... " << std::flush;
				pcl::io::savePCDFile("cloud.pcd", *cloud_prt, false);
			}
			else   /* if (format == KinFuApp::PLY) */
			{
				cout << "Saving point cloud to 'cloud.ply' (ASCII)... " << std::flush;
				pcl::io::savePLYFileASCII("cloud.ply", *cloud_prt);

			}
		cout << "Done" << endl;
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	void writePolygonMeshFile(int format, const pcl::PolygonMesh& mesh)
	{
		if (format == KinFuApp::MESH_PLY)
		{
			cout << "Saving mesh to to 'mesh.ply'... " << std::flush;
			pcl::io::savePLYFile("mesh.ply", mesh);
		}
		else /* if (format == KinFuApp::MESH_VTK) */
		{
			cout << "Saving mesh to to 'mesh.vtk'... " << std::flush;
			pcl::io::saveVTKFile("mesh.vtk", mesh);
		}
		cout << "Done" << endl;
	}

	void writeCloud(int format)
	{
		const SceneCloudView& view = scene_cloud_view_;

		// Points to export are either in cloud_ptr_ or combined_ptr_.
		// If none have points, we have nothing to export.
		if (view.cloud_ptr_->points.empty() && view.combined_ptr_->points.empty())
		{
			cout << "Not writing cloud: Cloud is empty" << endl;
		}
		else
		{
			if (view.point_colors_ptr_->points.empty()) // no colors
			{
				if (view.valid_combined_)
					writeCloudFile(format, view.combined_ptr_);
				else
					writeCloudFile(format, view.cloud_ptr_);
			}
			else
			{
				if (view.valid_combined_)
					writeCloudFile(format, KinFuAppMethos::merge<pcl::PointXYZRGBNormal>(*view.combined_ptr_, *view.point_colors_ptr_));
				else
					writeCloudFile(format, KinFuAppMethos::merge<pcl::PointXYZRGB>(*view.cloud_ptr_, *view.point_colors_ptr_));
			}
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void writeMesh(int format)
	{
		if (scene_cloud_view_.mesh_ptr_)
			writePolygonMeshFile(format, *scene_cloud_view_.mesh_ptr_);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void printHelp()
	{
		cout << endl;
		cout << "KinFu app hotkeys" << endl;
		cout << "=================" << endl;
		cout << "    H    : print this help" << endl;
		cout << "   Esc   : exit" << endl;
		cout << "    T    : take cloud" << endl;
		cout << "    A    : take mesh" << endl;
		cout << "    M    : toggle cloud exctraction mode" << endl;
		cout << "    N    : toggle normals exctraction" << endl;
		cout << "    I    : toggle independent camera mode" << endl;
		cout << "    B    : toggle volume bounds" << endl;
		cout << "    *    : toggle scene view painting ( requires registration mode )" << endl;
		cout << "    C    : clear clouds" << endl;
		cout << "   1,2,3 : save cloud to PCD(binary), PCD(ASCII), PLY(ASCII)" << endl;
		cout << "    7,8  : save mesh to PLY, VTK" << endl;
		cout << "   X, V  : TSDF volume utility" << endl;
		cout << endl;
	}

	bool exit_;
	bool scan_;
	bool scan_mesh_;
	bool scan_volume_;

	bool independent_camera_;

	bool registration_;
	bool integrate_colors_;
	bool pcd_source_;
	float focal_length_;

	//pcl::Grabber& capture_;
	pcl::gpu::KinfuTracker kinfu_;

	SceneCloudView scene_cloud_view_;
	ImageView image_view_;
	boost::shared_ptr<CurrentFrameCloudView> current_frame_cloud_view_;

	pcl::gpu::KinfuTracker::DepthMap depth_device_;

	pcl::TSDFVolume<float, short> tsdf_volume_;
	pcl::PointCloud<pcl::PointXYZI>::Ptr tsdf_cloud_ptr_;

	Evaluation::Ptr evaluation_ptr_;

	boost::mutex data_ready_mutex_;
	boost::condition_variable data_ready_cond_;

	std::vector<pcl::gpu::KinfuTracker::PixelRGB> source_image_data_;
	std::vector<unsigned short> source_depth_data_;
	pcl::gpu::PtrStepSz<const unsigned short> depth_;
	pcl::gpu::PtrStepSz<const pcl::gpu::KinfuTracker::PixelRGB> rgb24_;

	int time_ms_;
	int icp_, viz_;

	boost::shared_ptr<CameraPoseProcessor> pose_processor_;

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	static void keyboard_callback(const pcl::visualization::KeyboardEvent &e, void *cookie)
	{
		KinFuApp* app = reinterpret_cast<KinFuApp*> (cookie);

		int key = e.getKeyCode();

		if (e.keyUp())
			switch (key)
			{
			case 27: app->exit_ = true; break;
			case (int)'t': case (int)'T': app->scan_ = true; break;
			case (int)'a': case (int)'A': app->scan_mesh_ = true; break;
			case (int)'h': case (int)'H': app->printHelp(); break;
			case (int)'m': case (int)'M': app->scene_cloud_view_.toggleExtractionMode(); break;
			case (int)'n': case (int)'N': app->scene_cloud_view_.toggleNormals(); break;
			case (int)'c': case (int)'C': app->scene_cloud_view_.clearClouds(true); break;
			case (int)'i': case (int)'I': app->toggleIndependentCamera(); break;
			case (int)'b': case (int)'B': app->scene_cloud_view_.toggleCube(app->kinfu_.volume().getSize()); break;
			case (int)'7': case (int)'8': app->writeMesh(key - (int)'0'); break;
			case (int)'1': case (int)'2': case (int)'3': app->writeCloud(key - (int)'0'); break;
			case '*': app->image_view_.toggleImagePaint(); break;

			case (int)'x': case (int)'X':
				app->scan_volume_ = !app->scan_volume_;
				cout << endl << "Volume scan: " << (app->scan_volume_ ? "enabled" : "disabled") << endl << endl;
				break;
			case (int)'v': case (int)'V':
				cout << "Saving TSDF volume to tsdf_volume.dat ... " << std::flush;
				app->tsdf_volume_.save("tsdf_volume.dat", true);
				cout << "done [" << app->tsdf_volume_.size() << " voxels]" << endl;
				cout << "Saving TSDF volume cloud to tsdf_cloud.pcd ... " << std::flush;
				pcl::io::savePCDFile<pcl::PointXYZI>("tsdf_cloud.pcd", *app->tsdf_cloud_ptr_, true);
				cout << "done [" << app->tsdf_cloud_ptr_->size() << " points]" << endl;
				break;

			default:
				break;
			}
	}

	pcl::PointCloud<PointT>::Ptr GetPointCloud()
	{
		const SceneCloudView& view = scene_cloud_view_;
		return KinFuAppMethos::merge<pcl::PointXYZRGB>(*view.cloud_ptr_, *view.point_colors_ptr_);
	}
};

#endif