#include "CorrespondencesFactory.h"

CorrespondencesFactory::CorrespondencesFactory()
{
}

CorrespondencesProcessing* CorrespondencesFactory::GetFPFH()
{
	static MyFPFH* correspondences = new MyFPFH();
	return correspondences;
}

CorrespondencesProcessing* CorrespondencesFactory::GetSHOTRGB()
{
	static MySHOTRGB* correspondences = new MySHOTRGB();
	return correspondences;
}

CorrespondencesProcessing* CorrespondencesFactory::GetPFH()
{
	static MyPFH* correspondences = new MyPFH();
	return correspondences;
}

CorrespondencesProcessing* CorrespondencesFactory::GetPFHRGB()
{
	static MyPFHRGB* correspondences = new MyPFHRGB();
	return correspondences;
}