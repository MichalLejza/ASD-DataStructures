#include "Graph.hpp"

#pragma once

template<typename T>
Graph::Graph<T>::Graph()
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
}

template<typename T>
Graph::Graph<T>::Graph(std::map<T, std::vector<T>> &connection)
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
    addNode(connection);
}

template<typename T>
void Graph::Graph<T>::addNode(std::map<T, std::vector<T>> &connections)
{
    for (auto &node : connections)
    {
        auto *A = new Node::GraphNode<T>(node.first);
        std::vector<T> &values = node.second;
        for (auto a : this -> nodes)
            if (a -> getData() == A -> getData())
                A = a;

        for (auto a : values)
        {
            auto *B = new Node::GraphNode<T>(a);
            for (auto b : this -> nodes)
                if (b -> getData() == B -> getData())
                    B = b;
            A -> addConnection(B);
            this -> nodes.insert(A);
            this -> nodes.insert(B);
        }
    }
}

template<typename T>
void Graph::Graph<T>::addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal)
{
    node -> addConnection(goal);
    this -> nodes.insert(node);
    this -> nodes.insert(goal);
}

template<typename T>
void Graph::Graph<T>::addNode(T one, T two)
{
    auto *A = new Node::GraphNode<T>(one);
    auto *B = new Node::GraphNode<T>(two);
    for (auto a : this -> nodes)
    {
        if (a -> getData() == one)
            A = a;
        if (a -> getData() == two)
            B = a;
    }
    addNode(A,B);
}

template<typename T>
void Graph::Graph<T>::deleteNode(Node::GraphNode<T> *node)
{
    for (auto n : this -> nodes)
        n -> deleteNode(node);
    this -> nodes.erase(node);
}

template<typename T>
void Graph::Graph<T>::deleteNode(T value)
{
    for (auto a : this -> nodes)
        a -> deleteNode(value);
    for (auto a : this -> nodes)
        if (a -> getData() == value)
            this -> nodes.erase(a);
}

template<typename T>
void Graph::Graph<T>::printGraph()
{
    for (auto n : this -> nodes)
    {
        std::cout << "[" << n -> getData() << "] -> ";
        if (n -> getSetSize() != 0)
            n -> printConnectedNodes();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
int Graph::Graph<T>::getSize()
{
    return this -> nodes.size();
}

template<typename T>
Node::GraphNode<T> *Graph::Graph<T>::getNode(T data)
{
    auto *temp = new Node::GraphNode<T>();
    for (auto a : this -> nodes)
        if (a -> getData() == data)
            temp = a;
    return temp;
}

template<typename T>
std::set<Node::GraphNode<T> *> Graph::Graph<T>::getNodes()
{
    return this -> nodes;
}

template<typename T>
void Graph::Graph<T>::clear()
{
    this -> nodes.clear();
}






template<typename T>
Graph::DirectedGraph<T>::DirectedGraph()
{
    this -> nodes = std::set<Node::GraphNode<T> *>();
}

template<typename T>
void Graph::DirectedGraph<T>::addNode(std::map<T, std::vector<T>> &connections)
{
    for (auto &node : connections)
    {
        auto *A = new Node::GraphNode<T>(node.first);
        std::vector<T> &values = node.second;
        for (auto a : this -> nodes)
            if (a -> getData() == A -> getData())
                A = a;

        for (auto a : values)
        {
            auto *B = new Node::GraphNode<T>(a);
            for (auto b : this -> nodes)
                if (b -> getData() == B -> getData())
                    B = b;
            A -> addConnection(B);
            this -> nodes.insert(A);
            this -> nodes.insert(B);
        }
    }
}

template<typename T>
void Graph::DirectedGraph<T>::addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal)
{
    node -> addConnection(goal);
    this -> nodes.insert(node);
    this -> nodes.insert(goal);
}

template<typename T>
void Graph::DirectedGraph<T>::addNode(T one, T two)
{
    auto *A = new Node::GraphNode<T>(one);
    auto *B = new Node::GraphNode<T>(two);
    for (auto a : this -> nodes)
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
    for (auto n : this -> nodes)
        n -> deleteNode(node);
    this -> nodes.erase(node);
}

template<typename T>
void Graph::DirectedGraph<T>::deleteNode(T value)
{
    for (auto a : this -> nodes)
        a -> deleteNode(value);
    for (auto a : this -> nodes)
        if (a -> getData() == value)
            this -> nodes.erase(a);
}

template<typename T>
void Graph::DirectedGraph<T>::printGraph()
{
    for (auto n : this -> nodes)
    {
        std::cout << "[" << n -> getData() << "] -> ";
        if (n -> getSetSize() != 0)
            n -> printConnectedNodes();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
int Graph::DirectedGraph<T>::getSize()
{
    return this -> nodes.size();
}

template<typename T>
Node::GraphNode<T> *Graph::DirectedGraph<T>::getNode(T data)
{
    auto *temp = new Node::GraphNode<T>();
    for (auto a : this -> nodes)
        if (a -> getData() == data)
            temp = a;
    return temp;
}

template<typename T>
std::set<Node::GraphNode<T> *> Graph::DirectedGraph<T>::getNodes()
{
    return this -> nodes;
}



template<typename T>
Graph::WeightedGraph<T>::WeightedGraph()
{
    this -> nodes = std::set<Node::WeightedGraphNode<T> *>();
}

template<typename T>
void Graph::WeightedGraph<T>::addNode(std::map<T, std::pair<T, ssize_t>> &connections)
{
    for (auto &node : connections)
    {
        auto *A = new Node::WeightedGraphNode<T>(node.first);
        std::vector<std::pair<T, ssize_t>> &values = node.second;
        for (auto a : this -> nodes)
            if (a -> getData() == A -> getData())
                A = a;

        for (auto a : values)
        {
            auto *B = new Node::WeightedGraphNode<T>(a.first);
            for (auto b : this -> nodes)
                if (b -> getData() == B -> getData())
                    B = b;
            A -> addConnection(B, a.second);
            this -> nodes.insert(A);
            this -> nodes.insert(B);
        }
    }
}

template<typename T>
void
Graph::WeightedGraph<T>::addNode(Node::WeightedGraphNode<T> *node, Node::WeightedGraphNode<T> *goal, ssize_t weight)
{
    node -> addConnection(goal, weight);
    this -> nodes.insert(node);
    this -> nodes.insert(goal);
}

template<typename T>
void Graph::WeightedGraph<T>::addNode(T one, T two, ssize_t weight)
{
    auto *A = new Node::WeightedGraphNode<T>(one);
    auto *B = new Node::WeightedGraphNode<T>(two);
    for (auto a : this -> nodes)
    {
        if (a -> getData() == one)
            A = a;
        if (a -> getData() == two)
            B = a;
    }
    addNode(A, B, weight);
}

template<typename T>
void Graph::WeightedGraph<T>::deleteNode(T value)
{
    for (auto a : this -> nodes)
        a -> deleteNode(value);
    for (auto a : this -> nodes)
        if (a -> getData() == value)
            this -> nodes.erase(a);
}

template<typename T>
void Graph::WeightedGraph<T>::deleteNode(Node::WeightedGraphNode<T> *node)
{
    for (auto n : this -> nodes)
        n -> deleteNode(node);
    this -> nodes.erase(node);
}

template<typename T>
void Graph::WeightedGraph<T>::changeWeight(T one, T two, ssize_t weight)
{
    for (auto a : this -> nodes)
        if (a -> getData() == one)
            a -> changeWeight(one, two, weight);
}

template<typename T>
void Graph::WeightedGraph<T>::printGraph()
{
    for (auto n : this -> nodes)
    {
        std::cout << "[" << n -> getData() << "] -> ";
        if (n -> getSetSize() != 0)
            n -> printConnectedNodes();
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
int Graph::WeightedGraph<T>::getSize()
{
    return this -> nodes.size();
}

template<typename T>
Node::WeightedGraphNode<T> *Graph::WeightedGraph<T>::getNode(T data)
{
    auto *temp = new Node::WeightedGraphNode<T>();
    for (auto a : this -> nodes)
        if (a -> getData() == data)
            temp = a;
    return temp;
}

template<typename T>
std::set<Node::WeightedGraphNode<T> *> Graph::WeightedGraph<T>::getNodes()
{
    return this -> nodes;
}







