#ifndef FLEXX
#define FLEXX

#include <royale.hpp>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <mutex>
#include <thread>
#include <chrono>
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
	const unsigned int DEPTH_CONFIDENCE = 128;

	explicit FlexxListener(const royale::Vector<royale::StreamId> &streamIds, ISubject* subject);

	void onNewData(const royale::DepthData* data) override;

private:
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
class Flexx
{
public:
	Flexx(ISubject* subject, unsigned int cameraId = 0);
	
	~Flexx();

	void OpenCamera();

	void CloseCamera();

private:

	royale::CameraManager _manager;
	royale::Vector<royale::String> _camlist;												//	�����쪺Camera�C��
	std::unique_ptr<royale::ICameraDevice> _cameraDevice;					//	Camera�˸m (�w�]����0��Camera�˸m)
	royale::Vector<royale::String> _useCases;											//	���˸m�䴩��Use case (Mode)
	unsigned int _selectedUseCaseId;														//	��Ϊ�Use case
	royale::Vector<royale::StreamId> _streamIds;
	std::unique_ptr<FlexxListener> _listener;
	ISubject* _subject;
};
#endif