#include <gtest/gtest.h>
#include <Graph.h>

TEST(AssertTest, AddEdge)
{
	Graph graph(3, Graph::DirectionType::UNDIRECTED);
	
	EXPECT_NO_THROW(graph.addEdge(1, 2));
	EXPECT_THROW(graph.addEdge(4, 2), std::runtime_error);
}

TEST(AssertTest, GetEdge)
{
	Graph graph(3, Graph::DirectionType::UNDIRECTED);

	Graph::IndexT edgeIndex = graph.addEdge(1, 2);
	EXPECT_EQ(edgeIndex, 0);
	EXPECT_NO_THROW(graph.edge(0));

	EXPECT_THROW(graph.edge(1), std::runtime_error);
	EXPECT_THROW(graph.edge(2), std::runtime_error);
}

TEST(AssertTest, GetAdjacencyList)
{
	Graph graph(2, Graph::DirectionType::UNDIRECTED);
	EXPECT_NO_THROW(graph.addEdge(0, 1));

	EXPECT_NO_THROW(graph.adjacencyList(0));
	EXPECT_NO_THROW(graph.adjacencyList(1));

	EXPECT_THROW(graph.adjacencyList(2), std::runtime_error);
	EXPECT_THROW(graph.adjacencyList(3), std::runtime_error);
}
