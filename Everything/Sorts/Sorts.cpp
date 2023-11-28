#include "/Users/michallejza/CLionProjects/Everything/Sorts/Sorts.hpp"

#pragma once

template<typename T>
void Sorts::printVector(const std::vector<T> &vec)
{
    for (const auto& item : vec)
        std::cout << item << " ";
    std::cout << std::endl;
}

template<typename T>
void Sorts::swap(std::vector<T> &vec, size_t i, size_t j)
{
    T temp = std::move(vec[i]);
    vec[i] = std::move(vec[j]);
    vec[j] = std::move(temp);
}

template<typename T>
void Sorts::heapify(std::vector<T> &vec, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && vec[left] > vec[largest])
        largest = left;
    if(right < n && vec[right] > vec[largest])
        largest = right;
    if(largest != i)
        swap(vec, i, largest);
    heapify(vec,n,largest);
}

template<typename T>
int Sorts::partition(std::vector<T> &vec, int low, int high)
{
    T pivot = vec[high];
    int i = low - 1;

    for(int j = low; j <= high - 1; ++j)
    {
        if(vec[j] < pivot)
        {
            ++i;
            swap(vec,i ,j);
        }
    }
    swap(vec, i +1, high);
    return i + 1;
}

template<typename T>
void Sorts::startQuickSort(std::vector<T> &vec, int low, int high)
{
    if(low < high)
    {
        int p = partition(vec, low, high);
        startQuickSort(vec, low, p - 1);
        startQuickSort(vec, p + 1, high);
    }
}

template<typename T>
void Sorts::countingSort(std::vector<T> &vec, int exp)
{
    int n = vec.size();
    std::vector<T> output(n);
    std::vector<int> count(10, 0);

    for(int i = 0; i < n; ++i)
    {
        int digit = (vec[i] / exp) % 10;
        count[digit]++;
    }

    for(int i =1; i < 10; ++i)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        int digit = (vec[i] / exp) % 10;
        output[count[digit] - 1] = vec[i];
        count[digit]--;
    }

    for (int i = 0; i < n; ++i)
        vec[i] = output[i];
}

template<typename T>
void Sorts::merge(std::vector<T> &vec, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> leftVec(n1);
    std::vector<T> rightVec(n2);

    for(int i = 0; i < n1; i++)
        leftVec[i] = vec[left + 1];
    for(int i = 0; i < n2; i++)
        rightVec[i] = vec[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if(leftVec[i] <= rightVec[j])
        {
            vec[k] = leftVec[i];
            ++i;
        }
        else
        {
            vec[k] = rightVec[j];
            ++j;
        }
        ++k;
    }

    while (i < n1)
    {
        vec[k] = leftVec[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        vec[k] = rightVec[j];
        ++j;
        ++k;
    }
}

template<typename T>
void Sorts::HeapSort(std::vector<T> &vec)
{
    int n = vec.size();
    for(int i = n/2 - 1; i >= 0; --i)
        heapify(vec, n, i);
    for(int i = n - 1; i >= 0; --i)
    {
        swap(vec, 0, i);
        heapify(vec,i,0);
    }
}

template<typename T>
void Sorts::BubbleSort(std::vector<T> &vec)
{
    for(int i = 0; i < vec.size() - 1; ++i)
        for(int j = 0; j < vec.size() - i - 1; ++j)
            if(vec[j] > vec[j + 1])
                swap(vec, j, j+1);
}

template<typename T>
void Sorts::BucketSort(std::vector<T> &vec, int numBuckets)
{
    if (vec.empty() || numBuckets <= 0)
        return;

    T minVal = vec[0], maxVal = vec[0];
    for(const auto &item : vec)
    {
        if(item < minVal)
            minVal = item;
        if(item > maxVal)
            maxVal = item;
    }
    double range = static_cast<double>(maxVal - minVal + 1) / numBuckets;
    std::vector<std::vector<T>> buckets(numBuckets);
    for(const auto &item : vec)
    {
        int bucketIndex = static_cast<int>((item - minVal) / range);
        buckets[bucketIndex].push_back(item);
    }

    for(auto &bucket : buckets)
        std::sort(bucket.begin(), bucket.end());

    vec.clear();
    for(const auto &bucket : buckets)
        vec.insert(vec.end(), bucket.begin(), bucket.end());
}

template<typename T>
void Sorts::QuickSort(std::vector<T> &vec)
{
    startQuickSort(vec, 0, vec.size() - 1);
}

template<typename T>
void Sorts::SelectionSort(std::vector<T> &vec)
{
    for(int i = 0; i < vec.size() - 1; ++i)
    {
        int index = i;
        for(int j = i + 1; j < vec.size(); ++j)
            if(vec[j] < vec[index])
                index = j;
        swap(vec, i, index);
    }
}

template<typename T>
void Sorts::SelectionSort(std::vector<T> &vec, std::function<bool(const T&, const T&)> compare)
{
    for(size_t i = 0; i < vec.size() - 1; i++)
    {
        size_t index = i;
        for(size_t j = i + 1; j < vec.size(); j++)
            if(compare(vec[j], vec[index]))
                index = j;
        swap(vec, i , index);
    }
}

template<typename T>
void Sorts::RadixSort(std::vector<T> &vec)
{
    if(vec.empty())
        return;
    T maxElement = *std::max_element(vec.begin(), vec.end());
    for(int exp = 1; maxElement / exp > 0; exp *= 10)
        countingSort(vec, exp);
}

template<typename T>
void Sorts::MergeSort(std::vector<T> &vec, int left, int right)
{
    if (left < right) {
        int middle = left + (right - left) / 2;

        MergeSort(vec, left, middle);
        MergeSort(vec, middle + 1, right);

        merge(vec, left, middle, right);
    }
}