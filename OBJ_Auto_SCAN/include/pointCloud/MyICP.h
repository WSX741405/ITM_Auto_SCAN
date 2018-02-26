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
		_sourceCloud.reset(new pcl::PointCloud<PointT>(*sourceCloud));
		_targetCloud.reset(new pcl::PointCloud<PointT>(*targetCloud));
	}

	void ProcessICP()
	{
		_icp.setInputSource(_sourceCloud);
		_icp.setInputTarget(_targetCloud);
		_icp.align(*_outputCloud);
		_outputCloud->resize(_targetCloud->size() + _outputCloud->size());
		for (int counter = 0; counter; counter++)
		{
			_outputCloud->push_back(_targetCloud->points[counter]);
		}
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

	boost::shared_ptr<pcl::PointCloud<PointT>> GetOutputPointCloud()
	{
		return _outputCloud;
	}

private:
	boost::shared_ptr<pcl::PointCloud<PointT>> _sourceCloud;
	boost::shared_ptr<pcl::PointCloud<PointT>> _targetCloud;
	boost::shared_ptr<pcl::PointCloud<PointT>> _outputCloud;
	pcl::IterativeClosestPoint<PointT, PointT> _icp;
};

#endif