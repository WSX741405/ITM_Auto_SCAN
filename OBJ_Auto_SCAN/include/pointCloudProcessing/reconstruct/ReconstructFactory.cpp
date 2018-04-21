#include "ReconstructFactory.h"

ReconstructFactory::ReconstructFactory()
{

}

ReconstructProcessing* ReconstructFactory::GetGreedyProjection()
{
	static GreedyProjection* reconstruct = new GreedyProjection();
	return reconstruct;
}

ReconstructProcessing* ReconstructFactory::GetMarchingCubes()
{
	static MarchingCubes* reconstruct = new MarchingCubes();
	return reconstruct;
}

ReconstructProcessing* ReconstructFactory::GetPoisson()
{
	static MyPoisson* reconstruct = new MyPoisson();
	return reconstruct;
}

ReconstructProcessing* ReconstructFactory::GetConcaveHull()
{
	static ConcaveHull* reconstruct = new ConcaveHull();
	return reconstruct;
}