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

	virtual void run(Graph::IndexT firstVertex, EdgePredicate exitCondition) = 0;

	/**
	* @returns Indices of visited edges in the order of traverse.
	*/
	const std::vector<Graph::IndexT>& traverseOrder() const { return _traverseOrder; }

protected:
	const Graph& _graph;
	std::vector<Graph::IndexT> _traverseOrder;
};
