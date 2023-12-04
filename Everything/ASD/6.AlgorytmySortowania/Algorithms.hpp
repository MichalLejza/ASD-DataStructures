#ifndef EVERYTHING_ALGORITHMS_HPP
#define EVERYTHING_ALGORITHMS_HPP

#pragma once
#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Partition.cpp"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

template<typename T>
void SelectionSort(std::vector<T> &E)
{
    int i = 0;
    int j = 0;
    int min = 0;
    int operation = 1;

    std::cout << "SELECTION SORT" << std::endl << std::endl;

    for (i = 0; i < E.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < E.size(); j++)
        {
            if (E.at(j) < E.at(min))
                min = j;
        }
        if (min != i)
        {
            std::cout << operation << ":   zamieniam liczby na indexach: " << min << " i " << i << std::endl << operation << ":   ";
            for (int k = 0; k < E.size(); k++)
            {
                if (k == min || k == i)
                    std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
                else
                    std::cout << E.at(k) << ", ";
            }
            swap(E, min, i);
            std::cout << std::endl << operation << ":   ";
            for (int k = 0; k < E.size(); k++)
            {
                std::cout << E.at(k) << ", ";
            }
            std::cout << std::endl;
            operation++;
        }
    }
}

template<typename T>
void InsertionSort(std::vector<T> &E)
{
    int i = 0;
    int j = 0;
    int operation = 1;

    std::cout << "INSERTION SORT" << std::endl;

    for (i = 0; i < E.size(); i++)
    {
        j = i;
        while ((j > 0) && (E.at(j - 1) > E.at(j)))
        {
            std::cout << operation << ":   zamieniam liczby na indexach: " << j - 1 << " i " << j << std::endl << operation << ":   ";
            for (int k = 0; k < E.size(); k++)
            {
                if (k == j - 1 || k == j)
                    std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
                else
                    std::cout << E.at(k) << ", ";
            }
            swap(E, j - 1, j);
            std::cout << std::endl << operation << ":   ";
            for (int k = 0; k < E.size(); k++)
            {
                std::cout << E.at(k) << ", ";
            }
            std::cout << std::endl;
            j--;
            operation++;
        }
    }
}

template<typename T>
void QuickSortSplit(std::vector<T> &E, int i, int j, int count)
{
    std::cout << "QUICK SORT SPLIT:    " << count << std::endl;
    print(E);
    int m = split(E, i, j);
    print(E);

    if (m > 1)
    {
        QuickSortSplit(E, i, m , count + 1);
    }

    if ((j - i) - m - 1) > 1)
    {
        QuickSortSplit(E, m, j, count + 1);
    }
}

template<typename T>
void QuickSortPartition(std::vector<T> &E, int i, int j, int count)
{
    std::cout << "QUICK SORT PARTITION:    " << count << std::endl;
    print(E);
    int m = partition(E, i, j);
    print(E);
    
    if (m > 1)
    {
        QuickSortPartition(E, 0, m, count + 1);
    }

    if ((j - i) - m - 1 > 1)
    {
        QuickSortPartition(E, m, j, count + 1);
    }
}



#endif //EVERYTHING_ALGORITHMS_HPP
