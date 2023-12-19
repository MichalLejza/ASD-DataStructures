#ifndef EVERYTHING_NODE_HPP
#define EVERYTHING_NODE_HPP

#pragma once

#include "iostream"
#include "memory"
#include "cstdlib"
#include "limits"
#include "set"
#include "string"
#include "utility"
#include "functional"

namespace Node
{
    template<typename T>
    class Node
    {
    protected:
        T data;
    public:
        Node() = default;
        explicit Node(T data);
        ~Node() = default;
        void printNode();
        void setData(T data);
        T getData() const;
        void applyFunction(const std::function<void(T&)> &lambda);
        bool applyFilter(const std::function<bool(T&)> &lambda);
        [[nodiscard]] bool isInteger() const;
        [[nodiscard]] bool isDouble() const;
        [[nodiscard]] bool isString() const;
        bool isEqual(Node<T> *node);
        bool isGreaterThen(Node<T> *node);
        bool isLesserThen(Node<T> *node);
    };


    template<typename T>
    class LinkedNode : public Node<T>
    {
        LinkedNode<T> *next;
    public:
        LinkedNode() = default;
        explicit LinkedNode(T data);
        ~LinkedNode() = default;
        void setNext(LinkedNode<T> *next);
        void setNext(T data);
        LinkedNode<T> *getNext();
    };


    template<typename T>
    class DoubleLinkedNode : public Node<T>
    {
        DoubleLinkedNode<T> *next, *previous;
    public:
        DoubleLinkedNode() = default;
        explicit DoubleLinkedNode(T data);
        ~DoubleLinkedNode() = default;
        void setNext(DoubleLinkedNode<T> *next);
        void setNext(T data);
        void setPrevious(DoubleLinkedNode<T> *previous);
        void setPrevious(T data);
        DoubleLinkedNode<T> *getNext();
        DoubleLinkedNode<T> *getPrevious();
    };


    template<typename T>
    class TreeNode : public Node<T>
    {
        std::set<TreeNode<T> *> nodes;
    public:
        TreeNode() = default;
        explicit TreeNode(T data);
        ~TreeNode() = default;
        void printConnectedNodes();
        void addNode(TreeNode<T> *node);
        std::set<TreeNode<T> *> getNodes();
        int nodesCounter();
    };

    template<typename T>
    class BNode : public Node<T>
    {
        bool red{}, black{};
        ssize_t height{};
        BNode<T> *left, *right, *parent;
    public:
        BNode() = default;
        explicit BNode(T data);
        BNode(T data, bool red, bool black);
        ~BNode() = default;
        void setHeight(ssize_t data);
        void updateHeight();
        BNode<T> *rotateLeft();
        BNode<T> *rotateRight();
        int getBalance();
        ssize_t getHeight();
        void setParent(BNode<T> *node);
        void setParent(T data);
        void setLeft(BNode<T> *node);
        void setLeft(T data);
        void setRight(BNode<T> *node);
        void setRight(T data);
        void setBlack();
        void setRed();
        bool isBlack();
        bool isRed();
        BNode<T> *getLeft();
        BNode<T> *getRight();
        BNode<T> *getParent();
    };


    template<typename T>
    class GraphNode : public Node<T>
    {
    public:
        bool visited {};
        std::set<GraphNode<T> *> connectedNodes;
        GraphNode() = default;
        explicit GraphNode(T data);
        ~GraphNode() = default;
        bool isVisited();
        void setToVisited();
        void setToUnVisited();
        void addConnection(GraphNode<T> *node);
        void addConnection(T data);
        void deleteNode(GraphNode<T> *node);
        void deleteNode(T data);
        void printConnectedNodes();
        ssize_t getSetSize();
    };


    template<typename T>
    class WeightedGraphNode : public Node<T>
    {
    public:
        bool visited {};
        std::set<std::pair<WeightedGraphNode<T> *, ssize_t>> connectedNodes;
    public:
        WeightedGraphNode() = default;
        explicit WeightedGraphNode(T data);
        ~WeightedGraphNode() = default;
        std::set<std::pair<WeightedGraphNode<T> *, ssize_t>> getConnectedNodes();
        bool isVisited();
        void setToVisited();
        void unVisitNode();
        void changeWeight(T data, ssize_t weight);
        void addConnection(std::pair<WeightedGraphNode<T> *, ssize_t> node);
        void addConnection(WeightedGraphNode<T> *node, ssize_t weight);
        void addConnection(T data, ssize_t weight);
        void deleteNode(std::pair<WeightedGraphNode<T> *, ssize_t> node);
        void deleteNode(WeightedGraphNode<T> * node);
        void deleteNode(T data);
        void printConnectedNodes();
        ssize_t getSetSize();
    };
}


#endif //EVERYTHING_NODE_HPP
