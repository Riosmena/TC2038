// ====================================================
// File: main.cpp
// Authors: José Emiliano Riosmena Castañón - A01704245
//          María Azul Rosales Nachón - A01706348
//          Mauricio García Villanueva - A01704098
// Date: Friday, August 25th, 2025
// ====================================================

#include <iostream>
#include <vector>

using namespace std;

// Merge function to merge two sorted subarrays
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    // Copy data to temporary arrays left and right
    for (int i = 0; i < n1; i++) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    // Merge the temporary arrays back into arr
    while (i < n1 && j < n2) {
        if (left[i] >= right[j]) {
            arr[k] = left[i];
            i++;
        }

        else {
            arr[k] = right[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of left
    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right
    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// =========================
// Complexity: O(n)
// =========================

// Merge sort function using divide and conquer
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}
// ============================
// Complexity: O(n log n)
// ============================

int main(int argc, char* argv[]) {
    int selection;
    int n;
    vector<int> arr;

    cout << "Welcome, which case would you like to evaluate?" << endl;
    cout << "========================================================" << endl;
    cout << "1. Average case (7 elements)" << endl;
    cout << "2. Average case (10 elements)" << endl;
    cout << "3. Best case (10 elements)" << endl;
    cout << "4. Worst case (14 elements)" << endl;
    cout << "========================================================" << endl;
    cout << "Choose an option: ";
    cin >> selection;

    switch (selection) {
        case 1:
            arr = {38, 27, 43, 3, 9, 82, 10};
            n = arr.size();

            cout << "\nOriginal array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            mergeSort(arr, 0, n - 1);           

            cout << "Sorted array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            break;

        case 2:
            arr = {5, 2, 7, 6, 2, 1, 0, 3, 9, 4};
            n = arr.size();

            cout << "\nOriginal array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            mergeSort(arr, 0, n - 1);           

            cout << "Sorted array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            break;

        // Best case, array is already sorted
        case 3:
            arr = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
            n = arr.size();

            cout << "\nOriginal array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            mergeSort(arr, 0, n - 1);           

            cout << "Sorted array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            break;

        // Worst case: The array is sorted backwards.
        case 4:
            arr = {1, 3, 4, 6, 8, 9, 11, 12, 14, 15, 17, 18, 19, 20};
            n = arr.size();

            cout << "\nOriginal array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            mergeSort(arr, 0, n - 1);           

            cout << "Sorted array: ";
            for (int num : arr) {
                cout << num << " ";
            }
            cout << endl;

            break;

        default:
            cout << "\nInvalid Option" << endl;
            break;
    }
    
    return 0;
}