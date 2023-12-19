#include "Tree.hpp"

#pragma once

template<typename T>
Tree::BTree<T>::BTree() : root(nullptr) {}

template<typename T>
Tree::BTree<T>::BTree(T data)
{
    this -> root = new Node::BNode<T>(data);
}

template<typename T>
Tree::BTree<T>::BTree(Node::BNode<T> *node) : root(node) {}

template<typename T>
Node::BNode<T> *Tree::BTree<T>::getRoot()
{
    return this -> root;
}

template<typename T>
void Tree::BTree<T>::setRoot(T data)
{
    this -> root = new Node::BNode<T>(data);
}

template<typename T>
void Tree::BTree<T>::setRoot(Node::BNode<T> *node)
{
    this -> root = node;
}

template<typename T>
void Tree::BTree<T>::printBT(const std::string &prefix,Node::BNode<T> *node, bool isLeft)
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
void Tree::BTree<T>::print()
{
    printBT("", this -> root, false);
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
        this -> root = new Node::BNode<T>(data);
    else if (this -> root -> getLeft() == nullptr && this -> root -> getRight() == nullptr)
        this -> root -> setData(data);
    else
        return;
}

template<typename T>
void Tree::BSTree<T>::setRoot(Node::BNode<T> *node)
{
    if (this -> root == nullptr || this -> root -> getLeft() == nullptr && this -> root -> getRight() == nullptr)
        this -> root = node;
    else
        return;
}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::removingNode(Node::BNode<T> *node, T data)
{
    if (node == nullptr)
        return node;
    if (data < node -> getData())
        node -> setLeft(removingNode(node -> getLeft(), data));
    else if (data > node -> getData())
        node ->setRight(removingNode(node -> getRight(), data));
    else
    {
        if (node -> getLeft() == nullptr)
        {
            Node::BNode<T> *temp = node -> getRight();
            delete node;
            return temp;
        }
        else if (node -> getRight() == nullptr)
        {
            Node::BNode<T> *temp = node -> getLeft();
            delete node;
            return temp;
        }
        Node::BNode<T> *temp = findMinValue(node -> getRight());
        node ->setData(temp -> getData());
        node ->setRight(removingNode(node -> getRight(), temp -> getData()));
    }
    return node;
}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::removingNode(Node::BNode<T> *node, Node::BNode<T> *searchedNode)
{
    if (node == nullptr)
        return node;
    if (searchedNode -> getData() < node -> getData())
        node -> setLeft(removingNode(node -> getLeft(), searchedNode -> getData()));
    else if (searchedNode -> getData() > node -> getData())
        node ->setRight(removingNode(node -> getRight(), searchedNode -> getData()));
    else
    {
        if (node -> getLeft() == nullptr)
        {
            Node::BNode<T> *temp = node -> getRight();
            delete node;
            return temp;
        }
        else if (node -> getRight() == nullptr)
        {
            Node::BNode<T> *temp = node -> getLeft();
            delete node;
            return temp;
        }
        Node::BNode<T> *temp = findMinValue(node -> getRight());
        node ->setData(temp -> getData());
        node ->setRight(removingNode(node -> getRight(), temp -> getData()));
    }
    return node;
}

template<typename T>
int Tree::BSTree<T>::gettingHeight(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return 1 + std::max(gettingHeight(node -> getLeft()), gettingHeight(node -> getRight()));
}

template<typename T>
int Tree::BSTree<T>::gettingCount(Node::BNode<T> *node)
{
    if (node == nullptr)
        return 0;
    else
        return gettingCount(node -> getLeft()) + gettingCount(node -> getRight()) + 1;
}

template<typename T>
Node::BNode<T> *Tree::BSTree<T>::findMinValue(Node::BNode<T> *node)
{
    while (node -> getLeft() != nullptr)
        node = node -> getLeft();
    return node;
}

template<typename T>
void Tree::BSTree<T>::getFullValueTreeOfHeight(Node::BNode<T> *node, int height, T value)
{
    if (height > 0)
    {
        node -> setLeft(value);
        node -> setRight(value);
        getFullValueTreeOfHeight(node -> getLeft(), height - 1, value);
        getFullValueTreeOfHeight(node -> getRight(), height - 1, value);
    }
}

template<typename T>
void Tree::BSTree<T>::fillValueTree(Node::BNode<T> *ogNode, Node::BNode<T> *node)
{
    if (ogNode != nullptr)
    {
        node -> setData(ogNode -> getData());
        node ->setHeight(ogNode -> getHeight());
        fillValueTree(ogNode -> getLeft(), node -> getLeft());
        fillValueTree(ogNode -> getRight(), node -> getRight());
    }
}

template<typename T>
void Tree::BSTree<T>::printFancyTree(LinkedList::LinkedList<Node::BNode<T> *> *list, int height, int minValue, int currentHeight)
{
    int size = list -> getSize();
    int pivot = (pow( 2,(height - currentHeight)) * 4) + ((pow(2, (height - currentHeight)) - 1 ) * 2);
    auto temp = std::vector<Node::BNode<T> *>();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < pivot / 2 - 2; j++)
            std::cout << " ";
        if (list -> getValue() -> getData() < 10 && list -> getValue() -> getData() > minValue)
            std::cout << "[ " << list -> getValue() -> getData() << "]";
        else if (list -> getValue() -> getData() < 100 && list -> getValue() -> getData() > minValue)
            std::cout << "[" << list -> getValue() -> getData() << "]";
        else if (list -> getValue() -> getData() == minValue)
            std::cout << "    ";

        for (int j = 0; j < pivot / 2; j++)
            std::cout << " ";
        list -> pushBack(list -> getValue() -> getLeft());
        list -> pushBack(list -> getValue() -> getRight());
        temp.push_back(list -> getValue());
        list -> popFront();
    }
    std::cout << std::endl;
    if (height - currentHeight != 0)
    {
        pivot = pivot / 2 - 2;
        for (int i = 0; i < pivot; i++)
            std::cout << " ";
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp.at(i) -> getLeft() != nullptr && temp.at(i) -> getLeft() -> getData() != minValue)
                std::cout << "/";
            else
                std::cout << " ";
            if (temp.at(i) -> getRight() != nullptr && temp.at(i) -> getRight() -> getData() != minValue)
                std::cout << "  \\";
            else
                std::cout << "   ";
            for (int j = 0; j < pivot * 2 + 2; j++)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
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
    if (this -> root == nullptr)
    {
        this -> root = new Node::BNode<T>(data);
        this -> root -> setHeight(0);
    }
    int height = 0;
    Node::BNode<T> *current = this -> root;
    Node::BNode<T> *parent = nullptr;
    auto *newNode = new Node::BNode<T>(data);

    while (current != nullptr)
    {
        parent = current;
        if (data > current -> getData())
            current = current -> getRight();
        else if (data < current -> getData())
            current = current -> getLeft();
        else
        {
            delete newNode;
            return;
        }
        height++;
    }
    newNode ->setHeight(height);
    if (data < parent -> getData())
        parent ->setLeft(newNode);
    else
        parent ->setRight(newNode);
}

template<typename T>
void Tree::BSTree<T>::addNode(Node::BNode<T> *node)
{
    node -> setHeight(0);
    if (this -> root == nullptr)
        this -> root = node;
    int height = 0;
    Node::BNode<T> *current = this -> root;
    Node::BNode<T> *parent = nullptr;

    while (current != nullptr)
    {
        parent = current;
        if (node -> getData() > current -> getData())
            current = current -> getRight();
        else if (node -> getData() < current -> getData())
            current = current -> getLeft();
        else
            return;
        height++;
    }
    node -> setHeight(height);
    if (node -> getData() < parent -> getData())
        parent ->setLeft(node);
    else
        parent ->setRight(node);
}

template<typename T>
void Tree::BSTree<T>::removeNode(T data)
{
    auto *temp = this -> root;
    this -> root = removingNode(temp, data);
}

template<typename T>
void Tree::BSTree<T>::removeNode(Node::BNode<T> *node)
{
    auto *temp = this -> root;
    this -> root = removingNode(temp, node);
}

template<typename T>
int Tree::BSTree<T>::getHeight()
{
    auto *temp = this -> root;
    return gettingHeight(temp);
}

template<typename T>
T Tree::BSTree<T>::getMinValue()
{
    auto *temp = this -> root;
    while (temp -> getLeft() != nullptr)
        temp = temp -> getLeft();
    return temp -> getData();
}

template<typename T>
T Tree::BSTree<T>::getMaxValue()
{
    auto *temp = this -> root;
    while (temp -> getRight() != nullptr)
        temp = temp -> getRight();
    return temp -> getRight();
}

template<typename T>
int Tree::BSTree<T>::countNodes()
{
    auto *temp = this -> head;
    return gettingCount(temp);
}

template<typename T>
void Tree::BSTree<T>::print()
{
    T minValue = getMinValue() - 1;
    int height = getHeight();
    auto *tree = new BTree<int>(minValue);
    getFullValueTreeOfHeight(tree -> getRoot(), height - 1, minValue);
    fillValueTree(this -> getRoot(), tree -> getRoot());
    auto *list = new LinkedList::LinkedList<Node::BNode<T> *>(tree -> getRoot());
    for (int i = 1; i <= height; i++)
        printFancyTree(list, height, minValue, i);
    delete tree;
}





template<typename T>
Tree::AVLTree<T>::AVLTree() : BSTree<T>() {}

template<typename T>
Tree::AVLTree<T>::AVLTree(T data) : BSTree<T>(data) {}

template<typename T>
Tree::AVLTree<T>::AVLTree(Node::BNode<T> *node) : BSTree<T>(node) {}

template<typename T>
void Tree::AVLTree<T>::addNode(T data)
{
    this -> root = addingNode(this -> getRoot(), data, 0);
}

template<typename T>
void Tree::AVLTree<T>::addNode(Node::BNode<T> *node)
{
    this -> root = addingNode(this -> getRoot(), node, 0);
}

template<typename T>
void Tree::AVLTree<T>::removeNode(T data)
{

}

template<typename T>
void Tree::AVLTree<T>::removeNode(Node::BNode<T> *node)
{

}

template<typename T>
void Tree::AVLTree<T>::setRoot(Node::BNode<T> *node)
{
    if (this -> root == nullptr)
        this -> root = node;
    else
        this -> root -> setData(node);
}

template<typename T>
void Tree::AVLTree<T>::setRoot(T data)
{
    if (this -> root == nullptr)
        this -> root = new Node::BNode<T>(data);
    else
        this -> root -> setData(data);
}

template<typename T>
T Tree::AVLTree<T>::minValue()
{
    
}

template<typename T>
T Tree::AVLTree<T>::maxValue()
{

}

template<typename T>
int Tree::AVLTree<T>::getHeight()
{

}

template<typename T>
int Tree::AVLTree<T>::countNodes()
{

}

template<typename T>
void Tree::AVLTree<T>::print()
{

}

template<typename T>
template<typename ...Args>
void Tree::AVLTree<T>::insert(const T &value, Args ...args)
{
    addNode(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::addingNode(Node::BNode<T> *node, T data, int height)
{

}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::addingNode(Node::BNode<T> *node, Node::BNode<T> *newNode, int height)
{

}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::rotateLeft(Node::BNode<T> *node)
{

}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::rotateRight(Node::BNode<T> *node)
{

}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::removingNode(Node::BNode<T> *node, T data)
{

}

template<typename T>
Node::BNode<T> *Tree::AVLTree<T>::removingNode(Node::BNode<T> *node, Node::BNode<T> *searchedNode)
{

}







