//
// Created by 帆桥 on 2019/6/25.
//

#ifndef CLIONCODE_MINHEAP_HPP
#define CLIONCODE_MINHEAP_HPP

#include <iostream>
namespace Util {
    constexpr int DefaultSize = 60;

    template <typename T>
    class MinHeap {
    public:
        MinHeap(int sz = DefaultSize);

        MinHeap(T arr[], int n);

        ~MinHeap() { delete[] heap; }

        bool Insert(const T &x);

        bool RemoveMin();

        bool IsEmpty() { return currentSize == 0; }

        bool IsFull() { return currentSize == maxHeapSize; }

        void MakeEmpty() { currentSize = 0; }

        T getMin() {
            if (currentSize == 0)
                std::cerr << "Heap Full" <<std::endl;
            else
                return heap[0];
        }

    private:
        T *heap;
        int currentSize;
        int maxHeapSize;

        void siftDown(int start, int m);

        void siftUp(int start);
    };


    template <typename T>
    MinHeap<T>::MinHeap(int sz) {
        maxHeapSize = (sz > DefaultSize) ? sz : DefaultSize;
        heap = new T[maxHeapSize];
        if (heap == NULL) {
            std::cerr << "堆储存分配错误！" << std::endl;
            exit(1);
        }
        currentSize = 0;
    }


    template <typename T>
    MinHeap<T>::MinHeap(T arr[], int n) {
        maxHeapSize = (n > DefaultSize) ? n : DefaultSize;
        heap = new T[maxHeapSize];
        if (heap == NULL) {
            std::cerr << "堆储存分配错误！" << std::endl;
            exit(1);
        }
        currentSize = 0;
        for (int i = 0; i < n; ++i) {
            Insert(arr[i]);
        }
    }


    template <typename T>
    void MinHeap<T>::siftDown(int start, int m) {
        int i = start;
        int j = 2 * i + 1;
        T temp = heap[i];
        while (j <= m) {
            if (j < m && heap[j] > heap[j + 1]) j++;
            if (heap[j] >= temp) break;
            else {
                heap[i] = heap[j];
                i = j;
                j = 2 * j + 1;
            }
        }
        heap[i] = temp;
    }


    template <typename T>
    void MinHeap<T>::siftUp(int start) {
        int j = start;
        int i = (j - 1) / 2;
        T temp = heap[j];
        while (j > 0) {
            if (temp >= heap[i]) break;
            else {
                heap[j] = heap[i];
                j = i;
                i = (i - 1) / 2;
            }
        }
        heap[j] = temp;
    }

    template <typename T>
    bool MinHeap<T>::Insert(const T &x) {
        if (currentSize == maxHeapSize) {
            std::cerr << "Heap Full" << std::endl;
            return false;
        }
        heap[currentSize] = x;
        siftUp(currentSize);
        currentSize++;
        return true;
    }

    template <typename T>
    bool MinHeap<T>::RemoveMin() {
        if (currentSize == 0) {
            std::cout << "Heap empty" << std::endl;
            return false;
        }
        heap[0] = heap[currentSize - 1];
        currentSize--;
        siftDown(0, currentSize - 1);
        return true;
    }
}
#endif //CLIONCODE_MINHEAP_HPP
