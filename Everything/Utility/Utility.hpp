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
        std::cout << a << " ";
    std::cout << std::endl;
}

template<typename T>
constexpr bool isInteger(T &value)
{
    return std::is_integral<T>::value;
}