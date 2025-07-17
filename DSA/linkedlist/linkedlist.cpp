#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // O(1) - Constant Time
    void insertNodeAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // O(n) - Worst Case: traverses entire list if key is at end
    void insertNodeInMiddle(int data, int key) {
        if (head == NULL) return;
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) return;
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == tail) tail = newNode;
    }

    // O(1) - Constant Time
    void insertNodeAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // O(1) - Constant Time
    bool deleteFirstNode() {
        if (head == NULL) return false;
        Node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        return true;
    }

    // O(n) - Worst Case: search entire list for key
    bool deleteNode(int key) {
        if (head == NULL)
        {

         return false;
        }
        if (head->data == key)
        {

         return deleteFirstNode();
        }
        Node* temp = head;
        while (temp->next && temp->next->data != key) {
            temp = temp->next;
        }
        if (!temp->next) return false;
        Node* del = temp->next;
        temp->next = del->next;
        if (del == tail) tail = temp;
        delete del;
        return true;
    }

    // O(n) - Worst Case: traverse entire list to find last node
    bool deleteLastNode() {
        if (head == NULL) return false;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return true;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
        return true;
    }

    // O(n) - Worst Case: data at end of list
    bool search(int data) {
        Node* temp = head;
        while (temp) {
            if (temp->data == data) return true;
            temp = temp->next;
        }
        return false;
    }

    // O(1)
   
int checkHead() {
        if (head == NULL) return -1;
        return head->data;
    }

    // O(1)
    int checkTail() {
        if (tail == NULL) return -1;
        return tail->data;
    }
    // O(n)
    void display() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
};

class stackUsingLinkedList {
private:
    LinkedList Stack;
public:
    void push(int x) {
        Stack.insertNodeAtBeginning(x);
    }
    int pop() {
        int top = Stack.checkHead() ;
        Stack.deleteFirstNode();
        return top;
    }
    int top(int x) {
        return Stack.checkHead();
    }
    bool IsEmpty(int x) {
        return Stack.checkHead() == -1;
    }
    void display() {
        Stack.display();
    }
};

class QueueUsingLinkedList {
private:
    LinkedList Queue;
public:
    void Enqueue(int x) {
        Queue.insertNodeAtEnd(x);
    }
    int DeQueue() {
        int front = Queue.checkHead();
        Queue.deleteFirstNode();
        return front;
    }
    int Front(int x) {
        return Queue.checkHead();
    }
    bool IsEmpty(int x) {
        return Queue.checkHead() == -1;
    }
    void display() {
        Queue.display();
    }
};

/* To make this a circular queue using linked list:
   - Make the tail->next point to head.
   - Update insertNodeAtEnd and delete operations accordingly.
   - Traverse with a stopping condition: temp != head again. */
