
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Sorting {

private:

    // Helper functions
    void bubble(vector<int>& arr);
    void selection(vector<int>& arr);
    void mergeSort(vector<int>& arr, int left, int right);
    void merge(vector<int>& arr, int left, int mid, int right);
    void quickSort(vector<int>& arr, int low, int high);
    int partition(vector<int>& arr, int low, int high);

public:

    Sorting();  // constructor

    // User functions – return sorted arrays
    vector<int> bubbleSort(vector<int> arr);
    vector<int> selectionSort(vector<int> arr);
    vector<int> mergeSort(vector<int> arr);
    vector<int> quickSort(vector<int> arr);

    // Utility
    void display(vector<int> arr);
};




