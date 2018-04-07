#ifndef RECONSTRUCT_FACTORY
#define RECONSTRUCT_FACTORY

#include "ReconstructProcessing.h"
#include "GreedyProjection.h"

class ReconstructFactory
{
public:
	ReconstructFactory();
	ReconstructProcessing* GetGreedyProjection();

private:

};

#endif