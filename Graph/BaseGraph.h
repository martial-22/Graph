#include <vector>

class BaseGraph {
public:
	using IndexT = std::uint64_t;

	explicit BaseGraph(IndexT verticesCount);
	void addEdge(IndexT from, IndexT to);

private:
	struct Edge {
		IndexT _from;
		IndexT _to;
	};

	IndexT _verticesCount;

	std::vector<Edge> _edges;
	std::vector<std::vector<Edge>> _adjList;
};
