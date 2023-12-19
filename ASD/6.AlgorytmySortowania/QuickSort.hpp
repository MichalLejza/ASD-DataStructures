#ifndef EVERYTHING_QUICKSORT_HPP
#define EVERYTHING_QUICKSORT_HPP

#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Partition.hpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Split.hpp"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once

template<typename T>
void QuickSortSplit(std::vector<T> &E, int left, int right, int operation)
{
    if (left < right)
    {
        std::cout << "OPERATION: " << operation << std::endl;
        printArrayFromTo(E, left, right);
        std::cout << std::endl;
        int m = split(E, left, right);
        QuickSortSplit(E, left, m, operation + 1);
        QuickSortSplit(E, m + 1, right, operation + 1);
    }
}

template<typename T>
void QuickSortPartition(std::vector<T> &E, int left, int right, int operation)
{
    if (left < right)
    {
        std::cout << "OPERATION: " << operation << std::endl;
        printArrayFromTo(E, left, right);
        std::cout << std::endl;
        int m = partition(E, left, right);
        QuickSortPartition(E, left, m, operation + 1);
        QuickSortPartition(E, m + 1, right, operation + 1);
    }
}



#endif //EVERYTHING_QUICKSORT_HPP
