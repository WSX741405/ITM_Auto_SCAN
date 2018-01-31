#include "flexx/Flexx.h"

//		*****************************************************************
//				Flexx Listener
//		*****************************************************************

FlexxListener::FlexxListener(const royale::Vector<royale::StreamId> &streamIds, ISubject* subject) : _streamIds(streamIds), _subject(subject)
{
	_pointCloud.reset(new pcl::PointCloud<PointT>());
}

void FlexxListener::onNewData(const royale::DepthData* data)
{
	std::unique_lock<std::mutex> lock(_lockForReceivedData);
	if (_pointCloud != nullptr)
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
		point->x = data->points[counter].x;
		point->y = data->points[counter].y;
		point->z = data->points[counter].z;
		_pointCloud->push_back(*point);
	}
	_subject->notifyObservers(_pointCloud);
}

//		*****************************************************************
//				Flexx
//		*****************************************************************

Flexx::Flexx(ISubject* subject, unsigned int cameraId) : _subject(subject)
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

Flexx::~Flexx()
{
	if (_cameraDevice->stopCapture() != royale::CameraStatus::SUCCESS)
		throw std::string("Flexx: Error stopping the capturing");
}

void Flexx::OpenCamera()
{
	if (_cameraDevice->setUseCase(_useCases.at(_selectedUseCaseId)) != royale::CameraStatus::SUCCESS)
		throw std::string("Flexx: Error setting use case");
	_listener.reset(new FlexxListener(_streamIds, _subject));
	if (_cameraDevice->registerDataListener(_listener.get()) != royale::CameraStatus::SUCCESS)
		throw std::string("Flexx: Error registering flexx listener");
	if (_cameraDevice->startCapture() != royale::CameraStatus::SUCCESS)
		throw std::string("Flexx: Error starting the capturing");
}

void Flexx::CloseCamera()
{
	if (_cameraDevice->stopCapture() != royale::CameraStatus::SUCCESS)
		throw std::string("Flexx: Error stopping the capturing");
}