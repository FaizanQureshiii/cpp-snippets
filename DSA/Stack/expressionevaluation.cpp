#include<iostream>
using namespace std;

class Stack {
public:
    int capacity = 100;
    int array[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(char value) {
        if (top < capacity - 1) {
            array[++top] = value;
        } else {
            cout << "Stack is overflow" << endl;
        }
    }

    void pop() {
        if (top > -1) {
            top--;
        } else {
            cout << "Stack is underflow" << endl;
        }
    }

    char peek() {
        if (top > -1) {
            return array[top];
        }
        return '\0'; // null character
    }

    bool isEmpty() {
        return top == -1;
    }

    // This is fixed: takes characters now, not strings
    bool isMatch(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    // This checks if brackets are balanced
    bool isBracketMatch(string s) {
        Stack st;

        for (char ch : s) {
            // If it's an opening bracket
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // If it's a closing bracket
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.isEmpty()) return false; // No opening bracket for this

                char lastOpen = st.peek(); // Look at the last opening bracket
                if (isMatch(lastOpen, ch)) {
                    st.pop(); // If match, pop it
                } else {
                    return false; // If not match, brackets are wrong
                }
            }
        }

        // At the end, stack should be empty
        return st.isEmpty();
    }
};
class queue{
    public:
    Stack st1,st2;
    int capacity;
    queue(int n):capacity(n){};
    void enqueue(int val){
        st1.push(val);
    }
    int dequeue(){
        if(!st2.isEmpty()){
            while(!st1.isEmpty()){
                st2.push(st1.pop());
            }
        }
        return st2.pop();
    }
    bool isempty(){
        return st1.isEmpty() && st2.isEmpty();
    }
};
// AIN FUNCTION
int main() {
    Stack st;

    string input1 = "[()]{}{[()()]()}";
    string input2 = "[(])";

    cout << "Input: " << input1 << " --> ";
    cout << (st.isBracketMatch(input1) ? "Balanced ✅" : "Not Balanced ❌") << endl;

    cout << "Input: " << input2 << " --> ";
    cout << (st.isBracketMatch(input2) ? "Balanced ✅" : "Not Balanced ❌") << endl;

    return 0;
}
