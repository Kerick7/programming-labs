#include "additional.h"
#include "sorts.h"
#include <iostream>
#include <algorithm>
using namespace std;

void SelectionSort(vector<string>& arr, bool isDemo) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int best_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (compare(arr[j], arr[best_idx])) {
                best_idx = j;
            }
        }
        if (best_idx != i) {
            swap(arr[i], arr[best_idx]);
        }
        if (isDemo) {
            print(arr);
        }
    }
}

int Partition(vector<string>& arr, int low, int high, bool isDemo) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    if (isDemo) {
        print(arr);
    }
    return i + 1;
}

void QuickSort(vector<string>& arr, int low, int high, bool isDemo) {
    if (low < high) {
        int pivot_idx = Partition(arr, low, high, isDemo);
        QuickSort(arr, low, pivot_idx - 1, isDemo);
        QuickSort(arr, pivot_idx + 1, high, isDemo);
    }
}

void Merge(vector<string>& arr, int left, int mid, int right, bool isDemo) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L;
    vector<string> R;
    for (int i = 0; i < n1; i++) {
        L.push_back(arr[left + i]);
    }
    for (int i = 0; i < n2; i++) {
        R.push_back(arr[mid + i + 1]);
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (compare(L[i], R[j])) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    if (isDemo) {
        print(arr);
    }
}

void MergeSort(vector<string>& arr, int left, int right, bool isDemo) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        MergeSort(arr, left, mid, isDemo);
        MergeSort(arr, mid + 1, right, isDemo);
        Merge(arr, left, mid, right, isDemo);
    }
}

void HybridSort(vector<string>& arr, int low, int high, int threshold, bool isDemo) {
    if (low < high) {
        int size = high - low + 1;
        if (size <= threshold) {
            vector<string> temp;
            for (int i = low; i <= high; i++) {
                temp.push_back(arr[i]);
            }
            SelectionSort(temp, isDemo);
            for (int i = low; i <= high; i++) {
                arr[i] = temp[i - low];
            }
        }
        else {
            int pivot_idx = Partition(arr, low, high, isDemo);
            HybridSort(arr, low, pivot_idx - 1, threshold, isDemo);
            HybridSort(arr, pivot_idx + 1, high, threshold, isDemo);
        }
    }
}


