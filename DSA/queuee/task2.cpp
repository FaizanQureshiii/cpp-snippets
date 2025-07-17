#include<iostream>
using namespace std;
class Queuee{
    public:
    int front;int rear;
    int * arr;
    int size=10;
    Queuee(){
        arr=new int[size];
        front = rear=0;

    }
    void enqueuee(int data){
        if(rear==size){
            cout<<"queuee is fill"<<endl;

        }
        arr[++rear]=data;
    }

    void dequeuee(){
        if(front==rear){
            cout<<"queuee is empty"<<endl;
        }
        for(int i=front +1;i<rear;i++){
            arr[i-1]=arr[i];
        }
        rear--;
    }
    bool isEmpty(){
        return front==rear;
        }
        void print (){
            for(int i=front;i<rear;i++){
                cout<<arr[i]<<" ";
            } 
        }
};
int main(){
    Queuee q;
    q.enqueuee(1);
    q.enqueuee(2);
    q.enqueuee(3);
    q.enqueuee(4);
    q.enqueuee(5); 
    q.dequeuee();
    q.print();
    return 0;
}