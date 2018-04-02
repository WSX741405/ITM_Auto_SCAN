#ifndef MY_FPFH
#define MY_FPFH

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/fpfh.h>
#include <pcl/features/fpfh_omp.h>
#include <pcl/registration/correspondence_rejection_sample_consensus.h>

#include "CorrespondencesProcessing.h"

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointXYZI KeypointT;

class MyFPFH : public CorrespondencesProcessing
{
public:
	MyFPFH();
	void Processing(pcl::PointCloud<PointT>::Ptr source, pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<PointT>::Ptr target, pcl::PointCloud<KeypointT>::Ptr targetKpts);
	void SetDescriptorRadius(float descriptorRadiusSearch);
	void SetNormalRadius(float normalRadiusSearch);
	void SetCorrespondencesK(float correspondencesK);
	//pcl::PointCloud<pcl::FPFHSignature33>::Ptr GetResult();

private:
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr ProessingDescriptor(pcl::PointCloud<PointT>::Ptr cloud, pcl::PointCloud<KeypointT>::Ptr keypoints);
	std::vector<int> ProcessingCorrespondences(pcl::PointCloud<pcl::FPFHSignature33>::Ptr source, pcl::PointCloud<pcl::FPFHSignature33>::Ptr target);
	void ProcessingFilterCorrespondences(pcl::PointCloud<KeypointT>::Ptr sourceKpts, pcl::PointCloud<KeypointT>::Ptr targetKpts, std::vector<int> source2Target, std::vector<int> target2Source);

	pcl::Feature<PointT, pcl::FPFHSignature33>::Ptr _featureExtractor;
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr _sourceDescriptor;
	pcl::PointCloud<pcl::FPFHSignature33>::Ptr _targetDescriptor;

	float _descriptorRadiusSearch;
	float _normalRadiusSearch;
	int _correspondencesK;
};

#endif