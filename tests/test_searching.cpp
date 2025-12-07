#include <iostream>
#include "dsa/Searching.hpp"
using namespace std;

int main() {
    Searching s;

    vector<int> arr = {2, 5, 7, 10, 15, 20};

    cout << "===== Testing Linear Search =====\n";
    int idx1 = s.linearSearch(arr, 10);
    s.displayResult(idx1, 10);

    int idx2 = s.linearSearch(arr, 99);
    s.displayResult(idx2, 99);

    cout << "\n===== Testing Binary Search =====\n";
    int idx3 = s.binarySearch(arr, 15);
    s.displayResult(idx3, 15);

    int idx4 = s.binarySearch(arr, 100);
    s.displayResult(idx4, 100);

    return 0;
}