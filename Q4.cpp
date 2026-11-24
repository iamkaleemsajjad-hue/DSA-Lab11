// Name: Muhammad Kaleem Sajjad
// CMS ID: 544147
// Class: BSCS-15E
// Lab 11 - Task 4: Bubble Sort (Normal and Optimized)

#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

// normal bubble sort with n-1 passes
void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        // each pass moves the next largest to its correct position
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);
    }

    cout << "Comparisons: " << comparisons << "  Swaps: " << swaps << endl;
}

// optimized bubble sort that stops early if no swap happened
void bubbleSortOptimized(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
                swapped = true;
            }
        }
        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);

        // if no swap in this pass then array is already sorted
        if (!swapped) {
            cout << "No swaps in this pass, stopping early." << endl;
            break;
        }
    }

    cout << "Comparisons: " << comparisons << "  Swaps: " << swaps << endl;
}

void runTest(int original[], int n, string label) {
    // copy the array twice so each version gets its own fresh copy
    int arr1[10], arr2[10];
    for (int i = 0; i < n; i++) {
        arr1[i] = original[i];
        arr2[i] = original[i];
    }

    cout << "\n=== " << label << " ===" << endl;

    cout << "\nNormal Bubble Sort:" << endl;
    if (n <= 1) {
        cout << "Array too small to sort." << endl;
    } else {
        bubbleSort(arr1, n);
        cout << "Result: ";
        printArray(arr1, n);
    }

    cout << "\nOptimized Bubble Sort:" << endl;
    if (n <= 1) {
        cout << "Array too small to sort." << endl;
    } else {
        bubbleSortOptimized(arr2, n);
        cout << "Result: ";
        printArray(arr2, n);
    }
}

int main() {
    // three main test arrays from the lab
    int a1[] = {5, 1, 4, 2, 8};
    int a2[] = {1, 2, 4, 5, 8};
    int a3[] = {8, 5, 4, 2, 1};

    runTest(a1, 5, "{5, 1, 4, 2, 8}");
    runTest(a2, 5, "Already sorted {1, 2, 4, 5, 8}");
    runTest(a3, 5, "Reverse sorted {8, 5, 4, 2, 1}");

    // repeated values
    int a4[] = {3, 3, 1, 3, 2};
    runTest(a4, 5, "Repeated values {3, 3, 1, 3, 2}");

    // edge cases
    int a5[] = {};
    runTest(a5, 0, "Empty array");

    int a6[] = {42};
    runTest(a6, 1, "Single element {42}");

    return 0;
}
