//
// Created by Junio Moreira on 2026-08-26.
//
#include <iostream>
#include <vector>

using namespace std;

int swapCount = 0;

int partitionLomuto(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] >= pivot) {
            i++;
            if (i != j) {
                swap(arr[i], arr[j]);
                swapCount++;
            }
        }
    }
    if (i + 1 != high) {
        swap(arr[i + 1], arr[high]);
        swapCount++;
    }
    return i + 1;
}

int quickSelect(vector<int>& arr, int low, int high, int k) {
    if (low <= high) {
        int pi = partitionLomuto(arr, low, high);

        if (pi == k) return arr[pi];
        if (pi > k) return quickSelect(arr, low, pi - 1, k);
        return quickSelect(arr, pi + 1, high, k);
    }
    return -1;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int kthElement = quickSelect(arr, 0, n - 1, k - 1);

    cout << kthElement << "\n";
    for (int i = 0; i < n; i++) cout << arr[i] << (i == n - 1 ? "" : " ");
    cout << "\n" << swapCount << "\n";

    return 0;
}