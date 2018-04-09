#ifndef CORRESPONDENCES_FACTORY
#define CORRESPONDENCES_FACTORY

#include "CorrespondencesProcessing.h"
#include "MyFPFH.h"
#include "MySHOTRGB.h"
#include "MyPFH.h";
#include "MyPFHRGB.h"

class CorrespondencesFactory
{
public:
	CorrespondencesFactory();
	CorrespondencesProcessing* GetFPFH();
	CorrespondencesProcessing* GetSHOTRGB();
	CorrespondencesProcessing* GetPFH();
	CorrespondencesProcessing* GetPFHRGB();

private:
};

#endif