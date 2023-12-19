#include "Node.hpp"
#pragma once

template<typename T>
Node::Node<T>::Node(T data) : data(data) {}

template<typename T>
void Node::Node<T>::printNode()
{
    std::cout << this -> data << std::endl;
}

template<typename T>
void Node::Node<T>::setData(T update)
{
    this -> data = update;
}

template<typename T>
T Node::Node<T>::getData() const
{
    return this -> data;
}

template<typename T>
void Node::Node<T>::applyFunction(const std::function<void(T &)> &lambda)
{
    lambda(this -> data);
}

template<typename T>
bool Node::Node<T>::applyFilter(const std::function<bool(T &)> &lambda)
{
    return lambda(this -> data);
}

template<typename T>
bool Node::Node<T>::isInteger() const
{
    return std::is_integral<T>::value;
}

template<typename T>
bool Node::Node<T>::isDouble() const
{
    return std::is_same_v<double, T>;
}

template<typename T>
bool Node::Node<T>::isString() const
{
    return std::is_same_v<std::string, T>;
}

template<typename T>
bool Node::Node<T>::isEqual(Node<T> *node)
{
    return this -> data == node -> data;
}

template<typename T>
bool Node::Node<T>::isGreaterThen(Node<T> *node)
{
    return this -> data > node -> data;
}

template<typename T>
bool Node::Node<T>::isLesserThen(Node<T> *node)
{
    return this -> data < node -> data;
}



template<typename T>
Node::LinkedNode<T>::LinkedNode(T data) : Node<T>(data), next(nullptr) {}

template<typename T>
void Node::LinkedNode<T>::setNext(LinkedNode<T> *nextNode)
{
    this -> next = nextNode;
}

template<typename T>
void Node::LinkedNode<T>::setNext(T data)
{
    this -> next = new LinkedNode<T>(data);
}

template<typename T>
Node::LinkedNode<T>* Node::LinkedNode<T>::getNext()
{
    return this -> next;
}



template<typename T>
Node::DoubleLinkedNode<T>::DoubleLinkedNode(T data) : Node<T>(data), next(nullptr), previous(nullptr) {}

template<typename T>
void Node::DoubleLinkedNode<T>::setNext(DoubleLinkedNode <T> *nextNode)
{
    this -> next = nextNode;
}

template<typename T>
void Node::DoubleLinkedNode<T>::setNext(T data)
{
    this -> next = new DoubleLinkedNode<T>(data);
}

template<typename T>
void Node::DoubleLinkedNode<T>::setPrevious(DoubleLinkedNode <T> *previousNode)
{
    this -> previous = previousNode;
}

template<typename T>
void Node::DoubleLinkedNode<T>::setPrevious(T data)
{
    this -> previous = new DoubleLinkedNode<T>(data);
}

template<typename T>
Node::DoubleLinkedNode <T> *Node::DoubleLinkedNode<T>::getNext()
{
    return this -> next;
}

template<typename T>
Node::DoubleLinkedNode <T> *Node::DoubleLinkedNode<T>::getPrevious()
{
    return this -> previous;
}


template<typename T>
void Node::TreeNode<T>::printConnectedNodes()
{
    for (auto node : this -> nodes)
        std::cout << "[ " << this -> data << " ]  ";
    std::cout << std::endl;
}

template<typename T>
Node::TreeNode<T>::TreeNode(T data) : Node<T>(data)
{
    this -> nodes = std::set<TreeNode<T> *>();
}

template<typename T>
void Node::TreeNode<T>::addNode(TreeNode <T> *node)
{
    this -> nodes.insert(node);
}

template<typename T>
std::set<Node::TreeNode<T> *>Node::TreeNode<T>::getNodes()
{
    return this -> nodes;
}

template<typename T>
int Node::TreeNode<T>::nodesCounter()
{
    return this -> nodes.size();
}



template<typename T>
Node::BNode<T>::BNode(T data) : Node<T>(data), left(nullptr), right(nullptr), parent(nullptr), height(0) {}

template<typename T>
void Node::BNode<T>::setParent(BNode<T> *node)
{
    this -> parent = node;
}

template<typename T>
void Node::BNode<T>::setHeight(ssize_t data)
{
    this -> height = data;
}

template<typename T>
void Node::BNode<T>::updateHeight()
{
    this -> height = 1 + std::max(this -> left -> getHeight(), this -> right -> getHeight());
}

template<typename T>
Node::BNode <T> *Node::BNode<T>::rotateLeft()
{
    auto *y = this -> left;
    auto *T2 = y -> getRight();
    y -> setLeft(this);
    this -> right = T2;

    updateHeight();
    y -> updateHeight();
    return y;
}

template<typename T>
Node::BNode <T> *Node::BNode<T>::rotateRight()
{
    auto *x = this -> right;
    auto *T2 = x -> getLeft();
    x -> setRight(this);
    this -> left = T2;

    updateHeight();
    x -> updateHeight();
    return x;
}

template<typename T>
int Node::BNode<T>::getBalance()
{
    return this -> left -> getHeight() - this -> right -> getHeight();
}

template<typename T>
ssize_t Node::BNode<T>::getHeight()
{
    return this -> height;
}

template<typename T>
Node::BNode<T>::BNode(T data, bool red, bool black) : Node<T>(data), left(nullptr), right(nullptr), parent(nullptr), red(red), black(black), height(0) {}

template<typename T>
void Node::BNode<T>::setParent(T data)
{
    if (this -> parent == nullptr)
        this -> parent = new BNode<T>(data);
    else
        this -> parent -> setData(data);
}

template<typename T>
Node::BNode<T>* Node::BNode<T>::getLeft()
{
    return this -> left;
}

template<typename T>
Node::BNode<T> *Node::BNode<T>::getRight()
{
    return this -> right;
}

template<typename T>
Node::BNode<T> *Node::BNode<T>::getParent()
{
    return this -> parent;
}

template<typename T>
void Node::BNode<T>::setLeft(BNode<T> *node)
{
    this -> left = node;
}

template<typename T>
void Node::BNode<T>::setLeft(T data)
{
    if (this -> left == nullptr)
        this -> left = new BNode<T>(data);
    else
        this -> left -> setData(data);
}

template<typename T>
void Node::BNode<T>::setRight(BNode<T> *node)
{
    this -> right = node;
}

template<typename T>
void Node::BNode<T>::setRight(T data)
{
    if (this -> right == nullptr)
        this -> right = new BNode<T>(data);
    else
        this -> right -> setData(data);
}

template<typename T>
void Node::BNode<T>::setBlack()
{
    this -> red = false;
    this -> black = true;
}

template <typename T>
void Node::BNode<T>::setRed()
{
    this -> black = false;
    this -> red = true;
}

template<typename T>
bool Node::BNode<T>::isBlack()
{
    return this -> black;
}

template<typename T>
bool Node::BNode<T>::isRed()
{
    return this -> red;
}



template<typename T>
Node::GraphNode<T>::GraphNode(T data) : visited(false), Node<T>(data)
{
    this -> connectedNodes = std::set<GraphNode<T> *>();
}

template<typename T>
bool Node::GraphNode<T>::isVisited()
{
    return this -> visited;
}

template<typename T>
void Node::GraphNode<T>::setToVisited()
{
    this -> visited = true;
}

template<typename T>
void Node::GraphNode<T>::setToUnVisited()
{
    this -> visited = false;
}

template<typename T>
void Node::GraphNode<T>::deleteNode(GraphNode<T> *node)
{
    this -> connectedNodes.erase(node);
}

template<typename T>
void Node::GraphNode<T>::deleteNode(T data)
{
    auto *toDelete = new GraphNode<T>();
    for (auto a : connectedNodes)
        if (toDelete ->isEqual(a))
            toDelete = a;
    this -> connectedNodes.erase(toDelete);
}

template<typename T>
void Node::GraphNode<T>::addConnection(GraphNode<T> *node)
{
    this -> connectedNodes.insert(node);
}

template<typename T>
void Node::GraphNode<T>::addConnection(T data)
{
    auto *node = new GraphNode<T>(data);
    bool add = true;
    for (auto a : connectedNodes)
        if (node -> isEqual(a))
            add = false;
    if (add)
    {
        this -> connectedNodes.insert(node);
    }
}

template<typename T>
void Node::GraphNode<T>::printConnectedNodes()
{
    for (auto a : this -> connectedNodes)
        std::cout << "[ " << a -> data << " ],  ";
}

template<typename T>
ssize_t Node::GraphNode<T>::getSetSize()
{
    return this -> connectedNodes.size();
}



template<typename T>
Node::WeightedGraphNode<T>::WeightedGraphNode(T data) : Node<T>(data), visited(false)
{
    this -> connectedNodes = std::set<std::pair<WeightedGraphNode<T> *, ssize_t>>();
}

template<typename T>
std::set<std::pair<Node::WeightedGraphNode<T> *, ssize_t>> Node::WeightedGraphNode<T>::getConnectedNodes()
{
    return this -> connectedNodes;
}

template<typename T>
void Node::WeightedGraphNode<T>::setToVisited()
{
    this -> visited = false;
}

template<typename T>
void Node::WeightedGraphNode<T>::unVisitNode()
{
    this -> visited = false;
}

template<typename T>
bool Node::WeightedGraphNode<T>::isVisited()
{
    return this -> visited;
}

template<typename T>
void Node::WeightedGraphNode<T>::changeWeight(T data, ssize_t weight)
{
    for (auto a : this -> connectedNodes)
        if (a.first -> getData == data)
            a.second = weight;
}

template<typename T>
void Node::WeightedGraphNode<T>::addConnection(std::pair<WeightedGraphNode<T> * , ssize_t> node)
{
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node.first -> isEqual(a.first))
            add = false;
    if (add)
        this -> connectedNodes.insert(node);
}

template<typename T>
void Node::WeightedGraphNode<T>::addConnection(WeightedGraphNode<T> *node, ssize_t weight)
{
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node -> isEqual(a.first))
            add = false;
    if (add)
    {
        std::pair<WeightedGraphNode<T> *, ssize_t> para{node, weight};
        this -> connectedNodes.insert(para);
    }
}

template<typename T>
void Node::WeightedGraphNode<T>::addConnection(T data, ssize_t weight)
{
    auto *node = new WeightedGraphNode<T>(data);
    bool add = true;
    for (auto a : this -> connectedNodes)
        if (node -> isEqual(a.first))
            add = false;
    if (add)
    {
        std::pair<WeightedGraphNode<T> *, ssize_t> para{node, weight};
        this -> connectedNodes.insert(para);
    }
}

template<typename T>
void Node::WeightedGraphNode<T>::deleteNode(std::pair<WeightedGraphNode<T> * , ssize_t> node)
{
    for (auto a : this -> connectedNodes)
        if (a.first -> getData() == node.first -> getData())
            this -> connectedNodes.erase(a);
}

template<typename T>
void Node::WeightedGraphNode<T>::deleteNode(T data)
{
    for (auto a : this -> connectedNodes)
        if (a.first -> getData() == data)
            this -> connectedNodes.erase(a);
}

template<typename T>
void Node::WeightedGraphNode<T>::deleteNode(WeightedGraphNode<T> *node)
{
    for (auto a : this -> connectedNodes)
        if (a.first == node)
            this -> connectedNodes.erase(a);
}

template<typename T>
void Node::WeightedGraphNode<T>::printConnectedNodes()
{
    for (auto a : this -> connectedNodes)
        std::cout << "[ " << a.first -> data << " , " << a.second << " ]  ";
}

template<typename T>
ssize_t Node::WeightedGraphNode<T>::getSetSize()
{
    return this -> connectedNodes.size();
}
