#ifndef CORRESPONDENCES_FACTORY
#define CORRESPONDENCES_FACTORY

#include "CorrespondencesProcessing.h"
#include "MyFPFH.h"
#include "MySHOTRGB.h"

class CorrespondencesFactory
{
public:
	CorrespondencesFactory();
	CorrespondencesProcessing* GetFPFH();
	CorrespondencesProcessing* GetMySHOTRGB();

private:
};

#endif