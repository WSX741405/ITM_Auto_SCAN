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

	explicit FlexxListener(const royale::Vector<royale::StreamId> &streamIds, FlexxSubject* flexxSubject);

	void onNewData(const royale::DepthData* data) override;

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
	Flexx(FlexxSubject* flexxSubject, unsigned int cameraId = 0);
	
	~Flexx();

	void OpenCamera();

	void CloseCamera();

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