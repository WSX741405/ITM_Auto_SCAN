#include "ReconstructFactory.h"

ReconstructFactory::ReconstructFactory()
{

}

ReconstructProcessing* ReconstructFactory::GetGreedyProjection()
{
	static GreedyProjection* reconstruct = new GreedyProjection();
	return reconstruct;
}