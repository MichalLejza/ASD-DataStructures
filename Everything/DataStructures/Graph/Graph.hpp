#ifndef EVERYTHING_GRAPH_HPP
#define EVERYTHING_GRAPH_HPP

#pragma once

#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.hpp"
#include <iostream>
#include <map>
#include <set>
#include <random>

namespace Graph
{
    template<typename T>
    class DirectedGraph
    {
        std::set<Node::GraphNode<T> *> nodes;
    public:
        DirectedGraph();
        ~DirectedGraph() = default;
        void addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal);
        void addNode(T one, T two);
        void deleteNode(Node::GraphNode<T> *node);
        void deleteNode(T value);
        void printGraph();
    };

    template<typename T>
    class WeightedGraph
    {
        std::set<Node::WeightedGraphNode<T> *> nodes;
    public:
        WeightedGraph() = default;
        ~WeightedGraph() = default;
        WeightedGraph<T> &operator = (const WeightedGraph<T> &value);
        void addNode(T one, T two, ssize_t weight);
        void deleteNode(T value);
        void changeWeight(T one, T two, ssize_t weight);
        void printGraph();
    };
}

#endif //EVERYTHING_GRAPH_HPP
