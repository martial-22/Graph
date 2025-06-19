#include <Graph.h>
#include <GAssert.h>

Graph::Graph(IndexT numVertices, DirectionType directionType)
	: _numVertices(numVertices), _directionType(directionType), _adjacencyLists(_numVertices)
{
}

Graph::IndexT Graph::addEdge(IndexT from, IndexT to)
{
	GRAPH_ASSERT(from < _numVertices && to < _numVertices);

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
	GRAPH_ASSERT(vertexIndex < _numVertices);
	return _adjacencyLists[vertexIndex];
}
