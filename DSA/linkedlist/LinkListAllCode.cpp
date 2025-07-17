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

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    void pop_back() {
        if (head == NULL) return;
        if (head == tail) {
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        if (newNode->next == NULL) tail = newNode;
    }

    Node* mergelist(Node* h1, Node* h2) {
        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;

        if (h1->data <= h2->data) {
            h1->next = mergelist(h1->next, h2);
            return h1;
        } else {
            h2->next = mergelist(h1, h2->next);
            return h2;
        }
    }

    Node* reverselist(Node* head) {
        Node* prev = NULL;
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        Node* rev = reverselist(head);
        Node* temp1 = head;
        Node* temp2 = rev; 
        while (temp1 && temp2) {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    void middleoflist() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    bool cycledetection() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    void createcycle() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head; // Creates a cycle
    }

    void deletion(int val) {
        if (head == NULL) return;

        if (head->data == val) {
            pop_front();
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found" << endl;
            return;
        }

        Node* todelete = temp->next;
        temp->next = todelete->next;
        delete todelete;

        if (temp->next == NULL) tail = temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(5);

    cout << "Original list: ";
    list.display();

    list.pop_front();
    list.pop_back();

    cout << "List after popping front and back: ";
    list.display();

    list.insert(6, 2);
    cout << "List after inserting 6 at position 2: ";
    list.display();

    // Testing merge
    List list1, list2;
    list1.push_back(1);
    list1.push_back(3);
    list1.push_back(5);

    list2.push_back(2);
    list2.push_back(4);
    list2.push_back(6);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    List mergedList;
    mergedList.head = mergedList.mergelist(list1.head, list2.head);

    cout << "Merged List: ";
    mergedList.display();

    // Middle of list
    list.middleoflist();

    // Cycle detection
    if (list.cycledetection())
        cout << "Cycle is present" << endl;
    else
        cout << "Cycle is not present" << endl;

    // Palindrome check
    List list3;
    list3.push_front(1);
    list3.push_front(2);
    list3.push_front(2);
    list3.push_front(1);

    if (list3.isPalindrome(list3.head))
        cout << "List is palindrome" << endl;
    else
        cout << "List is not palindrome" << endl;
    mergedList.middleoflist();
    mergedList.deletion(4);
    mergedList.display();
    return 0;
}
