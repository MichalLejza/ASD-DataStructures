#include "iostream"
#include "/Utility/Utility.hpp"
#include "vector"

size_t FindMax(const std::vector<int> &array)
{
    size_t index = 0;
    int maxElement = INT32_MIN;
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array.at(i) > maxElement)
        {
            maxElement = array.at(i);
            index = i;
        }
    }
    return index;
}

ssize_t FindSecondMax(std::vector<int> array)
{
    if ( array.size() < 2 )
    {
        std::cerr << "Array has less elements than two";
        return -1;
    }

    ssize_t firstIndex = 0, secondIndex = (array.at(1) > array.at(0) ? 1 : 0);

    for (ssize_t i = 2; i < array.size(); ++i)
    {
        if (array.at(i) > array.at(firstIndex))
        {
            secondIndex = firstIndex;
            firstIndex = i;
        }
        else if (array.at(i) > array.at(secondIndex) && array.at(i) != array.at(firstIndex))
        {
            secondIndex = i;
        }
    }

    return secondIndex;
}

auto main() -> int
{
    std::vector<int> array = {8,1,3,4,7,2,0,9,6,5};
    std::cout << FindMax(array) << std::endl;
    std::cout << FindSecondMax(array);
    return 0;
}
