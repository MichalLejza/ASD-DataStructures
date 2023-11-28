#include "Tree.hpp"

#pragma once

template<typename T>
Tree::Tree<T>::Tree() : root(nullptr) {}

template<typename T>
Tree::Tree<T>::Tree(T data) : root(new Node::TreeNode<T>(data)) {}

template<typename T>
Tree::Tree<T>::Tree(Node::TreeNode<T> *node) : root(node) {}

template<typename T>
Node::TreeNode<T> *Tree::Tree<T>::getRoot()
{
    return this -> root;
}

template<typename T>
void Tree::Tree<T>::setRoot(T data)
{
    if (this -> root == nullptr)
    {
        this -> root = new Node::TreeNode<T>(data);
    }
    else
    {
        this -> root -> setData(data);
    }
}

template<typename T>
void Tree::Tree<T>::setRoot(Node::TreeNode<T> *node)
{
    if (this -> root == nullptr)
    {
        this -> root = node;
    }
    else
    {
        this -> root -> setData(node);
    }
}

template<typename T>
void Tree::Tree<T>::print()
{

}

template<typename T>
void Tree::Tree<T>::addNode(T data)
{
    this -> root -> addNode(new Node::TreeNode<T>(data));
}

template<typename T>
void Tree::Tree<T>::addNode(Node::TreeNode<T> *node)
{
    this -> root -> addNode(node);
}

template<typename T>
void Tree::Tree<T>::removeNode(T data)
{

}


template<typename T>
void Tree::Tree<T>::removeNode(Node::TreeNode<T> *node)
{

}








template<typename T>
Tree::BSTree<T>::BSTree() : root(nullptr) {}

template<typename T>
Tree::BSTree<T>::BSTree(T data) : root(new Node::BNode<T>(data)) {}

template<typename T>
Tree::BSTree<T>::BSTree(Node::BNode<T> *node) : root(node) {}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::getRoot()
{
    return this -> root;
}

template<typename T>
void Tree::BSTree<T>::setRoot(T data)
{
    if (this -> root == nullptr)
    {
        this -> root = new Node::BNode<T>(data);
    }
    else
    {
        this -> root -> setData(data);
    }
}

template<typename T>
void Tree::BSTree<T>::setRoot(Node::BNode<T> *node)
{
    if (this -> root == nullptr)
    {
        this -> root = node;
    }
    else
    {
        this -> root -> setData(node);
    }
}

template<typename T>
void Tree::BSTree<T>::printBT(const std::string &prefix,Node::BNode<T> *node, bool isLeft)
{
    if (node != nullptr)
    {
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──" );
        std::cout << node -> getData() << std::endl;
        printBT( prefix + (isLeft ? "│   " : "    "), node -> getLeft(), true);
        printBT( prefix + (isLeft ? "│   " : "    "), node -> getRight(), false);
    }
}

template<typename T>
void Tree::BSTree<T>::print()
{
    printBT("", this -> root, false);
}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::addingNode(Node::BNode<T> *node, T data)
{
    if (node == nullptr)
    {
        return new Node::BNode<T> (data);
    }
    if (data > node -> getData())
    {
        node -> setRight(addingNode(node -> getRight(), data));
    }
    else if (data < node -> getData())
    {
        node -> setLeft(addingNode(node -> getLeft(), data));
    }
    return node;
}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::addingNode(Node::BNode<T> *node, Node::BNode<T> *newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (newNode -> getData() > node -> getData())
    {
        node -> setRight(addingNode(node -> getRight()), newNode);
    }
    else if (newNode -> getData() < node -> getData())
    {
        node -> setLeft(addingNode(node -> getLeft()), newNode);
    }
    return node;
}

template<typename T>
template<typename ...Args>
void Tree::BSTree<T>::insert(const T &value, Args ...args)
{
    addNode(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
void Tree::BSTree<T>::addNode(T data)
{
    this -> root = addingNode(this -> root, data);
}

template<typename T>
void Tree::BSTree<T>::addNode(Node::BNode<T> *node)
{
    this -> root = addingNode(this -> root, node);
}

template<typename T>
void Tree::BSTree<T>::removeNode(T data)
{

}

template<typename T>
void Tree::BSTree<T>::removeNode(Node::BNode<T> *node)
{

}

template<typename T>
int Tree::BSTree<T>::getHeight()
{

}


template<typename T>
int Tree::BSTree<T>::countNodes()
{

}




