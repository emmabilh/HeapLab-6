// main.cpp

#include <iostream>
#include "Heap.hpp"

using namespace std;

int main() {                                // create an array of integers
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    MaxHeap maxHeap(arr);                   // create a MaxHeap object using the array

    cout << "Max Heap: ";                   // show the original heap
    maxHeap.display();

    cout << "Performing heap sort..." << endl;    // perform heap sort

    vector<int> sortedArray = maxHeap.heapSort();

    cout << "Sorted Array: ";                 // show sorted array

    for (size_t i = 0; i < sortedArray.size(); i++) { // this will iterate through the sorted array
        cout << sortedArray[i] << " "; // print each element of the array (sorted)
    }
    cout << endl;

    return 0;
}


