// Name: Muhammad Kaleem Sajjad
// CMS ID: 544147
// Class: BSCS-15E
// Lab 11 - Task 5: Selection Sort and Comparison

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

// selection sort finds the minimum in unsorted part and puts it in place
void selectionSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // find minimum in the remaining unsorted part
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // only swap if minimum is not already in place
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            swaps++;
        }

        cout << "Pass " << i + 1 << ": ";
        printArray(arr, n);
    }

    cout << "Comparisons: " << comparisons << "  Swaps: " << swaps << endl;
}

void runTest(int original[], int n, string label) {
    int arr[10];
    for (int i = 0; i < n; i++)
        arr[i] = original[i];

    cout << "\n=== " << label << " ===" << endl;

    if (n <= 1) {
        cout << "Array too small to sort." << endl;
        return;
    }

    cout << "Before: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Result: ";
    printArray(arr, n);
}

int main() {
    // same three arrays as task 4 for comparison
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

    cout << "\n--- Summary ---" << endl;
    cout << "Selection sort always does the same number of comparisons regardless of input order." << endl;
    cout << "It scans sorted input fully because it does not know the array is already sorted." << endl;
    cout << "Maximum swaps for n elements is n-1 because each pass places one element correctly." << endl;

    return 0;
}
