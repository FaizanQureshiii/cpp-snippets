#include<iostream>
#include<string>
using namespace std;
struct Car{
    int carID;
    string servicetype;
    int time;
};
class Queuee{
    public:
    Car queuee[5];
    int rear,front,count;
    Queuee(){
        rear=-1;
        front=-1;
        count=0;
    }
    bool isEmpty(){
        return count ==0;
    }
    bool isFull(){
        count==5-1;
    }
    void enqueuee(Car q){
        if(isFull()){
            cout<<"Queuee is full"<<endl;
        
        }
      
        rear=(rear+1)%5;
        queuee[rear]=q;
        count++;

    }
    void dequeuee(){
        if(isEmpty()){
            cout<<"Queuee is empty"<<endl;
        }
       
        front=(front+1)%5;
        cout<<"Car with ID "<<queuee[front].carID<<" is done with "<<queuee[front].servicetype<<endl;
        count--;
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queuee is empty"<<endl;
        }
        cout<<"Car with ID "<<queuee[front+1].carID<<" is done with "<<queuee[front+1].servicetype<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queuee is empty"<<endl;
        }
        int j=(front+1)%5;
        for(int i=front+1;i<=rear;i++){
            cout<<"Car with ID "<<queuee[i].carID<<" is done with "<<queuee[i].servicetype<<endl;
            j=(j+1)%5;
        } 
    }
};