#include "dsa/Searching.hpp"
#include <iostream>

Searching::Searching() {}

// -------- Linear Search --------
int Searching::linearSearchHelper(const std::vector<int>& arr, int target) {
    for(int i = 0; i < arr.size(); i++)
        if(arr[i] == target) return i;

    return -1;
}

int Searching::linearSearch(const std::vector<int>& arr, int target) {
    return linearSearchHelper(arr, target);
}

// -------- Binary Search --------
int Searching::binarySearchHelper(const std::vector<int>& arr, int left, int right, int target) {
    if(left <= right) {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) return mid;
        if(target < arr[mid])
            return binarySearchHelper(arr, left, mid - 1, target);

        return binarySearchHelper(arr, mid + 1, right, target);
    }
    return -1;
}

int Searching::binarySearch(const std::vector<int>& arr, int target) {
    return binarySearchHelper(arr, 0, arr.size() - 1, target);
}

// -------- Utility --------
void Searching::displayResult(int index, int target) {
    if(index != -1)
        std::cout << "Element " << target << " found at index: " << index << "\n";
    else
        std::cout << "Element " << target << " not found.\n";
}