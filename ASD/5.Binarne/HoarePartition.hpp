#ifndef EVERYTHING_HOAREPARTITION_HPP
#define EVERYTHING_HOAREPARTITION_HPP

#include "vector"
#include "iostream"
#include "/ASD/5.Binarne/Partition.hpp"

#pragma once


template<typename T>
void HoarePartition(std::vector<T> &E, int k)
{
    int m = 0;
    int operation = 1;
    int i = 0;
    int j = E.size();

    while (j - m != k && j - i > 0)
    {
        std::cout << "METODA HOARE PARTITION: " << operation << " I SZUKAMY ELEMENT " << k << " CO DO WIELKOŚCI" << std::endl << "ZAKRES PRZUKANIA TABLICY: " << i << "-" << j << std::endl;
        printArrayFromTo(E, i, j);
        m = partition(E, i, j);
        printArrayFromTo(E, i, j);
        std::cout << "PO WYKONANIU PARTITION DLA OPERACJI: " << operation << " MEDIANA JEST NA POZYCJI: " << m << " I WYNOSI: " << E.at(m) << std::endl << std::endl;
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
    std::cout << "KOIEC METODY HOARE PARTITION. ELEMENT " << k << " CO DO WIELKOŚCI WYNOSI " << E.at(m) << std::endl;
}


#endif //EVERYTHING_HOAREPARTITION_HPP
