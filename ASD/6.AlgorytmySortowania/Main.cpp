#include "/Users/michallejza/CLionProjects/Everything/ASD/6.AlgorytmySortowania/InsertionSort.hpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/6.AlgorytmySortowania/SelectionSort.hpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/6.AlgorytmySortowania/QuickSort.hpp"

void ZadaniePierwsze()
{
    auto vec = std::vector<int>();
    vec = {4,6,1,8,3,4,2,5,9,12,7,10,13,0};
    SelectionSort(vec);
    vec = {4,6,1,8,3,4,2,5,9,12,7,10,13,0};
    InsertionSort(vec);
    vec = {4,6,1,8,3,4,2,5,9,12,7,10,13,0};
    QuickSortSplit(vec, 0, vec.size(), 1);
    print(vec);
}

int main()
{
    ZadaniePierwsze();
    return 0;
}
