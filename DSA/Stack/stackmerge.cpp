#include<iostream>
using namespace std;

class stack {
    int* arr;
    int top;
    int size;
public:
    stack(int s = 10) {
        size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int val) {
        if (top >= size - 1) {
            cout << "Stack Overflow!" << endl;
        } else {
            arr[++top] = val;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow!" << endl;
            return -1;
        } else {
            return arr[top--];
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    bool Isempty() {
        return top == -1;
    }

    void display() {
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Merging two sorted stacks into one sorted stack (descending order)
/*stack merge(stack& s1, stack& s2, int size) {
    stack temp1(size), temp2(size), result(size * 2);

    // Reverse s1 into temp1
    while (!s1.Isempty()) {
        temp1.push(s1.pop());
    }

    // Reverse s2 into temp2
    while (!s2.Isempty()) {
        temp2.push(s2.pop());
    }

    // Merge both into result
    while (!temp1.Isempty() && !temp2.Isempty()) {
        if (temp1.peek() > temp2.peek()) {
            result.push(temp1.pop());
        } else {
            result.push(temp2.pop());
        }
    }

    while (!temp1.Isempty()) result.push(temp1.pop());
    while (!temp2.Isempty()) result.push(temp2.pop());

    return result;
}
    */

    stack merge(stack& arr1,stack& arr2,int size){
        stack temp1(size),temp2(size),result(size*2);
        while(!arr1.Isempty()){
           temp1.push(arr1.pop());
        }
        while(!arr2.Isempty()){
            temp2.push(arr2.pop());
        }
        while(!temp1.Isempty() && !temp2.Isempty()){
            if(temp1.peek()>temp2.peek()){
                result.push(temp1.pop());
            }
            else{
                result.push(temp2.pop());
            }
        }
        while(!temp1.Isempty()){
            result.push(temp1.pop());
        }
        while(!temp2.Isempty()){
            result.push(temp2.pop());
        }
        return result;
    }

// Driver code
int main() {
    stack s1(5), s2(5);

    // Sorted stacks (ascending order)
    s1.push(1);
    s1.push(3);
    s1.push(5);

    s2.push(2);
    s2.push(4);
    s2.push(6);

    cout << "Stack 1: ";
    s1.display();
    cout << "Stack 2: ";
    s2.display();

    stack result = merge(s1, s2, 5);
    cout << "Merged Stack: ";
    result.display();

    return 0;
}
