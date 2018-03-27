#include "observer/IObserver.h"

//		*****************************************************************
//				Observer
//				UI
//		*****************************************************************

void UIObserver::Update(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	emit UIObserver::UpdateViewer(pointCloud);
	emit UIObserver::KeepFrame(pointCloud);
}

//		*****************************************************************
//				Subject
//				Grabber(Flexx, RS)
//		*****************************************************************

void FlexxSubject::RegisterObserver(IObserver* observer)
{
	_observers.push_back(observer);
}

void FlexxSubject::NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	for each (IObserver* observer in _observers)
	{
		observer->Update(pointCloud);
	}
}

void RSSubject::RegisterObserver(IObserver* observer)
{
	_observers.push_back(observer);
}

void RSSubject::NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	for each (IObserver* observer in _observers)
	{
		observer->Update(pointCloud);
	}
}