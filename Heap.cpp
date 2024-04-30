// implementation file
//  Heap.cpp
//  HeapLab


#include "Heap.hpp"
#include <iostream>

using namespace std;

// constructor
MaxHeap::MaxHeap(const vector<int>& array) : heap(array) {
    buildHeap();
}

// helper function to heapify subtree rooted at given index
void MaxHeap::heapify(int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // if left child is larger than root
    if (left < static_cast<int>(heap.size()) && heap[left] > heap[largest]) {
        largest = left;
    }

    // if right child is larger than largest so far
    if (right < static_cast<int>(heap.size()) && heap[right] > heap[largest]) {
        largest = right;
    }

    // if largest is not root
    if (largest != index) {
        swap(heap[index], heap[largest]);
        // Recursively heapify the affected sub-tree
        heapify(largest);
    }
}

// function to build a Max Heap
void MaxHeap::buildHeap() {
    // start from the last non-leaf node and heapify each node in reverse level order
    for (int i = static_cast<int>(heap.size()) / 2 - 1; i >= 0; i--) {
        heapify(i);
    }
}

// ffunction to perform heap sort
vector<int> MaxHeap::heapSort() {
    vector<int> sortedArray;

    // extract elements from heap one by one
    while (!heap.empty()) {
        sortedArray.push_back(heap[0]);
        swap(heap[0], heap.back());
        heap.pop_back();
        heapify(0);
    }

    return sortedArray;
}

// function to insert a new element into the heap
void MaxHeap::insert(int value) {
    heap.push_back(value);
    size_t index = heap.size() - 1;
    // fix the heap property if it is violated
    while (index > 0 && heap[(index - 1) / 2] < heap[index]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

// function to display the elements of the heap
void MaxHeap::display() {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
