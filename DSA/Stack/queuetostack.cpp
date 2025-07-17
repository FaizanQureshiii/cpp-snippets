#include <iostream>
using namespace std;

// =================== QUEUE CLASS ====================
class Queue {
private:
    int* arr;
    int frontIndex, rearIndex, size, capacity;

public:
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        frontIndex = 0;
        rearIndex = -1;
        size = 0;
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = val;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        int val = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        size--;
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return -1;
        }
        return arr[frontIndex];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    int getSize() {
        return size;
    }
};

// =================== STACK USING TWO QUEUES ====================
class Stack {
private:
    Queue* q1;
    Queue* q2;
    int capacity;

public:
    Stack(int cap) {
        capacity = cap;
        q1 = new Queue(cap);
        q2 = new Queue(cap);
    }

    void push(int val) {
        // Step 1: enqueue to q2
        q2->enqueue(val);

        // Step 2: Move all elements from q1 to q2
        while (!q1->isEmpty()) {
            q2->enqueue(q1->dequeue());
        }

        // Step 3: swap q1 and q2
        Queue* temp = q1;
        q1 = q2;
        q2 = temp;
    }

    int pop() {
        if (q1->isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q1->dequeue();
    }

    int top() {
        if (q1->isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return q1->front();
    }

    bool isEmpty() {
        return q1->isEmpty();
    }
};

// =================== MAIN FUNCTION ====================
int main() {
    Stack s(10);

    s.push(5);
    s.push(10);
    s.push(15);

    cout << "Top: " << s.top() << endl;     // 15
    cout << "Pop: " << s.pop() << endl;     // 15
    cout << "Top: " << s.top() << endl;     // 10
    cout << "Is Empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.pop();
    s.pop();
    s.pop(); // Should say "Stack is Empty!"

    return 0;
}
