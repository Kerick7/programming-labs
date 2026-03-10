#include "advanced_sorts.h"
#include <vector>

void CountingSort(vector<Character>& arr) {
    if (arr.empty()) {
        return;
    }
    int max_type = arr[0].attack;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].attack > max_type) {
            max_type = arr[i].attack;
        }
    }
    vector<int> count(max_type + 1, 0);
    for (int i = 1; i < arr.size(); i++) {
        count[arr[i].attack]++;
    }
    for (int i = 1; i <= max_type; i++) {
        count[i] += count[i - 1];
    }
    vector<Character> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        int type = arr[i].attack;
        output[count[type] - 1] = arr[i];
        count[type]--;
    }
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void RadixSort(vector<Character>& arr) {
    if (arr.empty()) {
        return;
    }
    int max_health = arr[0].health;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].health > max_health) {
            max_health = arr[i].health;
        }
    }
    for (int exp = 1; max_health / exp > 0; exp *=10) {
        vector<int> count(10, 0);
        vector<Character> output(arr.size());
        for (int i = 0; i < arr.size(); i++) {
            int digit = (arr[i].health / exp)%10;
            count[digit]++;
        }
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        for (int i = arr.size() - 1; i >= 0; i--) {
            int digit = (arr[i].health / exp)%10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = output[i];
        }
    }
}