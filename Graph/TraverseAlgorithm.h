#pragma once

#include <functional>

#include <Graph.h>

using EdgePredicate = std::function<bool(Graph::IndexT edgeIndex)>;

class TraverseAlgorithm
{
public:
	TraverseAlgorithm(const Graph& graph)
		: _graph(graph)
	{
	}

	virtual void run(EdgePredicate exitCondition) = 0;

	const std::vector<Graph::IndexT>& traverseOrder() const { return _traverseOrder; }

private:
	const Graph& _graph;
	std::vector<Graph::IndexT> _traverseOrder;
};
