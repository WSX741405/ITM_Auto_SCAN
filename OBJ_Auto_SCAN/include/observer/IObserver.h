#ifndef UI_OBSERVER
#define UI_OBSERVER

#include "ui/MainWindow.h"

class MainWindow;

//		*****************************************************************
//				Observer
//				UI, 
//		*****************************************************************

class IObserver
{
public:
	virtual void Update(pcl::PointCloud<PointT>::Ptr pointCloud) = 0;
};

class UIObserver : public QObject, public IObserver
{
	Q_OBJECT
public:
	UIObserver(MainWindow* window) : _mainWindow(window){}
	void Update(pcl::PointCloud<PointT>::Ptr pointCloud);

signals:
	void UpdateViewer(pcl::PointCloud<PointT>::Ptr pointCloud);
	void KeepFrameArrived(pcl::PointCloud<PointT>::Ptr pointCloud);

private:
	MainWindow* _mainWindow;
};

//		*****************************************************************
//				Subject
//				Flexx, 
//		*****************************************************************

class ISubject
{
public:
	virtual void RegisterObserver(IObserver* observer) = 0;
	virtual void NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud) = 0;

protected:
	std::vector<IObserver*> _observers;
};

class FlexxSubject : ISubject
{
public:
	void RegisterObserver(IObserver* observer);
	void NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud);
};

class RSSubject : ISubject
{
public:
	void RegisterObserver(IObserver* observer);
	void NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud);
};
#endif