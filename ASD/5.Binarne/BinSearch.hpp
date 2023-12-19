#ifndef EVERYTHING_BINSEARCH_HPP
#define EVERYTHING_BINSEARCH_HPP

#include "vector"
#include "iostream"

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
            std::cout << E.at(i++) << " ";
        std::cout << std::endl << std::endl;

        if (E.at(m) < x)
            l = m + 1;
        else
            r = m - 1;
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
            return m;
        else if (E.at(m) < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}


#endif //EVERYTHING_BINSEARCH_HPP
