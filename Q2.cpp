// Name: Muhammad Kaleem Sajjad
// CMS ID: 544147
// Class: BSCS-15E
// Lab 11 - Task 2: Heap Sort

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

// fix heap at index i, only within active heap of size n
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// print array showing heap and sorted parts separately
void printWithBoundary(int arr[], int heapSize, int total) {
    cout << "Heap: [";
    for (int i = 0; i < heapSize; i++) {
        cout << arr[i];
        if (i < heapSize - 1) cout << " ";
    }
    cout << "] Sorted: [";
    for (int i = heapSize; i < total; i++) {
        cout << arr[i];
        if (i < total - 1) cout << " ";
    }
    cout << "]" << endl;
}

void heapSort(int arr[], int n) {
    if (n <= 1) {
        cout << "Array has 0 or 1 element, already sorted." << endl;
        return;
    }

    // build the max heap first
    buildMaxHeap(arr, n);
    cout << "Max heap built: ";
    printArray(arr, n);

    // repeatedly take root (max) and place at end
    for (int i = n - 1; i > 0; i--) {
        // swap root with last element of active heap
        swap(arr[0], arr[i]);
        // restore heap for the reduced size
        maxHeapify(arr, i, 0);
        cout << "After swap and heapify: ";
        printWithBoundary(arr, i, n);
    }
}

void runTest(int arr[], int n, string label) {
    cout << "\n--- " << label << " ---" << endl;
    cout << "Before: ";
    printArray(arr, n);
    heapSort(arr, n);
    cout << "Final sorted: ";
    printArray(arr, n);
}

int main() {
    // main test from the lab
    int arr1[] = {35, 12, 43, 8, 51, 27, 19};
    int n1 = 7;
    runTest(arr1, n1, "Main array {35, 12, 43, 8, 51, 27, 19}");

    // already sorted
    int arr2[] = {1, 2, 3, 4, 5};
    runTest(arr2, 5, "Already sorted {1, 2, 3, 4, 5}");

    // reverse sorted
    int arr3[] = {5, 4, 3, 2, 1};
    runTest(arr3, 5, "Reverse sorted {5, 4, 3, 2, 1}");

    // repeated values
    int arr4[] = {3, 3, 3, 3};
    runTest(arr4, 4, "Repeated values {3, 3, 3, 3}");

    // single element
    int arr5[] = {7};
    runTest(arr5, 1, "Single element {7}");

    // empty
    int arr6[] = {};
    runTest(arr6, 0, "Empty array");

    return 0;
}
