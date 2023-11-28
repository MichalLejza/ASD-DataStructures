#include "/Users/michallejza/CLionProjects/Everything/ASD/7.AlgorytmySortowania/Algorithms.hpp"

void ZadaniePierwsze()
{

}

void ZadaniePiate()
{
    auto vec = std::vector<int>();
    vec= {941,311,659,633,840,655,600,943,271,790,951};
    RadixSort(vec, 3);
}

int main()
{
    ZadaniePiate();
    return 0;
}
