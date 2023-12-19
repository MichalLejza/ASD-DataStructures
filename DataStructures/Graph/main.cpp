#include "Graph.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"

auto main() -> int
{
    std::map<int, std::vector<int>> connections;
    connections[0] = {1,2,4,7};
    connections[1] = {0,4,5};
    connections[2] = {0,3,5};
    connections[3] = {2,5};
    connections[4] = {0,1,6};
    connections[5] = {1,2,3,6};
    connections[6] = {4,5,7};
    connections[7] = {0,6};
    auto *graph = new Graph::Graph<int>(connections);
    graph -> printGraph();

    return 0;
}
