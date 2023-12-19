#ifndef EVERYTHING_PARTITION_HPP
#define EVERYTHING_PARTITION_HPP

#include "iostream"
#include "vector"
#include "/Utility/Utility.hpp"

#pragma once

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

#endif //EVERYTHING_PARTITION_HPP
