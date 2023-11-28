#include "/Users/michallejza/CLionProjects/Everything/Utility/Utility.hpp"
#include "vector"

auto main() -> int
{
    std::vector<int> vec = {1,2,3,4,5,6,7};
    print(vec);
    double x = 90.0;
    isInteger(x) ? std::cout << "TAK\n" : std::cout << "NIE\n";
    std::cout << max(vec.at(1), vec.at(2));
    return 0;
}
