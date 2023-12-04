#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Partition.cpp"

#pragma once


template<typename T>
auto binSearch(std::vector<T> &E, T x) -> int
{
    int l = 0;
    int r = E.size() - 1;
    int m = (l + r) / 2;

    int count = 1;

    while (E.at(m) != x)
    {
        std::cout << "[ " << count << " ]" << " obrót pętli: " << std::endl;
        std::cout << "l = " << l << ", m = " << m << ", r = " << r << std::endl;
        std::cout << "Przeszukiwany obszar tablicy: " << std::endl;
        int i = l;
        while (i < r)
        {
            std::cout << E.at(i) << " ";
            i++;
        }
        std::cout << std::endl << std::endl;


        if (E.at(m) < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
        m = (l + r) / 2;
    }
    return m;
}

template<typename T>
auto muchBetterBinSearch(std::vector<T> &E, T x) -> int
{
    int l = 0;
    int r = E.size() - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (E.at(m) == x)
        {
            return m;
        }
        else if (E.at(m) < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
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
