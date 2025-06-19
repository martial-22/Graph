#pragma once

#include <TraverseAlgorithm.h>

class BFS : public TraverseAlgorithm
{
public:
	using TraverseAlgorithm::TraverseAlgorithm;

	void run(Graph::IndexT firstVertex, EdgePredicate exitCondition) override;
};
