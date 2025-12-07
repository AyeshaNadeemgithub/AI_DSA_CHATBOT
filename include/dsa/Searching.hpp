#pragma once
#include <vector>

class Searching {
private:
    int linearSearchHelper(const std::vector<int>& arr, int target);
    int binarySearchHelper(const std::vector<int>& arr, int left, int right, int target);

public:
    Searching();

    int linearSearch(const std::vector<int>& arr, int target);
    int binarySearch(const std::vector<int>& arr, int target);

    void displayResult(int index, int target);
};