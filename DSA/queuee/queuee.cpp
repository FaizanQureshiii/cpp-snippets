#include<iostream>
using namespace std;

class Queue {
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue() {
        size = 1000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear++] = data;
        }
    }

    void dequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
        } else {
            for (int i = front + 1; i < rear; i++) {
                arr[i - 1] = arr[i];
            }
            rear--;
        }
    }

    bool isempty() {
        return front == rear;
    }

    void print() {
        for (int i = front; i < rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2); 
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    q.dequeue();
    q.dequeue();
    q.print();
}