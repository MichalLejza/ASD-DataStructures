#ifndef EVERYTHING_LINKEDLIST_HPP
#define EVERYTHING_LINKEDLIST_HPP

#pragma once
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"
#include <iostream>
#include <sstream>
#include <cstdarg>
#include "functional"

namespace LinkedList
{
    template<typename T>
    class LinkedList
    {
        Node::LinkedNode<T> *head;
        ssize_t size{};

        Node::LinkedNode<T> *merge(Node::LinkedNode<T> *left, Node::LinkedNode<T> *right);
        void split(Node::LinkedNode<T> *source, Node::LinkedNode<T> **left, Node::LinkedNode<T> **right);
        void mergeSort(Node::LinkedNode<T> **headRef);

    public:
        LinkedList();
        explicit LinkedList(T data);
        explicit LinkedList(Node::LinkedNode<T> *node);
        ~LinkedList() = default;
        Node::LinkedNode<T> *getHead();
        template<typename ...Args>
        void insert(const T &value, Args ... args);
        void pushBack(T value);
        void pushBack(Node::LinkedNode<T> *node);
        void pushFront(T value);
        void pushFront(Node::LinkedNode<T> *node);
        void popFront();
        void popBack();
        void popElement(T value);
        void clear();
        void print();
        bool sorted();
        bool empty();
        ssize_t getSize();
        void sort();
        void map(std::function<void(T&)> fun);
        void filter(const std::function<bool(T&)> &fun);
    };

    template<typename T>
    class DoubleLinkedList
    {
        Node::DoubleLinkedNode<T> *head;
        ssize_t size{};

    public:
        DoubleLinkedList();
        explicit DoubleLinkedList(T data);
        explicit DoubleLinkedList(Node::DoubleLinkedNode<T> *node);
        ~DoubleLinkedList() = default;
        Node::DoubleLinkedNode<T> *getHead();
        void pushBack(T value);
        void pushBack(Node::LinkedNode<T> *node);
        void pushFront(T value);
        void pushFront(Node::LinkedNode<T> *node);
        void popFront();
        void popBack();
        void clear();
        void print();
        bool empty();
        ssize_t getSize();
    };
}

#endif //EVERYTHING_LINKEDLIST_HPP
