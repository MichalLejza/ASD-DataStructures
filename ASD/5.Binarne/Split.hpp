#ifndef EVERYTHING_SPLIT_HPP
#define EVERYTHING_SPLIT_HPP

#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once

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
        else if (l <= r)
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


#endif //EVERYTHING_SPLIT_HPP
