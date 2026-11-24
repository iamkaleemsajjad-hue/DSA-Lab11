// Name: Muhammad Kaleem Sajjad
// CMS ID: 544147
// Class: BSCS-15E
// Lab 11 - Task 3: Heap Based Priority Queue

#include <iostream>
using namespace std;

const int CAPACITY = 20;

struct Job {
    int id;
    int priority;
};

// swap two Job records
void swapJobs(Job &a, Job &b) {
    Job temp = a;
    a = b;
    b = temp;
}

// move newly inserted job up if its priority is higher than parent
void heapifyUp(Job heap[], int size) {
    int i = size - 1;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].priority > heap[parent].priority) {
            swapJobs(heap[i], heap[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// fix heap downward from index i
void heapifyDown(Job heap[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != i) {
        swapJobs(heap[i], heap[largest]);
        heapifyDown(heap, size, largest);
    }
}

// insert a job into the priority queue
bool insertJob(Job heap[], int &size, int capacity, Job item) {
    if (size >= capacity) {
        cout << "Queue is full. Cannot insert job " << item.id << endl;
        return false;
    }
    heap[size] = item;
    size++;
    heapifyUp(heap, size);
    return true;
}

// look at the highest priority job without removing
bool peekJob(const Job heap[], int size, Job &item) {
    if (size == 0) {
        cout << "Queue is empty. Nothing to peek." << endl;
        return false;
    }
    item = heap[0];
    return true;
}

// remove the highest priority job
bool removeJob(Job heap[], int &size, Job &item) {
    if (size == 0) {
        cout << "Queue is empty. Nothing to remove." << endl;
        return false;
    }
    item = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapifyDown(heap, size, 0);
    return true;
}

// show all jobs in heap array order
void displayQueue(Job heap[], int size) {
    if (size == 0) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Jobs in heap order (not service order):" << endl;
    for (int i = 0; i < size; i++) {
        cout << "  Job ID: " << heap[i].id << "  Priority: " << heap[i].priority << endl;
    }
}

int main() {
    Job heap[CAPACITY];
    int size = 0;
    int choice;
    Job temp;

    cout << "=== Computer Lab Job Priority Queue ===" << endl;

    // run the required test sequence from the lab
    cout << "\n-- Running test sequence --" << endl;

    insertJob(heap, size, CAPACITY, {101, 3});
    insertJob(heap, size, CAPACITY, {102, 5});
    insertJob(heap, size, CAPACITY, {103, 1});
    insertJob(heap, size, CAPACITY, {104, 4});

    displayQueue(heap, size);

    if (peekJob(heap, size, temp))
        cout << "Peek: Job ID=" << temp.id << " Priority=" << temp.priority << " (size still " << size << ")" << endl;

    if (removeJob(heap, size, temp))
        cout << "Removed: Job ID=" << temp.id << " Priority=" << temp.priority << endl;

    insertJob(heap, size, CAPACITY, {105, 6});

    cout << "\nRemoving all remaining jobs in service order:" << endl;
    while (size > 0) {
        removeJob(heap, size, temp);
        cout << "  Served Job ID=" << temp.id << " Priority=" << temp.priority << endl;
    }

    // test empty queue operations
    cout << "\n-- Empty queue tests --" << endl;
    peekJob(heap, size, temp);
    removeJob(heap, size, temp);

    // fill up the queue to test full capacity
    cout << "\n-- Filling queue to capacity --" << endl;
    for (int i = 1; i <= CAPACITY + 1; i++) {
        Job j = {200 + i, i};
        insertJob(heap, size, CAPACITY, j);
    }

    // interactive menu
    cout << "\n\n=== Interactive Menu ===" << endl;
    do {
        cout << "\n1. Insert Job" << endl;
        cout << "2. Peek" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, pri;
            cout << "Enter Job ID and Priority: ";
            cin >> id >> pri;
            Job j = {id, pri};
            if (insertJob(heap, size, CAPACITY, j))
                cout << "Job inserted." << endl;
        } else if (choice == 2) {
            if (peekJob(heap, size, temp))
                cout << "Top Job: ID=" << temp.id << " Priority=" << temp.priority << endl;
        } else if (choice == 3) {
            if (removeJob(heap, size, temp))
                cout << "Removed Job: ID=" << temp.id << " Priority=" << temp.priority << endl;
        } else if (choice == 4) {
            displayQueue(heap, size);
        } else if (choice != 5) {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 5);

    cout << "Exiting." << endl;
    return 0;
}
