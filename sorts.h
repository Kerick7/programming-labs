#ifndef UNTITLED2_SORTS_H
#define UNTITLED2_SORTS_H

#include <string>
#include <vector>
using namespace std;

void SelectionSort(vector<string>& arr, bool isDemo);
void QuickSort(vector<string>& arr, int low, int high, bool isDemo);
void MergeSort(vector<string>& arr, int left, int right, bool isDemo);
void HybridSort(vector<string>& arr, int low, int high, int threshold, bool isDemo);

#endif //UNTITLED2_SORTS_H