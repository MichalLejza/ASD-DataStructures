#include "Everything/DataStructures/Graph/Graph.hpp"
#pragma once

template<typename T>
Graph::DirectedGraph<T>::DirectedGraph()
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
}

template<typename T>
void Graph::DirectedGraph<T>::addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal)
{
    node -> addConnection(goal);
    nodes.insert(node);
    nodes.insert(goal);
}

template<typename T>
void Graph::DirectedGraph<T>::addNode(T one, T two)
{
    auto *A = new Node::GraphNode<T>(one);
    auto *B = new Node::GraphNode<T>(two);
    for (auto a : nodes)
    {
        if (a -> getData() == one)
            A = a;
        if (a -> getData() == two)
            B = a;
    }
    addNode(A,B);
}

template<typename T>
void Graph::DirectedGraph<T>::deleteNode(Node::GraphNode<T> *node)
{
    for (auto n : nodes)
        n->deleteNode(node);
    nodes.erase(node);
}

template<typename T>
void Graph::DirectedGraph<T>::deleteNode(T value)
{

}

template<typename T>
void Graph::DirectedGraph<T>::printGraph()
{
    std::cout << "-printing graph nodes:" << std::endl;
    for (auto n : nodes)
    {
        std::cout << "Node : ";
        n->printNode();
        std::cout << "   ";
        if (n->getSetSize() != 0)
        {
            std::cout << "Connected nodes: ";
            n->printConnectedNodes();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


template<typename T>
Graph::WeightedGraph<T> &Graph::WeightedGraph<T>::operator=(const WeightedGraph<T> &value)
{
    if (this != &value)
    {
        nodes.clear();
    }
    else
    {
        for (const auto &element : value.connectedNodes)
        {
            nodes.insert(element);
        }
    }
    return *this;
}

template<typename T>
void Graph::WeightedGraph<T>::addNode(T one, T two, ssize_t weight)
{
    bool existsOne = false;
    bool existsTwo = false;
    Node::WeightedGraphNode<T> *firstNode = nullptr;
    Node::WeightedGraphNode<T> *secondNode = nullptr;
    for (auto a : nodes)
    {
        if (a->getData() == one)
        {
            existsOne = true;
            firstNode = a;
        }
        else if (a -> getData() == two)
        {
            existsTwo = true;
            secondNode = a;
        }
    }

    if (!existsOne)
    {
        auto *nodeOne = new Node::WeightedGraphNode<T>(one);
        nodes.insert(nodeOne);
        if (!existsTwo)
        {
            auto *nodeTwo = new Node::WeightedGraphNode<T>(two);
            nodes.insert(nodeTwo);
            nodeOne->addConnection(nodeTwo, weight);
        }
        else
        {
            nodeOne ->addConnection(secondNode, weight);
        }
    }
    else
    {
        if (!existsTwo)
        {
            auto *nodeTwo = new Node::WeightedGraphNode<T>(two);
            nodes.insert(nodeTwo);
            firstNode ->addConnection(nodeTwo, weight);
        }
        else
        {
            firstNode ->addConnection(secondNode, weight);
        }
    }

}

template<typename T>
void Graph::WeightedGraph<T>::deleteNode(T value)
{
    for (auto a : nodes)
        a -> deleteNode(value);
    for (auto a : nodes)
        if (a -> getData() == value)
            nodes.erase(a);
}

template<typename T>
void Graph::WeightedGraph<T>::changeWeight(T one, T two, ssize_t weight)
{
    for (auto a : nodes)
        if (a -> getData() == one)
            a->changeWeight(one, two, weight);
}

template<typename T>
void Graph::WeightedGraph<T>::printGraph()
{
    for (auto node : nodes)
    {
        std::cout << "Node: ";
        std::cout << node -> getData();
        node -> printConnectedNodes();
    }
}







