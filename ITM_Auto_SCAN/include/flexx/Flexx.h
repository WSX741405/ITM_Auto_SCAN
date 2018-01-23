#ifndef FLEXX
#define FLEXX

#include <royale.hpp>

#include <mutex>

class FlexxListener : public royale::IDepthDataListener
{
	/*
	struct FlexxFrameData
	{
		std::vector<uint32_t> exposureTimes;
	};
	*/

public:
	explicit FlexxListener(const royale::Vector<royale::StreamId> &streamIds) : _streamIds(streamIds)
	{
	}

	void onNewData(const royale::DepthData* data) override
	{
		_exposureTimes = data->exposureTimes;
		_height = data->height;

		/*
		{
			std::unique_lock<std::mutex> lock(_lockForReceivedData);
			auto &receivedData = _receivedData[data->streamId];
			receivedData.exposureTimes = _exposureTimes.toStdVector();
		}
		*/
	}

private:
	std::size_t _width;
	std::size_t _height;
	std::size_t _widthPerStream;
	royale::Vector<uint32_t> _exposureTimes;
	const royale::Vector<royale::StreamId> _streamIds;
	std::mutex _lockForReceivedData;
	//std::map<royale::StreamId, FlexxFrameData> _receivedData;
};

class Flexx
{
public:
	Flexx(unsigned int cameraId = 0)
	{
		_camlist = _manager.getConnectedCameraList();
		_selectedUseCaseId = 0;
		if (!_camlist.empty())
			_cameraDevice = _manager.createCamera(_camlist[cameraId]);
		if (_cameraDevice == nullptr)
			throw std::string("Flexx: Cannot create camera device");						//	�L�kcreate camera
		if (_cameraDevice->initialize() != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Cannot initalize camera device");						//	�L�k��l��
		royale::CameraStatus status = _cameraDevice->getUseCases(_useCases);
		if (status != royale::CameraStatus::SUCCESS || _useCases.empty())
			throw std::string("Flexx: No use cases are available");							//	���˸m�S��use case
		if (_cameraDevice->getStreams(_streamIds) != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error retrieving streams");
	}
	
	void OpenCamera()
	{
		if (_cameraDevice->setUseCase(_useCases.at(_selectedUseCaseId)) != royale::CameraStatus::SUCCESS)
			throw std::string("Flexx: Error setting use case");

	}

private:

	royale::CameraManager _manager;
	royale::Vector<royale::String> _camlist;												//	�����쪺Camera�C��
	std::unique_ptr<royale::ICameraDevice> _cameraDevice;					//	Camera�˸m (�w�]����0��Camera�˸m)
	royale::Vector<royale::String> _useCases;											//	���˸m�䴩��Use case (Mode)
	unsigned int _selectedUseCaseId;														//	��Ϊ�Use case
	royale::Vector<royale::StreamId> _streamIds;

};
#endif