#ifndef FLEXX
#define FLEXX

#include <royale.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <mutex>
#include <thread>
#include <chrono>

typedef pcl::PointXYZRGBA PointT;

//		*****************************************************************
//				Flexx Observer
//				When frame arrived, notify observer to update UI
//		*****************************************************************
class IFlexxObserver
{
public:
	virtual void Update(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud) = 0;
};

class FlexxSubject
{
public:
	void RegisterObserver(IFlexxObserver* observer)
	{
		_observers.push_back(observer);
	}

	void notifyObservers(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud)
	{
		for each (IFlexxObserver* observer in _observers)
		{
			observer->Update(pointCloud);
		}
	}

private:
	std::vector<IFlexxObserver*> _observers;
};

//		*****************************************************************
//				Flexx Listener
//				When the frame arrived, onNewData get depth data
//		*****************************************************************
class FlexxListener : public royale::IDepthDataListener
{
public:
	const unsigned int DEPTH_CONFIDENCE = 128;

	explicit FlexxListener(const royale::Vector<royale::StreamId> &streamIds, FlexxSubject* flexxSubject) : _streamIds(streamIds), _flexxSubject(flexxSubject)
	{
		_pointCloud.reset(new pcl::PointCloud<PointT>());
	}

	void onNewData(const royale::DepthData* data) override
	{
		std::unique_lock<std::mutex> lock(_lockForReceivedData);
		_pointCloud->clear();
		//			Copy depth data
		_width = data->width;
		_height = data->height;
		unsigned int counter = 0;
		for (; counter < _width * _height; counter++)
		{
			if (data->points[counter].depthConfidence < DEPTH_CONFIDENCE)		//	資料不可靠
				continue;
			boost::shared_ptr<pcl::PointXYZRGBA> point(new pcl::PointXYZRGBA);
			point->r = 255;
			point->g = 255;
			point->b = 255;
			//std::cout << std::string("Flexx Listener : X = ") << data->points[counter].x << std::endl;
			point->x = data->points[counter].x;
			point->y = data->points[counter].y;
			point->z = data->points[counter].z;
			_pointCloud->push_back(*point);
		}
		/*
		for (unsigned int y = 0; y < _height; y++)
		{
			for (unsigned int x = 0; x < _width; x++)
			{
				_pointCloud->points[y * _width + x].x = data->points[y * _width + x].x;
				_pointCloud->points[y * _width + x].y = data->points[y * _width + x].y;
				_pointCloud->points[y * _width + x].z = data->points[y * _width + x].z;
				_pointCloud->points[y * _width + x].rgb = 0;
			}
		}
		*/
		_flexxSubject->notifyObservers(_pointCloud);
	}

private:
	std::size_t _width;
	std::size_t _height;
	royale::Vector<uint32_t> _exposureTimes;
	const royale::Vector<royale::StreamId> _streamIds;
	std::mutex _lockForReceivedData;
	FlexxSubject* _flexxSubject;
	boost::shared_ptr<pcl::PointCloud<PointT>> _pointCloud;
};

//		*****************************************************************
//				Flexx
//				Flexx Manager, contains all pmdtec camera device
//		*****************************************************************
class Flexx
{
public:
	Flexx(FlexxSubject* flexxSubject, unsigned int cameraId = 0) : _flexxSubject(flexxSubject)
	{
		_camlist = _manager.getConnectedCameraList();
		_selectedUseCaseId = 0;
		if (!_camlist.empty())
			_cameraDevice = _manager.createCamera(_camlist[cameraId]);
		if (_cameraDevice == nullptr)
			throw std::string("Flexx: Cannot create camera device");						//	無法create camera
		if (_cameraDevice->initialize() != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Cannot initalize camera device");						//	無法初始化
		royale::CameraStatus status = _cameraDevice->getUseCases(_useCases);
		if (status != royale::CameraStatus::SUCCESS || _useCases.empty())
			throw std::string("Flexx: No use cases are available");							//	此裝置沒有use case
		if (_cameraDevice->getStreams(_streamIds) != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error retrieving streams");
	}
	
	~Flexx()
	{
		if (_cameraDevice->stopCapture() != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error stopping the capturing");
	}

	void OpenCamera()
	{
		if (_cameraDevice->setUseCase(_useCases.at(_selectedUseCaseId)) != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error setting use case");
		_listener.reset(new FlexxListener(_streamIds, _flexxSubject));
		if (_cameraDevice->registerDataListener(_listener.get()) != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error registering flexx listener");
		if (_cameraDevice->startCapture() != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error starting the capturing");
	}

private:

	royale::CameraManager _manager;
	royale::Vector<royale::String> _camlist;												//	偵測到的Camera列表
	std::unique_ptr<royale::ICameraDevice> _cameraDevice;					//	Camera裝置 (預設為第0個Camera裝置)
	royale::Vector<royale::String> _useCases;											//	此裝置支援的Use case (Mode)
	unsigned int _selectedUseCaseId;														//	選用的Use case
	royale::Vector<royale::StreamId> _streamIds;
	std::unique_ptr<FlexxListener> _listener;
	FlexxSubject* _flexxSubject;
};
#endif