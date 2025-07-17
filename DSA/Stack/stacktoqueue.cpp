#include <iostream>
using namespace std;

// ========== Custom Stack Class ==========
class Stack {
private:
    int* arr;
    int topIndex;
    int size;

public:
    Stack() {
        arr = nullptr;
        topIndex = -1;
        size = 0;
    }

    Stack(int n) {
        size = n;
        arr = new int[size];
        topIndex = -1;
    }

    void push(int val) {
        if (topIndex >= size - 1) {
            cout << "Stack is full!" << endl;
            return;
        }
        arr[++topIndex] = val;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex--];
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

// ========== Queue Using Two Stacks ==========
class Queue {
private:
    Stack s1, s2;
    int capacity;

public:
    Queue(int n) : s1(n), s2(n), capacity(n) {}

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        if (s2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s2.pop();
    }

    int front() {
        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }

        if (s2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return s2.peek();
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }
};

// ========== Driver Code ==========
int main() {
    Queue q(10);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front: " << q.front() << endl;      // Should print 10
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 10
    cout << "Front: " << q.front() << endl;      // Should print 20

    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl; // Should print 20
    cout << "Front: " << q.front() << endl;      // Should print 30

    return 0;
}
