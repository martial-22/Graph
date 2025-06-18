#include <gtest/gtest.h>
#include <Graph.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
	// Expect two strings not to be equal.
	EXPECT_STRNE("hello", "world");
	// Expect equality.
	EXPECT_EQ(7 * 6, 42);
}

TEST(AssertTest, AddEdge)
{
	Graph graph(3);
	
	EXPECT_NO_THROW(graph.addEdge(1, 2));
	EXPECT_THROW(graph.addEdge(4, 2), std::runtime_error);
}
