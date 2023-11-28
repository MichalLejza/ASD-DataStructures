#include "Stack.hpp"

template<typename T>
Stack::Stack<T>::Stack() : size(0), head(nullptr) {}

template<typename T>
Stack::Stack<T>::Stack(T data) : size(1), head(new Node::LinkedNode<T>(data)) {}

template<typename T>
Stack::Stack<T>::Stack(Node::LinkedNode<T> *headNode) : size(1)
{
    this -> head = headNode;
}

template<typename T>
template<typename ...Args>
void Stack::Stack<T>::insert(const T &value, Args ...args)
{
    push(value);
    if constexpr (sizeof...(args) > 0)
        insert(args...);
}

template<typename T>
T Stack::Stack<T>::getTop()
{
    return this -> head -> getData();
}

template<typename T>
void Stack::Stack<T>::pop()
{
    auto *temp = this -> head -> getNext();
    this -> head = temp;
    delete temp;
    this -> size--;
}

template<typename T>
bool Stack::Stack<T>::isEmpty()
{
    return this -> head == nullptr;
}

template<typename T>
ssize_t Stack::Stack<T>::getSize()
{
    return this -> size;
}

template<typename T>
void Stack::Stack<T>::push(T data)
{
    if (this -> head == nullptr)
    {
        this -> head = new Node::LinkedNode<T>(data);
        this -> size++;
    }
    else
    {
        auto *temp = new Node::LinkedNode<T>(data);
        temp -> setNext(head);
        this -> head = temp;
        this -> size++;
    }

}

template<typename T>
void Stack::Stack<T>::push(Node::LinkedNode<T> *node)
{
    if (this -> head == nullptr)
    {
        this -> head = node;
        this -> size = 1;
    }
    else
    {
        node -> setNext(this -> head);
        this -> head = node;
        delete node;
        this -> size++;
    }
}

template<typename T>
void Stack::Stack<T>::print()
{
    auto *temp = this -> head;
    while (temp != nullptr)
    {
        std::cout << temp -> getData() << " -> ";
        temp = temp -> getNext();
    }
}