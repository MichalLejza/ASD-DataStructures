#include "/Users/michallejza/CLionProjects/Everything/ASD/7.AlgorytmySortowania/RadixSort.hpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/7.AlgorytmySortowania/MergeSort.hpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/7.AlgorytmySortowania/CountingSort.hpp"

void ZadaniePiate()
{
    auto vec = std::vector<int>();
    vec= {941,311,659,633,840,655,600,943,271,790,951};
    RadixSort(vec, 3);
    vec= {941,311,659,633,840,655,600,943,271,790,951};
    MergeSort(vec, 0, vec.size(), 1);
    print(vec);
}

int main()
{
    ZadaniePiate();
    return 0;
}
