#ifndef MY_ICP
#define MY_ICP

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
typedef pcl::PointXYZRGBA PointT;

class MyIterativeClosestPoint
{
public:
	MyIterativeClosestPoint(boost::shared_ptr<pcl::PointCloud<PointT>> sourceCloud, boost::shared_ptr<pcl::PointCloud<PointT>> targetCloud)
	{
		_isDone = false;
		_sourceCloud.reset(new pcl::PointCloud<PointT>(*sourceCloud));
		_targetCloud.reset(new pcl::PointCloud<PointT>(*targetCloud));
		_outputCloud.reset(new pcl::PointCloud<PointT>());
	}

	void ProcessICP()
	{
		_icp.setInputSource(_sourceCloud);
		_icp.setInputTarget(_targetCloud);
		_icp.align(*_outputCloud);
		_outputCloud->resize(_targetCloud->size() + _outputCloud->size());
		for (int counter = 0; counter < _targetCloud->size(); counter++)
		{
			_outputCloud->push_back(_targetCloud->points[counter]);
		}
		_isDone = true;
	}

	void SetMaxCorrespondenceDistance(double threshold)
	{
		_icp.setMaxCorrespondenceDistance(threshold);
	}

	void SetTransformationEpsilon(double epsilon)
	{
		_icp.setTransformationEpsilon(epsilon);
	}

	void SetEuclideanFitnessEpsilon(double epsilon)
	{
		_icp.setEuclideanFitnessEpsilon(epsilon);
	}

	void SetMaximumIterations(int iteraction)
	{
		_icp.setMaximumIterations(iteraction);
	}

	bool GetIsDone()
	{
		return _isDone;
	}

	boost::shared_ptr<pcl::PointCloud<PointT>> GetOutputPointCloud()
	{
		return _outputCloud;
	}

	bool GetHasConverged()
	{
		return _icp.hasConverged();
	}

	double GetFitnessScore()
	{
		return _icp.getFitnessScore();
	}

private:
	bool _isDone;
	boost::shared_ptr<pcl::PointCloud<PointT>> _sourceCloud;
	boost::shared_ptr<pcl::PointCloud<PointT>> _targetCloud;
	boost::shared_ptr<pcl::PointCloud<PointT>> _outputCloud;
	pcl::IterativeClosestPoint<PointT, PointT> _icp;
};

#endif