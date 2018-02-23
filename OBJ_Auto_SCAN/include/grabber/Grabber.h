#ifndef GRABBER
#define GRABBER

#include <mutex>

class IGrabber
{
public:
	virtual void StartCamera() = 0;
	virtual void StopCamera() = 0;
	virtual void SetDepthConfidence(int depthConfidence) = 0;
	virtual std::mutex& GetMutex() = 0;
};

#endif