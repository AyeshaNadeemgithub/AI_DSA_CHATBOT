#include "dsa/Sorting.hpp"

// Constructor
Sorting::Sorting() {}

// ===================== BUBBLE SORT =====================

void Sorting::bubble(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

vector<int> Sorting::bubbleSort(vector<int> arr) {
    bubble(arr);
    return arr;
}


// ===================== SELECTION SORT =====================

void Sorting::selection(vector<int>& arr) {
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

vector<int> Sorting::selectionSort(vector<int> arr) {
    selection(arr);
    return arr;
}


// ===================== MERGE SORT =====================

void Sorting::merge(vector<int>& arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
}

void Sorting::mergeSort(vector<int>& arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

vector<int> Sorting::mergeSort(vector<int> arr) {
    mergeSort(arr, 0, arr.size() - 1);
    return arr;
}


// ===================== QUICK SORT =====================

int Sorting::partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}

void Sorting::quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

vector<int> Sorting::quickSort(vector<int> arr) {
    quickSort(arr, 0, arr.size() - 1);
    return arr;
}


// ===================== UTILITY =====================

void Sorting::display(vector<int> arr){
    cout << "[ ";
    for(int x : arr){
        cout << x << " ";
    }
    cout << "]" << endl;
}