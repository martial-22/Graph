#include <BaseGraph.h>

BaseGraph::BaseGraph(IndexT verticesCount)
	: _verticesCount(verticesCount)
{
	_adjList.reserve(verticesCount);
}

void BaseGraph::addEdge(IndexT from, IndexT to)
{
	_edges.emplace_back(from, to);

	_adjList[from].emplace_back(_edges.back());
	_adjList[to].emplace_back(_edges.back());
}
