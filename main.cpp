#include "additional.h"
#include "sorts.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "models.h"
#include "advanced_sorts.h"
using namespace std;

void DemoMode() {
    vector<string> original = generateRandomArray(10);
    cout<<"---Original Array---"<<endl;
    print(original);
    cout<<"---Selection Sort Demo---"<<endl;
    vector<string> arr1 = original;
    SelectionSort(arr1, true);
    cout<<"---QuickSort Demo---"<<endl;
    vector<string> arr2 = original;
    QuickSort(arr2, 0, arr2.size() - 1, true);
    cout<<"---MergeSort Demo---"<<endl;
    vector<string> arr3 = original;
    MergeSort(arr3, 0, arr3.size() - 1, true);
    cout<<"---HybridSort Demo---"<<endl;
    vector<string> arr4 = original;
    HybridSort(arr4, 0, arr4.size() - 1, 3, true);
}

void BenchmarkMode() {
    int N = 10000;
    cout<<"Benchmark for N = "<<N<<endl;
    vector<string> arrRandom = generateRandomArray(N);
    vector<string> arrSorted = generateAlmostSortedArray(N);
    vector<string> arrUnsorted = generateAlmostUnsortedArray(N);
    cout<<"Selection Sort (Random): ";
    vector<string> copy1 = arrRandom;
    clock_t start = clock();
    SelectionSort(copy1, false);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"Quick Sort (Random): ";
    vector<string> copy2 = arrRandom;
    start = clock();
    QuickSort(copy2, 0, copy2.size() - 1, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"MergeSort (Random): ";
    vector<string> copy3 = arrRandom;
    start = clock();
    MergeSort(copy3, 0, copy3.size() - 1, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"HybridSort (Random): ";
    vector<string> copy4 = arrRandom;
    start = clock();
    HybridSort(copy4, 0, copy4.size() - 1, 15, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"std::sort (Random): ";
    vector<string> copy5 = arrRandom;
    start = clock();
    sort(copy5.begin(), copy5.end(), compare);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;


    cout<<"-----------------------"<<endl;
    cout<<"Selection Sort (Almost sorted): ";
    vector<string> copy11 = arrSorted;
    start = clock();
    SelectionSort(copy11, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"Quick Sort (Almost Sorted): ";
    vector<string> copy22 = arrSorted;
    start = clock();
    QuickSort(copy22, 0, copy22.size() - 1, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"MergeSort (Almost Sorted): ";
    vector<string> copy33 = arrSorted;
    start = clock();
    MergeSort(copy33, 0, copy33.size() - 1, false);
    clock_t end33 = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"HybridSort (Almost Sorted): ";
    vector<string> copy44 = arrSorted;
    start = clock();
    HybridSort(copy44, 0, copy44.size() - 1, 15, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"std::sort (Almost Sorted): ";
    vector<string> copy55 = arrSorted;
    start = clock();
    sort(copy55.begin(), copy55.end(), compare);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;



    cout<<"-----------------------"<<endl;
    cout<<"Selection Sort (Almost Unsorted): ";
    vector<string> copy111 = arrUnsorted;
    start = clock();
    SelectionSort(copy111, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"Quick Sort (Almost Unsorted): ";
    vector<string> copy222 = arrUnsorted;
    start = clock();
    QuickSort(copy222, 0, copy222.size() - 1, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"MergeSort (Almost Unsorted): ";
    vector<string> copy333 = arrUnsorted;
    start = clock();
    MergeSort(copy333, 0, copy333.size() - 1, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"HybridSort (Almost Unsorted): ";
    vector<string> copy444 = arrUnsorted;
    start = clock();
    HybridSort(copy444, 0, copy444.size() - 1, 15, false);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;
    cout<<"std::sort (Almost Unsorted): ";
    vector<string> copy555 = arrUnsorted;
    start = clock();
    sort(copy555.begin(), copy555.end(), compare);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<time<<" sec"<<endl;

    cout<<"---Finding Optimal Threshold---"<<endl;
    for (int t = 5; t <= 50; t += 5) {
        vector<string> copy_threshold = arrRandom;
        clock_t start_threshold = clock();
        HybridSort(copy_threshold, 0, copy_threshold.size() - 1, t, false);
        clock_t end_threshold = clock();
        time = (double)(end_threshold - start_threshold) / CLOCKS_PER_SEC;
        cout << "Threshold " << t << ": " << time << " sec" << endl;
    }
}

vector<Character> generateCharacters(int N) {
    vector<Character> arr;
    for (int i = 0; i < N; i++) {
        Character c;
        c.name = "Hero";
        c.attack = rand() % 5 + 1;
        c.health = rand() % 10000 + 1;
        arr.push_back(c);
    }
    return arr;
}

void Benchmark_3b() {
    int N = 100000;
    cout<<"---Benchmark 3-B---"<<endl;
    vector<Character> original = generateCharacters(N);
    vector<Character> copy1 = original;
    clock_t start = clock();
    CountingSort(copy1);
    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"Counting Sort (Attack Only): "<<time<<" sec"<<endl;
    vector<Character> copy2 = original;
    start = clock();
    RadixSort(copy2);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"Radix Sort (Health Only): "<<time<<" sec"<<endl;
    vector<Character> copy3 = original;
    start = clock();
    RadixSort(copy3);
    CountingSort(copy3);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"Combined (Radix + Counting): "<<time<<" sec"<<endl;
    vector<Character> copy4 = original;
    start = clock();
    sort(copy4.begin(), copy4.end(), compareCharacters);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    cout<<"std::sort (Combined): "<<time<<" sec"<<endl;
}

int main() {
    srand(time(0));
    int choice;
    cout<<"Enter programm mode:"<<endl;
    cout<<"1. Demo mode sorting words"<<endl;
    cout<<"2. Benchmark of base sort algorithms"<<endl;
    cout<<"3. Benchmark of Counting & Radix Sort"<<endl;
    cout<<"0. Exit"<<endl;
    do {
        cin>>choice;
        switch (choice) {
            case 1:
                DemoMode();
                break;
            case 2:
                BenchmarkMode();
                break;
            case 3:
                Benchmark_3b();
                break;
            case 0:
                cout<<"Exit"<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    }while(choice != 0);

    return 0;
}