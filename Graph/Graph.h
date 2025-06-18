#include <BaseGraph.h>

template <class V, class E>
class Graph {
public:
	Graph(std::vector<V>&& vertices)
		: _vertices(std::move(vertices))
	{
	}

	void addEdge(const V& from, const V& to, E&& edge)
	{
		_edges.emplace_back(std::move(edge));
	}

private:
	std::vector<V> _vertices;
	std::vector<E> _edges;

	std::unordered_map<V, BaseGraph::IndexT> _vertexToIndex;
	std::unordered_map<E, BaseGraph::IndexT> _edgeToIndex;
};
