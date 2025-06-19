#include <BFS.h>

#include <queue>
#include <unordered_map>
#include <unordered_set>

void BFS::run(Graph::IndexT firstVertex, EdgePredicate exitCondition)
{
    std::unordered_map<Graph::IndexT, Graph::IndexT> parentEdges;

    Graph::IndexT v = firstVertex;
    std::queue<Graph::IndexT> queue;

    queue.push(v);
    parentEdges[v] = Graph::nullIndex;

    // Traverse graph while exit condition is unsatisfied
    while (!queue.empty()) {

        v = queue.front();
        queue.pop();

        auto iter = parentEdges.find(v);
        if (iter != parentEdges.end() && exitCondition(iter->second)) {
            break;
        }

        for (Graph::IndexT eIndex : _graph.adjacencyList(v)) {
            const Graph::Edge& edge = _graph.edge(eIndex);

            if (parentEdges.count(edge._to) == 0) {
                queue.push(edge._to);
                parentEdges[edge._to] = eIndex;
            }
        }
    }

    // Save traverse order
    _traverseOrder.clear();

    auto iter = parentEdges.find(v);
    while (iter != parentEdges.end()) {

        Graph::IndexT eIndex = iter->second;
        if (eIndex == Graph::nullIndex) {
            break;
        }

        const Graph::Edge& edge = _graph.edge(eIndex);

        _traverseOrder.push_back(eIndex);
        iter = parentEdges.find(edge._from);
    }
    std::reverse(_traverseOrder.begin(), _traverseOrder.end());
}
