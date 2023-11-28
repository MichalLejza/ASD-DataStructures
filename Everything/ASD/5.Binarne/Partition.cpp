#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once


template<typename T>
int partition(std::vector<T> &E, int i, int j)
{
    int l = i - 1;
    int r = i;
    int n = j;
    int operation = 1;

    std::cout << std::endl << "METODA PARTITION: " << std::endl;

    while (r < n - 1)
    {
        if (E.at(r) < E.at(n - 1))
        {
            if (r > l + 1)
            {
                std::cout << operation << ":   zamieniam liczby na indexach: " << l + 1 << " i " << r << std::endl << operation << ":   ";
                for (int k = i; k < j; k++)
                {
                    if (k == l + 1 || k == r)
                        std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
                    else
                        std::cout << E.at(k) << ", ";
                }
                swap(E, r, l + 1);
                std::cout << operation << ":   " ;
                for (int k = i; k < j; k++)
                {
                    std::cout << E.at(k) << ", ";
                }
                std::cout << std::endl;
                operation++;
            }
            l++;
        }
        r++;
    }
    if (l + 1 < n - 1)
    {
        std::cout << operation << ":   dodatkowo zamieniam liczby na indexach: " << l + 1 << " i " << n - 1 << std::endl << operation << ":   ";
        for (int k = i; k < j; k++)
        {
            if (k == l + 1 || k == n - 1)
                std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
            else
                std::cout << E.at(k) << ", ";
        }
        swap(E, l + 1, n - 1);
        std::cout << std::endl << operation << ":   " ;
        for (int k = i; k < j; k++)
        {
            std::cout << E.at(k) << ", ";
        }

    }
    std::cout << std::endl << "tzw. mediana jest na pozycji:   " << l + 1 << "   i wynosi:   " << E.at(l + 1) << std::endl;
    std::cout << std::endl;
    return l + 1;
}

template<typename T>
int split(std::vector<T> &E, int i, int j)
{
    int l = i + 1;
    int r = j - 1;
    int m = i;
    int operation = 1;

    std::cout << std::endl << "METODA SPLIT: " << std::endl;

    while (l < r)
    {
        if (r >= 0 && E.at(r) > E.at(m))
            r--;
        else if(E.at(l) < E.at(m) && l < r)
            l++;
        else if (l < r)
        {
            std::cout << operation << ":   zamieniam liczby na indexach: " << l << " i " << r << std::endl << operation << ":   ";
            for (int k = i; k < j; k++)
            {
                if (k == l || k == r)
                    std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
                else
                    std::cout << E.at(k) << ", ";
            }
            std::cout << std::endl << operation << ":   ";
            swap(E, l, r);
            for (int k = i; k < j; k++)
            {
                std::cout << E.at(k) << ", ";
            }
            std::cout << std::endl;
            operation++;
            r--;
            l++;
        }
    }
    std::cout << operation << ": zamieniam liczby na indexach: " << m << " i " << r << std::endl << operation << ":   ";
    for (int k = i; k < j; k++)
    {
        if (k == m || k == r)
            std::cout << "\033[32m" << E.at(k) << "\033[0m" << ", ";
        else
            std::cout << E.at(k) << ", ";
    }
    swap(E, m, r);
    std::cout << std::endl << operation << ":   ";
    for (int k = i; k < j; k++)
    {
        std::cout << E.at(k) << ", ";
    }
    std::cout << std::endl << "tzw. mediana jest na pozycji:   " << r << "   i wynosi:   " << E.at(r) << std::endl;
    std::cout <<  std::endl;
    return r;
}

