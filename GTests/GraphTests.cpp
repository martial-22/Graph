#include <gtest/gtest.h>
#include <Graph.h>

TEST(GraphTest, GetEdge)
{
	Graph graph(3, Graph::DirectionType::UNDIRECTED);

	Graph::IndexT e1 = graph.addEdge(1, 2);
	EXPECT_EQ(graph.numEdges(), 1);

	Graph::IndexT e2 = graph.addEdge(0, 2);
	EXPECT_EQ(graph.numEdges(), 2);

	Graph::IndexT e3 = graph.addEdge(0, 1);
	EXPECT_EQ(graph.numEdges(), 3);
	
	EXPECT_EQ(graph.edge(0)._from, 1);
	EXPECT_EQ(graph.edge(0)._to, 2);
	EXPECT_EQ(graph.edge(0)._index, 0);

	EXPECT_EQ(graph.edge(1)._from, 0);
	EXPECT_EQ(graph.edge(1)._to, 2);
	EXPECT_EQ(graph.edge(1)._index, 1);

	EXPECT_EQ(graph.edge(2)._from, 0);
	EXPECT_EQ(graph.edge(2)._to, 1);
	EXPECT_EQ(graph.edge(2)._index, 2);

	EXPECT_THROW(graph.edge(3), std::runtime_error);
	EXPECT_THROW(graph.edge(4), std::runtime_error);
}

TEST(GraphTest, GetAdjacencyListDirected)
{
	Graph graph(4, Graph::DirectionType::DIRECTED);

	Graph::IndexT e1 = graph.addEdge(1, 2);
	EXPECT_EQ(graph.numEdges(), 1);

	Graph::IndexT e2 = graph.addEdge(0, 2);
	EXPECT_EQ(graph.numEdges(), 2);

	EXPECT_EQ(graph.adjacencyList(0).size(), 1);
	EXPECT_EQ(graph.adjacencyList(0).front(), e2);

	EXPECT_EQ(graph.adjacencyList(1).size(), 1);
	EXPECT_EQ(graph.adjacencyList(1).front(), e1);

	EXPECT_TRUE(graph.adjacencyList(2).empty());
	EXPECT_TRUE(graph.adjacencyList(3).empty());
}

TEST(GraphTest, GetAdjacencyListUndirected)
{
	Graph graph(4, Graph::DirectionType::UNDIRECTED);

	Graph::IndexT e1 = graph.addEdge(1, 2);
	EXPECT_EQ(graph.numEdges(), 1);

	Graph::IndexT e2 = graph.addEdge(0, 2);
	EXPECT_EQ(graph.numEdges(), 2);

	EXPECT_EQ(graph.adjacencyList(0).size(), 1);
	EXPECT_EQ(graph.adjacencyList(0).front(), e2);

	EXPECT_EQ(graph.adjacencyList(1).size(), 1);
	EXPECT_EQ(graph.adjacencyList(1).front(), e1);

	EXPECT_EQ(graph.adjacencyList(2).size(), 2);
	EXPECT_EQ(graph.adjacencyList(2).front(), e1);
	EXPECT_EQ(graph.adjacencyList(2).back(), e2);

	EXPECT_TRUE(graph.adjacencyList(3).empty());
}
