#ifndef GRABBER
#define GRABBER

class IGrabber
{
public:
	virtual void StartCamera() = 0;
	virtual void StopCamera() = 0;
};

#endif