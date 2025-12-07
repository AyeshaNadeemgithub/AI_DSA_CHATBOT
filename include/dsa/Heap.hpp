#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Heap {

private:
    vector<int> heap;   // internal storage
    bool isMinHeap;     // true = Min Heap, false = Max Heap

    // Helper functions
    void heapifyUp(int index);
    void heapifyDown(int index);
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);

public:
    // Constructor
    Heap(bool minHeap = false);

    // Core operations
    void insert(int value);
    void deleteRoot();
    int getRoot();
    vector<int> heapSort();

    // Utility
    void display();
};


