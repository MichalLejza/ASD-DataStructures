#ifndef EVERYTHING_DFS_HPP
#define EVERYTHING_DFS_HPP

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Graph/Graph.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Stack/Stack.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Queue/Queue.cpp"

#pragma once

LinkedList::LinkedList<int> *DFS(Graph::DirectedGraph<int> *graph, int data)
{
    Node::GraphNode<int> *start = nullptr;
    for (auto a : graph -> getNodes())
        if (a->getData() == data)
            start = a;
    std::vector<bool> Checked = std::vector<bool>(graph -> getSize(), false);
    auto *S = new Stack::Stack<Node::GraphNode<int> *>();
    auto *L = new LinkedList::LinkedList<int>();

    S -> push(start);
    Checked.at(start -> getData()) = true;

    while (!S -> isEmpty())
    {
        auto *temp = S -> getTop();
        S -> pop();
        L -> pushBack(temp -> getData());

        for (auto a : temp -> connectedNodes)
            if (!Checked[a->getData()])
            {
                S->push(a);
                Checked.at(a -> getData()) = true;
            }
    }
    return L;
}


#endif //EVERYTHING_DFS_HPP
