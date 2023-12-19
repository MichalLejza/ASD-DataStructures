#include "iostream"
#include "vector"
#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"

using namespace Print;

auto dutchFlag(std::vector<int> &array) -> void
{
    size_t c = 0, b = 0, n = array.size() - 1;
    while (b <= n)
    {
        if (array.at(b) == 0)
        {
            if (c != b)
                std::swap(array.at(b), array.at(c));
            b++;
            c++;
        }
        else if (array.at(b) == 1)
        {
            b++;
        }
        else if (array.at(b) == 2)
        {
            if (b != n)
                std::swap(array.at(b), array.at(n));
            n--;
        }
    }
}

auto main() -> int
{
    std::vector<int> array = {0,1,2,2,1,0,1,1,0,0,2,2,1,0,2,1,0,2,1,1,2,0,2,0,0,0,2,2,1};
    print(array);
    dutchFlag(array);
    print(array);
    return 0;
}
