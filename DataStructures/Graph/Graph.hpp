#ifndef EVERYTHING_GRAPH_HPP
#define EVERYTHING_GRAPH_HPP

#pragma once

#include "/DataStructures/Node/Node.hpp"
#include <iostream>
#include <map>
#include <set>
#include <random>

namespace Graph
{
    template<typename T>
    class Graph
    {
        std::set<Node::GraphNode<T> *>nodes;
    public:
        Graph();
        explicit Graph(std::map<T,std::vector<T>> &connection);
        ~Graph() = default;
        void addNode(std::map<T,std::vector<T>> &connection);
        void addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal);
        void addNode(T one, T two);
        void deleteNode(Node::GraphNode<T> *node);
        void deleteNode(T value);
        void printGraph();
        int getSize();
        Node::GraphNode<T> *getNode(T data);
        std::set<Node::GraphNode<T> *> getNodes();
        void clear();
    };

    template<typename T>
    class DirectedGraph
    {
        std::set<Node::GraphNode<T> *> nodes;
    public:
        DirectedGraph();
        ~DirectedGraph() = default;
        void addNode(std::map<T,std::vector<T>> &nodes);
        void addNode(Node::GraphNode<T> *node, Node::GraphNode<T> *goal);
        void addNode(T one, T two);
        void deleteNode(Node::GraphNode<T> *node);
        void deleteNode(T value);
        void printGraph();
        int getSize();
        Node::GraphNode<T> *getNode(T data);
        std::set<Node::GraphNode<T> *> getNodes();
    };

    template<typename T>
    class WeightedGraph
    {
        std::set<Node::WeightedGraphNode<T> *> nodes;
    public:
        WeightedGraph();
        ~WeightedGraph() = default;
        void addNode(std::map<T,std::pair<T, ssize_t>> &connections);
        void addNode(Node::WeightedGraphNode<T> *node, Node::WeightedGraphNode<T> *goal, ssize_t weight);
        void addNode(T one, T two, ssize_t weight);
        void deleteNode(T value);
        void deleteNode(Node::WeightedGraphNode<T> *node);
        void changeWeight(T one, T two, ssize_t weight);
        void printGraph();
        int getSize();
        Node::WeightedGraphNode<T> *getNode(T data);
        std::set<Node::WeightedGraphNode<T> *> getNodes();
    };
}

#endif //EVERYTHING_GRAPH_HPP
