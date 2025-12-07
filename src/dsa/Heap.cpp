#include "dsa/Heap.hpp"

// ========================= CONSTRUCTOR =========================
Heap::Heap(bool minHeap) {
    isMinHeap = minHeap;
}

// ========================= HELPER FUNCTIONS =========================
int Heap::parent(int i) { return (i - 1) / 2; }
int Heap::leftChild(int i) { return 2 * i + 1; }
int Heap::rightChild(int i) { return 2 * i + 2; }

void Heap::heapifyUp(int index) {
    while(index != 0) {
        int p = parent(index);
        bool condition = isMinHeap ? (heap[index] < heap[p])
                                   : (heap[index] > heap[p]);
        if(condition) {
            swap(heap[index], heap[p]);
            index = p;
        } else break;
    }
}

void Heap::heapifyDown(int index) {
    int left = leftChild(index);
    int right = rightChild(index);
    int chosen = index;

    if(isMinHeap) {
        if(left < heap.size() && heap[left] < heap[chosen])
            chosen = left;
        if(right < heap.size() && heap[right] < heap[chosen])
            chosen = right;
    } else {
        if(left < heap.size() && heap[left] > heap[chosen])
            chosen = left;
        if(right < heap.size() && heap[right] > heap[chosen])
            chosen = right;
    }

    if(chosen != index) {
        swap(heap[index], heap[chosen]);
        heapifyDown(chosen);
    }
}

// ========================= CORE OPERATIONS =========================
void Heap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

void Heap::deleteRoot() {
    if(heap.empty()) return;

    heap[0] = heap.back();
    heap.pop_back();
    if(!heap.empty()) heapifyDown(0);
}

int Heap::getRoot() {
    if(heap.empty()) {
        cout << "Heap is empty!\n";
        return -1;
    }
    return heap[0];
}

// ========================= HEAP SORT =========================
vector<int> Heap::heapSort() {
    vector<int> temp = heap;    // copy heap
    vector<int> sorted;

    while(!temp.empty()) {
        sorted.push_back(temp[0]);       // root
        temp[0] = temp.back();
        temp.pop_back();

        // local heapify down
        int idx = 0;
        while(true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int chosen = idx;

            if(isMinHeap) {
                if(left < temp.size() && temp[left] < temp[chosen]) chosen = left;
                if(right < temp.size() && temp[right] < temp[chosen]) chosen = right;
            } else {
                if(left < temp.size() && temp[left] > temp[chosen]) chosen = left;
                if(right < temp.size() && temp[right] > temp[chosen]) chosen = right;
            }

            if(chosen != idx) {
                swap(temp[idx], temp[chosen]);
                idx = chosen;
            } else break;
        }
    }

    return sorted;  // MinHeap -> ascending, MaxHeap -> descending
}

// ========================= DISPLAY =========================
void Heap::display() {
    if(heap.empty()) {
        cout << "Heap is empty.\n";
        return;
    }
    cout << (isMinHeap ? "Min Heap: " : "Max Heap: ");
    for(int v : heap) cout << v << " ";
    cout << endl;
}