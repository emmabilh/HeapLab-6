// Emma Bilhimer
// Lab 6 - Heap
// Busch SP24
// Due April 15, 2024
// Description: Implement a heap that can perform heap sort and reheap operations.

#ifndef Heap_hpp
#define Heap_hpp
#include <stdio.h>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapify(int index);
    void buildHeap();

public:
    MaxHeap(const vector<int>& array);
    vector<int> heapSort();
    void insert(int value);
    void display();
};

#endif
