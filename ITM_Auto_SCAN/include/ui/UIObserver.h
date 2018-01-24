#ifndef UI_OBSERVER
#define UI_OBSERVER

#include "flexx/Flexx.h"
#include "ui/MainWindow.h"

class MainWindow;

class UIObserver : public IFlexxObserver
{
public:
	UIObserver(MainWindow* window) : _mainWindow(window)
	{
	}

	void Update(boost::shared_ptr<pcl::PointCloud<PointT>> pointCloud);

private:
	MainWindow* _mainWindow;
};

#endif