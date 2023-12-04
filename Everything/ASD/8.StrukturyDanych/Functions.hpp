#ifndef EVERYTHING_FUNCTIONS_HPP
#define EVERYTHING_FUNCTIONS_HPP

#include "/Everything/DataStructures/Graph/Graph.cpp"
#include "/Everything/DataStructures/LinkedList/LinkedList.cpp"
#include "/Everything/DataStructures/Stack/Stack.cpp"
#include "/Everything/DataStructures/Queue/Queue.cpp"

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
    auto *temp = new Node::GraphNode<int>();

    S -> push(start);
    Checked.at(start -> getData()) = true;

    while (!S -> isEmpty())
    {
        temp = S -> getTop();
        S -> pop();
        L -> pushBack(temp -> getData());

        for (auto a : temp -> connectedNodes)
        {
            if (!Checked[a->getData()])
            {
                S->push(a);
                Checked.at(a -> getData()) = true;
            }
        }
    }
    return L;
}

LinkedList::LinkedList<int> *BFS(Graph::DirectedGraph<int> *graph, int data)
{
    Node::GraphNode<int> *start = nullptr;
    for (auto a : graph -> getNodes())
        if (a->getData() == data)
            start = a;
    std::vector<bool> Checked = std::vector<bool>(graph -> getSize(), false);
    auto *Q = new Queue::Queue<Node::GraphNode<int> *>();
    auto *L = new LinkedList::LinkedList<int>();
    auto *temp = new Node::GraphNode<int>();

    Q->push(start);
    Checked.at(start -> getData()) = true;

    while (!Q -> empty())
    {
        temp = Q -> getHead();
        Q -> pop();
        L ->pushBack(temp -> getData());

        for (auto a : temp -> connectedNodes)
        {
            if (!Checked[a->getData()])
            {
                Q -> push(a);
                Checked.at(a -> getData()) = true;
            }
        }
    }
    return L;
}

#endif //EVERYTHING_FUNCTIONS_HPP
