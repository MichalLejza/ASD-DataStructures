#ifndef EVERYTHING_TREE_HPP
#define EVERYTHING_TREE_HPP

#include "/DataStructures/Node/Node.cpp"
#include "/DataStructures/LinkedList/LinkedList.cpp"

#pragma once

namespace Tree
{
    template<typename T>
    class BTree
    {
        Node::BNode<T> *root;
        void printBT(const std::string& prefix,Node::BNode<T>* node, bool isLeft);
    public:
        BTree();
        ~BTree() = default;
        explicit BTree(T data);
        explicit BTree(Node::BNode<T> *node);
        Node::BNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        void print();
    };

    template<typename T>
    class BSTree
    {
        Node::BNode<T> *root;
        Node::BNode<T> *removingNode(Node::BNode<T> *node, T data);
        Node::BNode<T> *removingNode(Node::BNode<T> *node, Node::BNode<T> *searchedNode);
        int gettingHeight(Node::BNode<T> *node);
        int gettingCount(Node::BNode<T> *node);
        Node::BNode<T> *findMinValue(Node::BNode<T> *node);
        void getFullValueTreeOfHeight(Node::BNode<T> *node, int height, T value);
        void fillValueTree(Node::BNode<T> *ogNode, Node::BNode<T> *node);
        void printFancyTree(LinkedList::LinkedList<Node::BNode<T> *> *list, int height, int minValue, int currentHeight);
    public:
        BSTree();
        ~BSTree() = default;
        explicit BSTree(T data);
        explicit BSTree(Node::BNode<T> *node);
        Node::BNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        T getMinValue();
        T getMaxValue();
        template<typename ...Args>
        void insert(const T &value, Args ...args);
        void addNode(T data);
        void addNode(Node::BNode<T> *node);
        void removeNode(T data);
        void removeNode(Node::BNode<T> *node);
        int getHeight();
        int countNodes();
        void print();
    };

    template<typename T>
    class AVLTree
    {
        Node::BNode<T> *root;
        Node::BNode<T> *rotateLeft(Node::BNode<T> *node);
        Node::BNode<T> *rotateRight(Node::BNode<T> *node);
        Node::BNode<T> *addingNode(Node::BNode<T> *node, T data, int height);
        Node::BNode<T> *addingNode(Node::BNode<T> *node, Node::BNode<T> *newNode, int height);
        Node::BNode<T> *removingNode(Node::BNode<T> *node, T data);
        Node::BNode<T> *removingNode(Node::BNode<T> *node, Node::BNode<T> *searchedNode);
        int gettingHeight(Node::BNode<T> *node);
        int gettingCount(Node::BNode<T> *node);
        Node::BNode<T> *findMinValue(Node::BNode<T> *node);
        void getFullValueTreeOfHeight(Node::BNode<T> *node, int height, T value);
        void fillValueTree(Node::BNode<T> *ogNode, Node::BNode<T> *node);
        void printFancyTree(LinkedList::LinkedList<Node::BNode<T> *> *list, int height, int minValue, int currentHeight);

    public:
        AVLTree();
        ~AVLTree() = default;
        explicit AVLTree(T data);
        explicit AVLTree(Node::BNode<T> *node);
        void addNode(T data);
        void addNode(Node::BNode<T> *node);
        void removeNode(T data);
        void removeNode(Node::BNode<T> *node);
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        T minValue();
        T maxValue();
        template<typename ...Args>
        void insert(const T &value, Args ...args);
        int getHeight();
        int countNodes();
        void print();
    };
}

#endif //EVERYTHING_TREE_HPP
