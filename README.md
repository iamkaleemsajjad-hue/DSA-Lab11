# Lab 11 - Heaps and Sorting Algorithms

**Name:** Muhammad Kaleem Sajjad  
**CMS:** 544147  
**Class:** BSCS-15E  
**Course:** Data Structures and Algorithms  
**Instructor:** Sara Tariq Sheikh  
**Lab Engineer:** Hassan Mohtashim  
**Date:** 24th November 2026  

---

## About This Lab

This lab covers heap data structures and sorting algorithms. We build a max heap from scratch, use it to sort an array, implement a priority queue for a job scheduling scenario, and also implement bubble sort and selection sort with operation counting.

---

## Files

| File | Task | Description |
|------|------|-------------|
| Q1.cpp | Task 1 | Build a max heap and verify heap property |
| Q2.cpp | Task 2 | Heap sort using the max heap from Task 1 |
| Q3.cpp | Task 3 | Heap based priority queue for job scheduling |
| Q4.cpp | Task 4 | Bubble sort (normal and optimized versions) |
| Q5.cpp | Task 5 | Selection sort with comparison against bubble sort |

---

## How to Compile and Run

Each file is an independent program. Compile them one by one using any C++11 or later compiler.

**Using g++:**
```
g++ Q1.cpp -o Q1.exe
g++ Q2.cpp -o Q2.exe
g++ Q3.cpp -o Q3.exe
g++ Q4.cpp -o Q4.exe
g++ Q5.cpp -o Q5.exe
```

Then run each one:
```
./Q1.exe
./Q2.exe
./Q3.exe
./Q4.exe
./Q5.exe
```

On Windows you can also open these files directly in Visual Studio, Code::Blocks, or Dev-C++ and run from there.

---

## Task Descriptions

### Task 1 - Building a Max Heap
Implements `maxHeapify` and `buildMaxHeap` functions. The input array `{35, 12, 43, 8, 51, 27, 19}` is turned into a valid max heap. The program prints the array before and after, then checks the parent-child property at every non-leaf node. Also tests an empty array, a single element, and repeated values.

### Task 2 - Heap Sort
Reuses the heap functions from Task 1. Builds a max heap once then repeatedly swaps the root with the last element, reduces the heap size, and calls heapify. The program prints the heap and sorted portions separately after each step so you can follow along. Tests include already sorted, reverse sorted, repeated values, and edge cases.

### Task 3 - Priority Queue
Implements a max-heap based priority queue using an array of `Job` structs (each job has an id and a priority). Higher priority number means the job is served first. Supports insert, peek, remove, and display operations. Has a menu for interactive use and also runs the required test sequence automatically at startup. Queue capacity is fixed at 20.

### Task 4 - Bubble Sort
Implements two versions of bubble sort. The normal version always does n-1 passes. The optimized version uses a swapped flag to stop early if a pass has no swaps, which makes it run in one pass on already sorted input. Both versions count and print the number of comparisons and swaps. Tests all three arrays from the lab spec plus edge cases.

### Task 5 - Selection Sort
Implements selection sort which finds the minimum in the unsorted portion and swaps it into position. Only swaps when the minimum is not already in place. Counts comparisons and swaps and prints the array after each pass. Uses the same three test arrays as Task 4 so results can be compared directly.

---

## Key Concepts

- In a max heap, every parent is greater than or equal to its children
- For index i, left child is at `2*i+1` and right child is at `2*i+2`
- Parent of index i is at `(i-1)/2`
- Heap sort is O(n log n) in the worst case
- Building a heap bottom-up is O(n)
- Optimized bubble sort is O(n) on already sorted input
- Selection sort always does the same number of comparisons no matter what order the input is in

---

## Submission

Submitted as `544147_Lab11_Heaps_and_Sorting.zip` containing Q1.cpp through Q5.cpp.
