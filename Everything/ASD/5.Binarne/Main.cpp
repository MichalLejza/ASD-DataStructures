#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Partition.cpp"
#include "/Users/michallejza/CLionProjects/Everything/ASD/5.Binarne/Algorithms.cpp"

void ZadanieDrugie()
{
    auto vec = std::vector<int>();
    vec = {9,3,2,10,7,15,4,5,12,13,14,1,11,3,23,20};
    std::cout << split(vec, 0, 16);
    auto vec1 = std::vector<int>();
    vec1 = {9,3,2,10,7,15,4,5,12,13,14,1,11,3,23,20};
    std::cout << partition(vec1,0, 16);
}

void ZadanieTrzecie()
{
    auto vec = std::vector<int>();
    vec = {9,3,2,10,7,15,4,5,12,13,14,1,11,3,23,20};
    std::cout << hoarePartition(vec, 5, 0, 16, 1);
}

int main()
{
    //ZadanieDrugie();
    ZadanieTrzecie();
    return 0;
}
