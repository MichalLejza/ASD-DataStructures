#ifndef EVERYTHING_COUNTINGSORT_HPP
#define EVERYTHING_COUNTINGSORT_HPP

#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

#pragma once

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

#endif //EVERYTHING_COUNTINGSORT_HPP
