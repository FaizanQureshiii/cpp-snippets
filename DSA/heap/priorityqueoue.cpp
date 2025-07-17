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

    void heapify(int i) {
        while(i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);                                     
            i = parent(i);                                                   
        }                                                                    
    }                                                                        
                                                                             
    void heapifydown(int i) {         //maxheapidy                                       
                                                                             
                                                                             
        int largest = i;
        int left = leftchild(i);
        int right = rightchild(i);

        if(left < size && arr[left] > arr[largest])
            largest = left;

        if(right < size && arr[right] > arr[largest])
            largest = right;

        if(largest != i) {
            swap(arr[i], arr[largest]);
            heapifydown(largest);
        }
    }

   
    void enqueue(int val) {
        if(size >= 100) {
            cout << "Queue Overflow" << endl;
            return;
        }
        arr[size] = val;
        heapify(size);
        size++;
    }

    void dequeue() {
        if(size == 0) {
            cout << "Queue Underflow" << endl;
            return;
        }
        arr[0] = arr[size - 1];
        size--;
        heapifydown(0);
    }

    int top() {
        if (size == 0) return -1;
        return arr[0];
    }

    bool isempty() {
        return size == 0;
    }

    void print() {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};
int main(){
    heap h;
    h.enqueue(1);
    h.enqueue(99);
    h.enqueue(22);
    h.enqueue(4);
    h.enqueue(34);
    h.print();
cout<<h.top()<<endl;
h.dequeue();
h.print();
cout<<h.top()<<endl;
}