//
// Created by Junio Moreira on 2026-08-26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int i = -1, j = n;
    while (true) {
        do { i++; } while (i < n && arr[i] % 2 == 0);
        do { j--; } while (j >= 0 && arr[j] % 2 != 0);
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }


    if (j >= 0) {
        sort(arr.begin(), arr.begin() + j + 1);
    }

    if (j + 1 < n) {
        sort(arr.begin() + j + 1, arr.end(), greater<int>());
    }

    for (int k = 0; k < n; k++) {
        cout << arr[k] << (k == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}