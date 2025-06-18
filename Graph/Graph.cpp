#include <Graph.h>
#include <GAssert.h>

Graph::Graph(IndexT verticesCount, DirectionType directionType)
	: _verticesCount(verticesCount), _directionType(directionType), _adjacencyLists(verticesCount)
{
}

Graph::IndexT Graph::addEdge(IndexT from, IndexT to)
{
	GRAPH_ASSERT(from < _verticesCount && to < _verticesCount);

	IndexT edgeIndex = _edges.size();
	_edges.emplace_back(from, to, edgeIndex);

	_adjacencyLists[from].emplace_back(edgeIndex);

	if (_directionType == DirectionType::UNDIRECTED)
	{
		_adjacencyLists[to].emplace_back(edgeIndex);
	}
	return edgeIndex;
}

const Graph::Edge& Graph::edge(IndexT edgeIndex) const
{
	GRAPH_ASSERT(edgeIndex < _edges.size());
	return _edges[edgeIndex];
}

const std::vector<Graph::IndexT>& Graph::adjacencyList(IndexT vertexIndex) const
{
	GRAPH_ASSERT(vertexIndex < _verticesCount);
	return _adjacencyLists[vertexIndex];
}
