#include <vector>

class Graph {
public:
	using IndexT = std::uint64_t;

	struct Edge {
		IndexT _from;
		IndexT _to;
		IndexT _index;
	};

	explicit Graph(IndexT verticesCount);

	/**
	* @brief Adds new edge between two vertices.
	* @returns Index of added edge.
	*/
	IndexT addEdge(IndexT from, IndexT to);

	/**
	* @returns Edge by index.
	*/
	const Edge& edge(IndexT edgeIndex) const;

	/**
	* @returns Edges incident to vertex with index vertexIndex.
	*/
	const std::vector<IndexT>& adjacencyList(IndexT vertexIndex) const;

private:

	IndexT _verticesCount;

	std::vector<Edge> _edges;
	std::vector<std::vector<IndexT>> _adjacencyLists;
};
