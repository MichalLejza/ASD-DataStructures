#ifndef EVERYTHING_BFS_HPP
#define EVERYTHING_BFS_HPP

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Graph/Graph.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Stack/Stack.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Queue/Queue.cpp"

#pragma once

LinkedList::LinkedList<int> *BFS(Graph::DirectedGraph<int> *graph, int data)
{
    Node::GraphNode<int> *start = nullptr;
    for (auto a : graph -> getNodes())
        if (a->getData() == data)
            start = a;
    std::vector<bool> Checked = std::vector<bool>(graph -> getSize(), false);
    auto *Q = new Queue::Queue<Node::GraphNode<int> *>();
    auto *L = new LinkedList::LinkedList<int>();

    Q -> push(start);
    Checked.at(start -> getData()) = true;

    while (!Q -> empty())
    {
        auto *temp = Q -> getHead();
        Q -> pop();
        L -> pushBack(temp -> getData());

        for (auto a : temp -> connectedNodes)
            if (!Checked[a->getData()])
            {
                Q -> push(a);
                Checked.at(a -> getData()) = true;
            }
    }
    return L;
}


#endif //EVERYTHING_BFS_HPP
