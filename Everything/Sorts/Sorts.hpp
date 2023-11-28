#ifndef EVERYTHING_SORTS_HPP
#define EVERYTHING_SORTS_HPP

#include <iostream>
#include <vector>
#include <random>
#include <functional>
#include <utility>

namespace Sorts
{
    template<typename T>
    void printVector(const std::vector<T> &vec);

    template<typename T>
    void swap(std::vector<T> &vec, size_t i, size_t j);

    template<typename T>
    void heapify(std::vector<T> &vec, int n, int i);

    template<typename T>
    int partition(std::vector<T> &vec, int low, int high);

    template<typename T>
    void startQuickSort(std::vector<T> &vec, int low, int high);

    template<typename T>
    void countingSort(std::vector<T> &vec, int exp);

    template<typename T>
    void merge(std::vector<T> &vec, int left, int middle, int right);

    template<typename T>
    void HeapSort(std::vector<T> &vec);

    template<typename T>
    void BubbleSort(std::vector<T> &vec);

    template<typename T>
    void BucketSort(std::vector<T> &vec, int numBuckets);

    template<typename T>
    void QuickSort(std::vector<T> &vec);

    template<typename T>
    void SelectionSort(std::vector<T> &vec);

    template<typename T>
    void SelectionSort(std::vector<T> &vec, std::function<bool(const T&, const T&)> compare);

    template<typename T>
    void RadixSort(std::vector<T> &vec);

    template<typename T>
    void MergeSort(std::vector<T> &vec, int left, int right);
}

#endif //EVERYTHING_SORTS_HPP
