#include <iostream>
#include <vector>
#include "dsa/Sorting.hpp"

using namespace std;

void print(const vector<int>& arr) {
    cout << "[ ";
    for (int x : arr) cout << x << " ";
    cout << "]";
}

bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int main() {

    Sorting sortObj;

    vector<int> arr = {5, 2, 9, 1, 5, 6};

    cout << "\n===== TESTING BUBBLE SORT =====\n";
    vector<int> bubble = sortObj.bubbleSort(arr);
    print(bubble);
    cout << "  -> " << (isSorted(bubble) ? "PASS" : "FAIL") << "\n";

    cout << "\n===== TESTING SELECTION SORT =====\n";
    vector<int> selection = sortObj.selectionSort(arr);
    print(selection);
    cout << "  -> " << (isSorted(selection) ? "PASS" : "FAIL") << "\n";

    cout << "\n===== TESTING MERGE SORT =====\n";
    vector<int> merge = sortObj.mergeSort(arr);
    print(merge);
    cout << "  -> " << (isSorted(merge) ? "PASS" : "FAIL") << "\n";

    cout << "\n===== TESTING QUICK SORT =====\n";
    vector<int> quick = sortObj.quickSort(arr);
    print(quick);
    cout << "  -> " << (isSorted(quick) ? "PASS" : "FAIL") << "\n";

    cout << "\n=== ALL SORT TESTS COMPLETE ===\n\n";

    return 0;
}