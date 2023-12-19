#ifndef EVERYTHING_INSERTIONSORT_HPP
#define EVERYTHING_INSERTIONSORT_HPP

#include "iostream"
#include "vector"
#include "/Utility/Utility.hpp"

#pragma once

template<typename T>
void InsertionSort(std::vector<T> &E)
{
    std::cout << "INSERTION SORT\n\n";
    int i = 0;
    int j = 0;
    int operation = 0;
    int porownania = 0;
    int swapy = 0;

    std::cout << operation << ":    ";
    printArrayFromToHighlightOneElement(E, 0, E.size(), operation);
    operation++;

    for (i = 1; i < E.size(); i++)
    {
        j = i;
        if (E.at(j - 1) >  E.at(j))
        {
            while ((j > 0) && (E.at(j - 1) > E.at(j)))
            {
                std::cout << operation << ":    zamieniam liczby na indexach: " << j - 1 << " i " << j << std::endl << operation << ":    ";
                printArrayFromToInColour(E, 0, E.size(), j - 1, j);
                swap(E, j - 1, j);
                swapy++;
                porownania++;
                std::cout << operation << ":    ";
                print(E);
                j--;
            }
        }
        else
        {
            std::cout << operation << ":    niczego nie zmieniam\n";
            std::cout << operation << ":    ";
            printArrayFromToHighlightOneElement(E, 0, E.size(), operation);
            porownania++;
        }
        operation++;
        std::cout << std::endl;
    }
    std::cout << "LICZBA POROWNAN: " << porownania << " LICZBA SWAPOW:  " << swapy << std::endl;
}


#endif //EVERYTHING_INSERTIONSORT_HPP
