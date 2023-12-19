#ifndef EVERYTHING_RADIXSORT_HPP
#define EVERYTHING_RADIXSORT_HPP

#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once


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
                while (!vec.at(j)->isEmpty())
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


#endif //EVERYTHING_RADIXSORT_HPP
