#include "CorrespondencesFactory.h"

CorrespondencesFactory::CorrespondencesFactory()
{
}

CorrespondencesProcessing* CorrespondencesFactory::GetFPFH()
{
	static MyFPFH* correspondences = new MyFPFH();
	return correspondences;
}

CorrespondencesProcessing* CorrespondencesFactory::GetMySHOTRGB()
{
	static MySHOTRGB* correspondences = new MySHOTRGB();
	return correspondences;
}