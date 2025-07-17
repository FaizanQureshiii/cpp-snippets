#include<iostream>
#include<string>
using namespace std;

class Queue {
    public:
    int *arr;
    int size;
    int front;
    int rear;
    string *names;

    Queue() {
        size = 1000;
        arr = new int[size];
        names = new string[size];
        front = 0;
        rear = 0;
    }
    void enqueue(string name,int number){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            names[rear]=name;
            arr[rear]=number;
            rear++;
        }
    }

    //dequeue(): removes the first customer call from the queue.
    void dequeue(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            for(int i=front+1;i<rear;i++){
                names[i-1]=names[i];
                arr[i-1]=arr[i];
            }
            rear--;
        }
    }

    void peek(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            cout<<"The first customer call is "<<names[front]<<" with number "<<arr[front]<<endl;

        }
    }
    bool isempty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }

     
};
int main(){
    Queue q;
    q.enqueue("John",123456789);
    q.enqueue("Jane",987654321);
    q.enqueue("Jack",111111111);
    q.enqueue("Jill",222222222);
    q.enqueue("Joe",333333333);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.peek(); 
}
