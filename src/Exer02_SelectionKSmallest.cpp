//
// Created by Junio Moreira on 2026-08-26.
//#include <iostream>
#include <vector>
#include <string>

using namespace std;

void merge(vector<string>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].length() >= R[j].length()) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<string>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partitionLomuto(vector<string>& arr, int low, int high) {
    string pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        // Instável: trocas de longa distância ignoram a ordem relativa original
        if (arr[j].length() > pivot.length()) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<string>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionLomuto(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<string> arrMerge = original;
    vector<string> arrQuick = original;

    mergeSort(arrMerge, 0, n - 1);
    quickSort(arrQuick, 0, n - 1);

    cout << "[MergeSort] ";
    for (int i = 0; i < n; i++) cout << arrMerge[i] << (i == n - 1 ? "" : " ");
    cout << "\n[QuickSort] ";
    for (int i = 0; i < n; i++) cout << arrQuick[i] << (i == n - 1 ? "" : " ");
    cout << "\n";



    return 0;
}