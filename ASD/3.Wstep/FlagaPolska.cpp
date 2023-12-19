#include "iostream"
#include "vector"
#include "/Utility/Utility.hpp"

auto flag(std::vector<int> &array) -> void
{
    size_t poc = 0, kon = array.size() - 1;
    while (poc < kon)
    {
        if (array.at(poc) == 0)
            poc++;
        else
        {
            auto temp = array.at(poc);
            array.at(poc) = array.at(kon);
            array.at(kon) = temp;
            kon--;
        }
    }
}

auto main() -> int
{
    std::vector<int> array = {1,0,1,1,0,1,0,0,0,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0};
    Print::print(array);
    flag(array);
    Print::print(array);
    return 0;
}
