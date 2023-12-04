#ifndef EVERYTHING_ALGORITHMS_HPP
#define EVERYTHING_ALGORITHMS_HPP


#include "vector"
#include "iostream"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"


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


template<typename T>
void CountingSort(std::vector<T> &E)
{
    int max = findMax(E);
    auto Tmp = std::vector<T>(max + 1);
    auto out = std::vector<T>(E.size());

    for (int i = 0; i < E.size(); i++)
        Tmp[E.at(i)]++;

    print(Tmp);

    for (int i = 1; i < max + 1; i++)
        Tmp.at(i) += Tmp.at(i - 1);

    print(Tmp);

    for (int i = E.size() - 1; i>= 0; i--)
    {
        out.at(Tmp.at(E.at(i)) - 1) = E.at(i);
        Tmp.at(E.at(i)) = Tmp.at(E.at(i)) - 1;
    }

    print(Tmp);
    E = out;
}

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



#endif //EVERYTHING_ALGORITHMS_HPP
