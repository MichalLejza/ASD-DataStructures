#ifndef EVERYTHING_ALGORITHMS_HPP
#define EVERYTHING_ALGORITHMS_HPP

#pragma once

#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"

template<typename T>
T findMax(std::vector<T> &E)
{
    T min = E.at(0);
    for (auto a : E)
        if (min < a)
            min = a;
    return min;
}

template<typename T>
void CountingSort(std::vector<T> &E)
{
    int max = findMax(E);
    auto Tmp = std::vector<T>(max + 1);
    auto out = std::vector<T>(E.size());

    for (int i = 0; i < E.size(); i++)
        Tmp[E.at(i)]++;

    for (int i = 1; i < max + 1; i++)
        Tmp.at(i) += Tmp.at(i - 1);

    for (int i = E.size() - 1; i>= 0; i--)
    {
        out.at(Tmp.at(E.at(i)) - 1) = E.at(i);
        Tmp.at(E.at(i)) = Tmp.at(E.at(i)) - 1;
    }
    E = out;
}

template<typename T>
void Merge(std::vector<T> &E, int i, int j)
{
    int n = j;
    int l = i;
    int r = n / 2;
    int k = 0;
    auto tempR = std::vector<T>(j - i);

    while ((l < n / 2) && (r < n))
    {
        if (E.at(r) > E.at(l))
            tempR.at(k) = E.at(l++);
        else
            tempR.at(k) = E.at(r++);
        k++;
    }

    if (l < n / 2)
        while (l < n / 2)
            tempR.at(k++) = E.at(l++);
    else
        while (r < n)
            tempR.at(k++) = E.at(r++);
    E = tempR;
}

template<typename T>
void MergeSort(std::vector<T> &E, int i, int j, int operation)
{
    int n = j - i;
    if (n > 1)
    {
        if (n / 2 > 1)
        {
            MergeSort(E, i, n / 2 - 1, operation);
        }
        if ((n - n / 2) > 1)
        {
            MergeSort(E, n/2, n - 1, operation);
        }
        Merge(E, i, j);
    }
}

template<typename T>
void RadixSort(std::vector<T> &E, int d)
{
    auto vec = std::vector<LinkedList::LinkedList<T> *>(10);
    for (int i = 0; i < 10; i++)
    {
        auto *element = new LinkedList::LinkedList<T>();
        vec.at(i) = element;
    }
    std::cout << "RADIX SORT" << std::endl;

    int multiplier = 10;
    int divider = 1;
    for (int i = 1; i <= d; i++)
    {
        for (int j = 0; j < E.size(); j++)
            vec.at((E.at(j) % multiplier) / divider) -> pushBack(E.at(j));

        std::cout << "TABLICA DLA RESZTY Z DZIELENIA PRZEZ: " << multiplier << std::endl;

        for (int j = 0; j < vec.size(); j++)
        {
            std::cout << "[" << j << "] :   ";
            vec.at(j) -> print();
        }
        int k = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec.at(j) -> getSize() > 0)
            {
                while (!vec.at(j) -> empty())
                {
                    E.at(k++) = vec.at(j) -> getHead() -> getData();
                    vec.at(j) -> popFront();
                }
            }
        }
        print(E);
        multiplier *= 10;
        divider *= 10;
    }
}

#endif //EVERYTHING_ALGORITHMS_HPP
