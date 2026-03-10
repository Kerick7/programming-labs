#include "additional.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    else {
        return a > b;
    }
}

void print(const vector<string>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

string generateRandomWord() {
    int len = rand() % 8 + 3;
    string word = "";
    for (int i = 0; i < len; i++) {
        word += (char)('a' + rand() % 26);
    }
    return word;
}

vector<string> generateRandomArray(int size) {
    vector<string> result;
    for (int i = 0; i < size; i++) {
        result.push_back(generateRandomWord());
    }
    return result;
}

vector<string> generateAlmostSortedArray(int size) {
    vector<string> result = generateRandomArray(size);
    sort(result.begin(), result.end(), compare);
    int swaps = size * 0.05;
    for (int i = 0; i < swaps; i++) {
        int idx1 = rand() % result.size();
        int idx2 = rand() % result.size();
        swap(result[idx1], result[idx2]);
    }
    return result;
}

vector<string> generateAlmostUnsortedArray(int size) {
    vector<string> result = generateRandomArray(size);
    sort(result.begin(), result.end(), compare);
    reverse(result.begin(), result.end());
    int swaps = size * 0.05;
    for (int i = 0; i < swaps; i++) {
        int idx1 = rand() % result.size();
        int idx2 = rand() % result.size();
        swap(result[idx1], result[idx2]);
    }
    return result;
}
