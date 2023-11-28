#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set>

struct Wezel
{
    std::string name;
    bool visited;
    std::vector<Wezel *> connectedTo;
    size_t numberOfConnectedNodes;
};
typedef struct Wezel Wezel;

auto createNewNode(std::string name)
{
    auto newNode = (Wezel *)(malloc(sizeof(Wezel)));
    newNode -> name = std::move(name);
    newNode -> visited = false;
    newNode -> numberOfConnectedNodes = 0;
    newNode -> connectedTo = std::vector<Wezel *>();
    return newNode;
}

auto createConnections(Wezel *node, Wezel **connected, size_t numberOfNodes) -> void
{
    node -> numberOfConnectedNodes = numberOfNodes;
    for(int i = 0; i < numberOfNodes; i++)
        node -> connectedTo.push_back(connected[i]);
}

auto checkCycle(Wezel *node, int &ileCykli) -> void
{
    // jeśli natrafliśmy na węzeł już odwiedzony, to napewno ten graf jest cykliczny
    if(node -> visited)
    {
        ileCykli++;
        return;
    }
    for(int i = 0; i < node -> numberOfConnectedNodes; i++)
    {
        node -> visited = true;
        if(node -> connectedTo.at(i) != nullptr)
            checkCycle(node -> connectedTo.at(i), ileCykli);
        node -> visited = false;
    }
}

auto has_cycle(const std::map<std::string, std::set<std::string>>& graph) -> void
{
    auto setOfNodes =  std::set<std::string>();
    for(const auto& a : graph)
    {
        setOfNodes.insert(a.first);
        for(const auto& b : a.second)
            setOfNodes.insert(b);
    }

    auto vecOfNodes = std::vector<Wezel *>();
    for(const auto& a : setOfNodes)
        vecOfNodes.push_back(createNewNode(a));

    auto **FromA = (Wezel **)(malloc(sizeof(Wezel) * 2));
    FromA[0] = vecOfNodes[1];
    FromA[1] = vecOfNodes[2];
    createConnections(vecOfNodes[0], FromA, 2);

    auto **FromB = (Wezel **)(malloc(sizeof(Wezel) * 1));
    FromB[0] = vecOfNodes[4];
    createConnections(vecOfNodes[1], FromB, 1);

    auto **FromC = (Wezel **)(malloc(sizeof(Wezel) * 1));
    FromC[0] = vecOfNodes[3];
    createConnections(vecOfNodes[2], FromC, 1);

    auto **FromD = (Wezel **)(malloc(sizeof(Wezel) * 1));
    FromD[0] = vecOfNodes[1];
    createConnections(vecOfNodes[3], FromD, 1);


    int cykle = 0;

    for(auto & vecOfNode : vecOfNodes)
    {
        checkCycle(vecOfNode, cykle);
        if(cykle > 0)
        {
            std::cout << "Graf jest cykliczny";
            exit(0);
        }
    }
    std::cout << "Graf nie jest cykliczny";
}

auto main() -> int
{
    auto graph = std::map<std::string, std::set<std::string>>();
    graph["A"] = {"B", "C"};
    graph["B"] = {"E"};
    graph["C"] = {"D"};
    graph["D"] = {"B"};

    has_cycle(graph);

    return 0;
}