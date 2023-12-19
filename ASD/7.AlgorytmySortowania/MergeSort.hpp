#ifndef EVERYTHING_MERGESORT_HPP
#define EVERYTHING_MERGESORT_HPP


#include "iostream"
#include "vector"

#pragma once

template<typename T>
void Merge(std::vector<T> &E, int left, int middle, int right, int operation)
{
    std::vector<int> temp = std::vector<T>(right - left);

    int l = left;
    int m = middle;
    int k = 0;

    std::cout << "MERGE:    " << operation << std::endl << operation << ":    ";
    std::cout << "L: ";
    for (int i = left; i < middle; i++)
        std::cout << E.at(i) << ", ";
    std::cout << "    P: ";
    printArrayFromTo(E, middle, right);

    while (l < middle && m < right)
    {
        if (E.at(l) < E.at(m))
            temp.at(k++) = E.at(l++);
        else
            temp.at(k++) = E.at(m++);
    }

    while (l < middle)
        temp.at(k++) = E.at(l++);

    while (m < right)
        temp.at(k++) = E.at(m++);

    k = 0;
    for (int i = left; i < right; i++)
        E.at(i) = temp.at(k++);
    std::cout << operation << ":    ";
    printArrayFromTo(E, left, right);
}

template<typename T>
void MergeSort(std::vector<T> &E, int left, int right, int operation)
{
    if (right - left > 1 && left < right)
    {
        std::cout << "MERGESORT:    " << operation << std::endl << operation << ":    ";
        printArrayFromTo(E, left, right);
        int mid = left + (right - left) / 2;
        std::cout << operation << ":    L: ";
        for (int i = left; i < mid; i++)
            std::cout << E.at(i) << ", ";
        std::cout << "    P: ";
        printArrayFromTo(E, left, mid);

        if ((right - left) / 2 > 1)
            MergeSort(E, left, mid, operation + 1);
        if (((right - left) - (right - left) / 2) > 1)
            MergeSort(E, mid, right, operation + 1);
        Merge(E, left, mid, right, operation);
    }
}


#endif //EVERYTHING_MERGESORT_HPP
