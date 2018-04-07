#ifndef MY_FPFH
#define MY_FPFH

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/fpfh_omp.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>
#include <pcl/registration/icp.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/filters/filter.h>

#include "CorrespondencesProcessing.h"

typedef pcl::PointXYZRGB PointT;
typedef pcl::PointXYZI KeypointT;

class MyFPFH : public CorrespondencesProcessing
{
public:
	MyFPFH();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts);
	void SetDescriptorRadius(float descriptorRadiusSearch);
	void SetNormalRadius(float normalRadiusSearch);
	void SetCorrespondencesK(float correspondencesK);
	pcl::CorrespondencesPtr GetCorrespondencesResult();
	pcl::PointCloud<PointT>::Ptr GetResult();

private:
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints);
	std::vector<int> ProcessingCorrespondences(pcl::PointCloud<pcl::FPFHSignature33>::Ptr source, pcl::PointCloud<pcl::FPFHSignature33>::Ptr target);
	pcl::CorrespondencesPtr ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source);
	void DetermineInitialTransformation(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, pcl::CorrespondencesPtr correspondences);

	pcl::PointCloud<pcl::FPFHSignature33>::Ptr _sourceDescriptor;
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr _targetDescriptor;
	pcl::PointCloud<PointT>::Ptr _transformedSource;
	pcl::CorrespondencesPtr _correspondencesResult;

	float _descriptorRadiusSearch;
	float _normalRadiusSearch;
	int _correspondencesK;
	float _rejectorInlierThreshold;
};

#endif