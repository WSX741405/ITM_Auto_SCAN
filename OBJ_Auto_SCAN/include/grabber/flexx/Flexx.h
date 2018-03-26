#ifndef FLEXX
#define FLEXX

#include <royale.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <mutex>
#include <thread>
#include <chrono>
#include "grabber/Grabber.h"
#include "observer/IObserver.h"

typedef pcl::PointXYZRGBA PointT;

class ISubject;

//		*****************************************************************
//				Flexx Listener
//				When the frame arrived, onNewData get depth data
//		*****************************************************************
class FlexxListener : public royale::IDepthDataListener
{
public:
	explicit FlexxListener(const royale::Vector<royale::StreamId> &streamIds, ISubject* subject);
	void onNewData(const royale::DepthData* data) override;
	void SetDepthConfidence(int depthConfidence);
	std::mutex& GetMutex();

private:
	int _depthConfidence;
	std::size_t _width;
	std::size_t _height;
	royale::Vector<uint32_t> _exposureTimes;
	const royale::Vector<royale::StreamId> _streamIds;
	std::mutex _lockForReceivedData;
	ISubject* _subject;
	boost::shared_ptr<pcl::PointCloud<PointT>> _pointCloud;
};

//		*****************************************************************
//				Flexx
//				Flexx Manager, contains all pmdtec camera device
//		*****************************************************************
class Flexx : IGrabber
{
public:
	Flexx(ISubject* subject, unsigned int cameraId = 0);
	~Flexx();
	void StartCamera();
	void StopCamera();
	void SetDepthConfidence(int depthConfidence);
	std::mutex& GetMutex();

private:

	royale::CameraManager _manager;
	royale::Vector<royale::String> _camlist;												//	偵測到的Camera列表
	std::unique_ptr<royale::ICameraDevice> _cameraDevice;					//	Camera裝置 (預設為第0個Camera裝置)
	royale::Vector<royale::String> _useCases;											//	此裝置支援的Use case (Mode)
	unsigned int _selectedUseCaseId;														//	選用的Use case
	royale::Vector<royale::StreamId> _streamIds;
	std::unique_ptr<FlexxListener> _listener;
	ISubject* _subject;
};
#endif