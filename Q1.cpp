// Name: Muhammad Kaleem Sajjad
// CMS ID: 544147
// Class: BSCS-15E
// Lab 11 - Task 1: Building a Max Heap

#include <iostream>
using namespace std;

// swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
}

// fix the heap property at index i (downward)
void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // check if left child is bigger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check if right child is bigger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not the largest then swap and fix downward
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

// build max heap from any array
void buildMaxHeap(int arr[], int n) {
    // start from last non-leaf and go up
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
}

// verify parent-child property at every non-leaf
void verifyHeap(int arr[], int n) {
    bool valid = true;
    for (int i = 0; i < n / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[i] < arr[left]) {
            cout << "Heap violation at index " << i << " and left child " << left << endl;
            valid = false;
        }
        if (right < n && arr[i] < arr[right]) {
            cout << "Heap violation at index " << i << " and right child " << right << endl;
            valid = false;
        }
    }
    if (valid)
        cout << "Heap property is valid at all nodes." << endl;
}

// run a test case
void runTest(int arr[], int n, string label) {
    cout << "\n--- " << label << " ---" << endl;

    if (n == 0) {
        cout << "Array is empty, nothing to do." << endl;
        return;
    }

    cout << "Before: ";
    printArray(arr, n);

    buildMaxHeap(arr, n);

    cout << "After:  ";
    printArray(arr, n);

    verifyHeap(arr, n);
}

int main() {
    // main test array from the lab
    int arr1[] = {35, 12, 43, 8, 51, 27, 19};
    int n1 = 7;
    runTest(arr1, n1, "Main array {35, 12, 43, 8, 51, 27, 19}");

    // empty array test
    int arr2[] = {};
    runTest(arr2, 0, "Empty array");

    // single element test
    int arr3[] = {10};
    runTest(arr3, 1, "Single element {10}");

    // repeated values test
    int arr4[] = {5, 5, 5, 5, 5};
    int n4 = 5;
    runTest(arr4, n4, "Repeated values {5, 5, 5, 5, 5}");

    return 0;
}
