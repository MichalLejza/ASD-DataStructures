#ifndef EVERYTHING_TREE_HPP
#define EVERYTHING_TREE_HPP

#pragma once
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"

namespace Tree
{
    template<typename T>
    class Tree
    {
        Node::TreeNode<T> *root;
    public:
        Tree();
        ~Tree() = default;
        explicit Tree(T data);
        explicit Tree(Node::TreeNode<T> *node);
        Node::TreeNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::TreeNode<T> *node);
        void print();
        void addNode(T data);
        void addNode(Node::TreeNode<T> *node);
        void removeNode(T data);
        void removeNode(Node::TreeNode<T> *node);
    };

    template<typename T>
    class BTree
    {
        Node::BNode<T> *root;
    public:
        BTree();
        ~BTree() = default;
        explicit BTree(T data);
        explicit BTree(Node::BNode<T> *node);
        Node::BNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        void print();
        void addNode(T data);
        void addNode(Node::BNode<T> *node);
        void removeNode(T data);
        void removeNode(Node::BNode<T> *node);
    };

    template<typename T>
    class BSTree
    {
        Node::BNode<T> *root;
        void printBT(const std::string& prefix,Node::BNode<T>* node, bool isLeft);
        Node::BNode<T> *addingNode(Node::BNode<T> *node, T data);
        Node::BNode<T> *addingNode(Node::BNode<T> *node, Node::BNode<T> *newNode);
    public:
        BSTree();
        ~BSTree() = default;
        explicit BSTree(T data);
        explicit BSTree(Node::BNode<T> *node);
        Node::BNode<T> *getRoot();
        void setRoot(T data);
        void setRoot(Node::BNode<T> *node);
        void print();

        template<typename ...Args>
        void insert(const T &value, Args ...args);
        void addNode(T data);
        void addNode(Node::BNode<T> *node);
        void removeNode(T data);
        void removeNode(Node::BNode<T> *node);
        int getHeight();
        int countNodes();
    };

    template<typename T>
    class AVLTree
    {

    };
}

#endif //EVERYTHING_TREE_HPP
