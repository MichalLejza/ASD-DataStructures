#ifndef EVERYTHING_SELECTIONSORT_HPP
#define EVERYTHING_SELECTIONSORT_HPP

#include "iostream"
#include "vector"
#include "/Utility/Utility.hpp"

#pragma once

template<typename T>
void SelectionSort(std::vector<T> &E)
{
    std::cout << "SELECTION SORT\n\n";
    int operation = 0;
    std::cout << operation++ << ":    ";
    print(E);
    int i = 0;
    int j = 0;
    int min = 0;
    int swapy = 0;
    int porownania = 0;

    for (i = 0; i < E.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < E.size(); j++)
        {
            if (E.at(j) < E.at(min))
            {
                min = j;
                porownania++;
            }
        }
        if (min != i)
        {
            std::cout << operation << ":    zamieniam liczby na indexach: " << min << " i " << i << std::endl << operation << ":    ";
            printArrayFromToInColour(E, 0, E.size(), min, i);
            swap(E, min, i);
            swapy++;
            std::cout << operation++ << ":    ";
            print(E);
            std::cout << std::endl;
        }
        else
        {
            std::cout << operation << ":    Nie zmieniam zadnych liczb\n";
            std::cout << operation++ << ":    ";
            printArrayFromToHighlightOneElement(E, 0, E.size(), i);
            std::cout << std::endl;
        }
    }

    std::cout << "LICZBA POROWNAN: " << porownania << " LICZBA SWAPOW: " << swapy << std::endl;
}


#endif //EVERYTHING_SELECTIONSORT_HPP
