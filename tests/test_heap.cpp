#include <iostream>
#include "dsa/Heap.hpp"
using namespace std;

int main() {

    cout << "===== Testing Max Heap =====\n";
    Heap maxHeap(false);   // false → Max Heap

    maxHeap.insert(10);
    maxHeap.insert(4);
    maxHeap.insert(15);
    maxHeap.insert(20);
    maxHeap.insert(8);

    cout << "Max Heap root (expected 20): " << maxHeap.getRoot() << endl;

    maxHeap.display();

    maxHeap.deleteRoot();
    cout << "After deleting root (expected 15): " << maxHeap.getRoot() << endl;
    maxHeap.display();

    vector<int> maxSorted = maxHeap.heapSort();
    cout << "Heap Sort (maxHeap → descending): ";
    for(int x : maxSorted) cout << x << " ";
    cout << "\n";


    cout << "\n===== Testing Min Heap =====\n";
    Heap minHeap(true);   // true → Min Heap

    minHeap.insert(10);
    minHeap.insert(4);
    minHeap.insert(15);
    minHeap.insert(20);
    minHeap.insert(8);

    cout << "Min Heap root (expected 4): " << minHeap.getRoot() << endl;

    minHeap.display();

    minHeap.deleteRoot();
    cout << "After deleting root (expected 8): " << minHeap.getRoot() << endl;
    minHeap.display();

    vector<int> minSorted = minHeap.heapSort();
    cout << "Heap Sort (minHeap → ascending): ";
    for(int x : minSorted) cout << x << " ";
    cout << "\n";

    return 0;
}