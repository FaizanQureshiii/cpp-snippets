#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    // Push at the END for ascending order
    void Push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* mergelist(Node* h1, Node* h2){
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;

        if(h1->data <= h2->data){
            h1->next = mergelist(h1->next, h2);
            return h1;
        }
        else{
            h2->next = mergelist(h1, h2->next);
            return h2;
        }
    }

    void print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    LinkedList l1;
    l1.Push_back(10);
    l1.Push_back(20);
    l1.Push_back(30);
    l1.Push_back(40);
    l1.Push_back(50);

    LinkedList l2;
    l2.Push_back(15);
    l2.Push_back(25);
    l2.Push_back(35);
    l2.Push_back(45);
    l2.Push_back(55);

    LinkedList l3;
    l3.head = l3.mergelist(l1.head, l2.head);

    cout << "Merged List: ";
    l3.print();

    return 0;
}
