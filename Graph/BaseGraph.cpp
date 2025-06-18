#include <BaseGraph.h>
#include <GAssert.h>

BaseGraph::BaseGraph(IndexT verticesCount)
	: _verticesCount(verticesCount), _adjList(verticesCount)
{
}

void BaseGraph::addEdge(IndexT from, IndexT to)
{
	GRAPH_ASSERT(from < _verticesCount && to < _verticesCount);

	_edges.emplace_back(from, to);

	_adjList[from].emplace_back(_edges.back());
	_adjList[to].emplace_back(_edges.back());
}
