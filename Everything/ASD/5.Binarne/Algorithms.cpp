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
int hoarePartition(std::vector<T> &E, int k, int i, int j, int operacja)
{
    int m = 0;
    int tmp = 0;
    int n = j - i;

    std::cout << "HOARE PARTITION operacja numer:  " << operacja << std::endl;

    m = partition(E, i, j);
    std::cout << "m wynosi: " << m << std::endl <<  std::endl;

    if (n - m == k)
    {
        return m;
    }
    else
    {
        if (n - m > k)
        {
            std::cout << "PRZESZUKIWANY OBSZAR PRAWEJ CZESCI TABLICY DLA OPERACJI NUMER : " << operacja << std::endl;
            for (int z = m + 1; z < n; z++)
                std::cout << E.at(z) << ", ";
            std::cout << std::endl;
            tmp = m + 1 + hoarePartition(E, m + 1, n, k, operacja + 1);
        }
        else
        {
            std::cout << "PRZESZUKIWANY OBSZAR LEWEJ CZESCI TABLICY DLA OPERACJI NUMER : " << operacja << std::endl;
            for (int z = i; z < m; z++)
                std::cout << E.at(z) << ", ";
            std::cout << std::endl;
            tmp = hoarePartition(E, i, m - 1, k - (n - m), operacja + 1);
        }
    }
    return tmp;
}

template<typename T>
int hoareSplit(std::vector<T> &E, int k, int i, int j)
{
    int m = 0;
    int tmp = 0;
    int n = j - i;

    m = split(E);
    std::cout << "m wynosi: " << m << std::endl;


    if (n - m == k)
    {
        return m;
    }
    else
    {
        if (n - m > k)
        {
            tmp = m + 1 + hoareSplit(E, k,m + 1, n - 1);
        }
        else
        {
            tmp = hoareSplit(E, 0, m - 1, k - (n-m));
        }
    }
    return tmp;
}

template<typename T>
void SelectionSort(std::vector<T> &E)
{
    int i = 0;
    int j = 0;
    int min = 0;

    for (i = 0; i < E.size() - 1; i++)
    {
        min = i;
        for (j = i + 1; j < E.size(); j++)
            if (E.at(j) < E.at(min))
                min = j;
        if (min != i)
            swap(E, min, i);
    }
}

template<typename T>
void InsertionSort(std::vector<T> &E)
{

}
