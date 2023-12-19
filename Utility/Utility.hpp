#include "vector"
#include "iostream"

#pragma once

template<typename T>
T max(T one, T two)
{
    return one > two ? one : two;
}

template<typename T>
T min(T one, T two)
{
    return one < two ? one : two;
}

template<typename T>
T findMax(std::vector<T> &E)
{
    T min = E.at(0);
    for (auto a : E)
        if (min < a)
            min = a;
    return min;
}


template<typename T>
void swap(std::vector<T> &vec, int i, int j)
{
    T temp = vec.at(i);
    vec.at(i) = vec.at(j);
    vec.at(j) = temp;
}

template<typename T>
void print(std::vector<T> array)
{
    for (auto a : array)
        std::cout << a << ", ";
    std::cout << std::endl;
}

template<typename T>
constexpr bool isInteger(T &value)
{
    return std::is_integral<T>::value;
}


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
