#pragma once

#include <vector>

class Graph
{
public:
	using IndexT = std::uint64_t;

	enum class DirectionType
	{
		DIRECTED,
		UNDIRECTED
	};

	struct Edge
	{
		IndexT _from;
		IndexT _to;
		IndexT _index;
	};

	explicit Graph(IndexT numVertices, DirectionType directionType);

	/**
	* @brief Adds new edge between two vertices.
	* @returns Index of added edge.
	*/
	IndexT addEdge(IndexT from, IndexT to);

	/**
	* @returns Number of vertices.
	*/
	std::size_t numVertices() const { return _numVertices; }

	/**
	* @returns Number of edges.
	*/
	std::size_t numEdges() const { return _edges.size(); }

	/**
	* @returns Edge by index.
	*/
	const Edge& edge(IndexT edgeIndex) const;

	/**
	* @returns Edges incident to vertex with index vertexIndex.
	*/
	const std::vector<IndexT>& adjacencyList(IndexT vertexIndex) const;

private:
	IndexT _numVertices;
	DirectionType _directionType;

	std::vector<Edge> _edges;
	std::vector<std::vector<IndexT>> _adjacencyLists;
};
