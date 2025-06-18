#include <BaseGraph.h>
#include <GAssert.h>

template <class V, class E>
class Graph {
public:
	Graph(std::vector<V>&& vertices)
		: _baseGraph(vertices.size()), _vertices(std::move(vertices))
	{
	}

	void addEdge(const V& from, const V& to, E&& edge)
	{
		auto fromIter = _vertexToIndex.find(from);
		auto toIter = _vertexToIndex.find(to);

		GRAPH_ASSERT(fromIter != _vertexToIndex.end() && toIter != _vertexToIndex.end());

		_edges.emplace_back(std::move(edge));
		_baseGraph.addEdge(fromIter->second, toIter->second);
	}

private:
	BaseGraph _baseGraph;

	std::vector<V> _vertices;
	std::vector<E> _edges;

	std::unordered_map<V, BaseGraph::IndexT> _vertexToIndex;
	std::unordered_map<E, BaseGraph::IndexT> _edgeToIndex;
};
