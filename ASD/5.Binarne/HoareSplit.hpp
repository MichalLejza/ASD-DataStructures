#ifndef EVERYTHING_HOARESPLIT_HPP
#define EVERYTHING_HOARESPLIT_HPP

#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Split.hpp"

#pragma once


template<typename T>
void HoareSplit(std::vector<T> &E, int k)
{
    int m = 0;
    int operation = 1;
    int i = 0;
    int j = E.size();

    while (j - m != k && j - i > 0)
    {

        std::cout << "METODA HOARE SPLIT: " << operation << " I SZUKAMY ELEMENT " << k << " CO DO WIELKOŚCI" << std::endl << "ZAKRES PRZUKANIA TABLICY: " << i << "-" << j << std::endl;
        printArrayFromTo(E, i, j);
        m = split(E, i, j);
        printArrayFromTo(E, i, j);
        std::cout << "PO WYKONANIU SPLIT DLA OPERACJI: " << operation << " MEDIANA JEST NA POZYCJI: " << m << " I WYNOSI: " << E.at(m) << std::endl << std::endl;
        if (j - m > k)
        {
            i = m + 1;
        }
        else if (j - m < k)
        {
            k -= (j - m);
            j = m;
        }
        operation++;
    }
    std::cout << "KOIEC METODY HOARE SPLIT. ELEMENT " << k << " CO DO WIELKOŚCI WYNOSI " << E.at(m) << std::endl;
}


#endif //EVERYTHING_HOARESPLIT_HPP
