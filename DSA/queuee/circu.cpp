#include<iostream>
using namespace std;

class Queuee {
public:
    int front, rear;
    int* arr;
    int size;
    int count;

    Queuee(int s = 10) {
        size = s + 1; // One extra space to separate full vs empty
        arr = new int[size];
        front = 0;
        rear = 0;
        count=0;
    }

    bool isFull() {
        return count == size - 1;
    }

    bool isEmpty() {
        return count==9;
    }

    void enqueuee(int data) {
        if (isFull()) {
            cout << "Queue is overflow!" << endl;
            return;
        }
        arr[rear] = data;
        rear = (rear + 1) % size;
        count++;
    }

    

    void dequeuee() {
        if (isEmpty()) {
            cout << "Queue is underflow!" << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % size;
        count--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (i != rear) {
            cout << arr[i] << " ";
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~Queuee() {
        delete[] arr;
    }
};
