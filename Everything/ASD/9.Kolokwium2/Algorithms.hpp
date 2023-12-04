#ifndef EVERYTHING_ALGORITHMS_HPP
#define EVERYTHING_ALGORITHMS_HPP


#include "vector"
#include "iostream"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

template<typename T>
void printArrayFromTo(std::vector<T> &E, int i, int j)
{
    for (int l = i; l < j; l++)
        std::cout << E.at(l) << " ";
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

template<typename T>
void InsertionSort(std::vector<T> &E)
{

}


#endif //EVERYTHING_ALGORITHMS_HPP
