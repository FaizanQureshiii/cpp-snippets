#include<iostream>
using namespace std;

class heap {
    int arr[100];
    int size;

public:
    heap() {
        size = 0;
    }

    // Helper functions
    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    // ========== Max Heapify (for Priority Queue / Heap Sort / Kth Smallest) ==========

    void maxheapifyup(int i) {
        while(i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void maxheapifydown(int i) {
        int largest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        if(left < size && arr[left] > arr[largest]) largest = left;
        if(right < size && arr[right] > arr[largest]) largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            maxheapifydown(largest);
        }
    }

    // ========== Min Heapify (for Kth Largest) ==========

    void minheapifydown(int i) {
        int smallest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        if(left < size && arr[left] < arr[smallest]) smallest = left;
        if(right < size && arr[right] < arr[smallest]) smallest = right;

        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            minheapifydown(smallest);
        }
    }

    // ========== Priority Queue (Max Heap) ==========

    void enqueue(int val) {
        if(size >= 100) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[size] = val;
        maxheapifyup(size);
        size++;
    }

    void dequeue() {
        if(size == 0) {
            cout << "Queue Underflow" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        maxheapifydown(0);
    }

    int top() {
        if(size == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        return arr[0];
    }

    bool isempty() {
        return size == 0;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // ========== Heap Sort (Max Heap) ==========

    void sort(int array[], int n) {
        size = n;
        for(int i = 0; i < n; i++) arr[i] = array[i];

        for(int i = n/2 - 1; i >= 0; i--) maxheapifydown(i);

        for(int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            maxheapifydown(0);
        }

        for(int i = 0; i < n; i++) array[i] = arr[i];
    }

    // ========== Kth Largest Element (Min Heap of size k) ==========

    int kthlargest(int array[], int n, int k) {
        size = k;
        for(int i = 0; i < k; i++) arr[i] = array[i];

        for(int i = k/2 - 1; i >= 0; i--) minheapifydown(i);

        for(int i = k; i < n; i++) {
            if(array[i] > arr[0]) {
                arr[0] = array[i];
                minheapifydown(0);
            }
        }
        return arr[0];
    }

    // ========== Kth Smallest Element (Max Heap of size k) ==========

    int kthsmallest(int array[], int n, int k) {
        size = k;
        for(int i = 0; i < k; i++) arr[i] = array[i];

        for(int i = k/2 - 1; i >= 0; i--) maxheapifydown(i);

        for(int i = k; i < n; i++) {
            if(array[i] < arr[0]) {
                arr[0] = array[i];
                maxheapifydown(0);
            }
        }
        return arr[0];
    }
};

// ========== MAIN FUNCTION ==========

int main() {
    heap h;

    cout << "\n🚀 Priority Queue (Max Heap):\n";
    h.enqueue(10); h.enqueue(20); h.enqueue(30);
    h.enqueue(40); h.enqueue(70); h.enqueue(90);
    h.enqueue(50); h.enqueue(80); h.enqueue(60);

    h.print(); // Full heap
    h.dequeue(); // Removes 90
    h.print();
    h.dequeue(); // Removes 80
    h.print();

    int arr[] = {40, 10, 30, 50, 60, 90, 70, 20, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    cout << "\n🔍 " << k << "th Largest: " << h.kthlargest(arr, n, k) << endl;
    cout << "🔍 " << k << "th Smallest: " << h.kthsmallest(arr, n, k) << endl;

    h.sort(arr, n);
    cout << "\n🧹 Sorted Array: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    cout << "\n🎯 Top Element (Max): " << h.top() << endl;
}
