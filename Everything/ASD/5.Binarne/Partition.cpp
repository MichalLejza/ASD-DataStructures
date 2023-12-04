#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once


template<typename T>
void printArrayFromTo(std::vector<T> &E, int i, int j)
{
    for (int l = i; l < j; l++)
        std::cout << E.at(l) << ", ";
    std::cout << std::endl;
}

template<typename T>
void printArrayFromToInColour(std::vector<T> &E, int i, int j, int indexOne, int indexTwo)
{
    for (int k = i; k < j; k++)
    {
        if (k == indexOne || k == indexTwo)
            std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
        else
            std::cout << E.at(k) << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
void printArrayFromToHighlightOneElement(std::vector<T> &E, int i, int j, int index)
{
    for (int k = i; k < j; k++)
    {
        if (k == index)
            std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
        else
            std::cout << E.at(k) << ", ";
    }
    std::cout << std::endl;
}

template<typename T>
int partition(std::vector<T> &E, int i, int j)
{
    int l = i - 1;
    int r = i;
    int n = j;

    while (r < n - 1)
    {
        if (E.at(r) < E.at(n - 1))
        {
            if (r > l + 1)
                swap(E, r, l + 1);
            l++;
        }
        r++;
    }
    if (l + 1 < n - 1)
        swap(E, l + 1, n - 1);
    return l + 1;
}

template<typename T>
int split(std::vector<T> &E, int i, int j)
{
    int l = i + 1;
    int r = j - 1;
    int m = i;

    while (l <= r)
    {
        if (l <= r && E.at(r) > E.at(m))
            r--;
        else if(E.at(l) < E.at(m) && l <= r)
            l++;
        else if (l < r)
        {
            swap(E, l, r);
            r--;
            l++;
        }
    }
    if (r > 0)
        swap(E, m, r);
    return r;
}
