#include "Graph.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"

auto main() -> int
{
    auto *graph = new Graph::WeightedGraph<std::string>();

    graph ->addNode("A", "B", 9);
    graph ->addNode("B", "C", 12);
    graph ->addNode("D", "C", 8);
    graph ->addNode("E", "D", 0);
    graph ->addNode("A", "E", 3);
    graph -> printGraph();
    graph ->deleteNode("A");
    graph->printGraph();

    return 0;
}
