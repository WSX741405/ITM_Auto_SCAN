#include "observer/IObserver.h"

//		*****************************************************************
//				Observer
//				UI
//		*****************************************************************

void UIObserver::Update(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	emit UIObserver::UpdateViewer(pointCloud);
	emit UIObserver::KeepFrameArrived(pointCloud);
}

//		*****************************************************************
//				Subject
//				Grabber(Flexx, RS)
//		*****************************************************************

void GrabberSubject::RegisterObserver(IObserver* observer)
{
	_observers.push_back(observer);
}

void GrabberSubject::NotifyObservers(pcl::PointCloud<PointT>::Ptr pointCloud)
{
	for each (IObserver* observer in _observers)
	{
		observer->Update(pointCloud);
	}
}