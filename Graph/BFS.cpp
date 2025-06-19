#include <BFS.h>

#include <queue>
#include <unordered_map>
#include <unordered_set>

void BFS::run(Graph::IndexT firstVertex, EdgePredicate exitCondition)
{
    std::unordered_set<Graph::IndexT> visited;
    std::unordered_map<Graph::IndexT, Graph::IndexT> parentEdges;

    Graph::IndexT v = firstVertex;
    std::queue<Graph::IndexT> queue;

    queue.push(v);
    visited.insert(v);

    // Traverse graph while exit condition is unsatisfied
    while (!queue.empty()) {

        v = queue.front();
        queue.pop();

        auto parentIter = parentEdges.find(v);
        if (parentIter != parentEdges.end() && exitCondition(parentIter->second)) {
            break;
        }

        for (Graph::IndexT outEdgeIndex : _graph.adjacencyList(v)) {
            const Graph::Edge& edge = _graph.edge(outEdgeIndex);

            // TODO: support ingore edge condition
            if (visited.count(edge._to) == 0) {
                queue.push(edge._to);
                visited.insert(edge._to);

                parentEdges[edge._to] = outEdgeIndex;
            }
        }
    }

    // Save traverse order
    _traverseOrder.clear();

    auto parentIter = parentEdges.find(v);
    while (parentIter != parentEdges.end()) {
        Graph::IndexT parentEdgeIndex = parentIter->second;

        const Graph::Edge& parentEdge = _graph.edge(parentEdgeIndex);

        _traverseOrder.push_back(parentEdgeIndex);
        parentIter = parentEdges.find(parentEdge._from);
    }
    std::reverse(_traverseOrder.begin(), _traverseOrder.end());
}
