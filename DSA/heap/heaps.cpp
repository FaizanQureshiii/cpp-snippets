#include<iostream>
using namespace std;

class heap {
    int arr[100];
    int size;

public:
    heap() {
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftchild(int i) { return 2 * i + 1; }
    int rightchild(int i) { return 2 * i + 2; }

    // Max Heapify Up
    void heapifyup(int i) {
        while (i > 0 && arr[i] > arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Max Heapify Down
    void heapifydown(int i) {
        int largest = i;
        int left = leftchild(i);
        int right = rightchild(i);
        if (left < size && arr[left] > arr[largest]) largest = left;
        if (right < size && arr[right] > arr[largest]) largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifydown(largest);
        }
    }

    // Min Heapify Up
    void heapifyupmin(int i) {
        while (i > 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    // Min Heapify Down
    void heapifydownmin(int i) {
        int smallest = i;
        int left = leftchild(i);
        int right = rightchild(i);
        if (left < size && arr[left] < arr[smallest]) smallest = left;
        if (right < size && arr[right] < arr[smallest]) smallest = right;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapifydownmin(smallest);
        }
    }

    // Max Heap Insert & Delete
    void insert(int val) {
        if (size >= 100) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = val;
        heapifyup(size);
        size++;
    }

    void deletefromheap() {
        if (size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapifydown(0);
    }

    // Min Heap Insert & Delete
    void insertmin(int val) {
        if (size >= 100) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = val;
        heapifyupmin(size);
        size++;
    }

    void deletemin() {
        if (size == 0) return;
        arr[0] = arr[size - 1];
        size--;
        heapifydownmin(0);
    }

    bool isempty() {
        return size == 0;
    }

    int top() {
        return arr[0];
    }

    // Heap Sort for Max Heap
    void heapSort() {
        int originalSize = size;
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            heapifydown(0);
        }
        cout << "Sorted (accending): ";
        for (int i = 0; i < originalSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        size = originalSize;
    }

    void heapsortmin() {
        int originalSize = size;
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            size--;
            heapifydownmin(0);
        }
        cout << "Sorted (decending): ";
        for (int i = 0; i < originalSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        size = originalSize;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insert(190);
    h.insert(60);
    h.insert(80);
    h.insert(52);
    h.insert(10);

    cout << "Heap structure: ";
    h.print();

    cout << "Top element: " << h.top() << endl;

    h.heapSort();
    h.heapsortmin();
    cout<<"top ele men "<<h.top()<<endl;
   
}
