#include<iostream>
#include<string>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};


class List{
    Node* head;
    Node* tail;
    public:
    int count=0;
    List(){
        head=NULL;
        tail=NULL;
    }
    void push_list(int value){
        Node*newNode=new Node(value);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;

        }else{
            newNode->next=head;
            head=newNode;
        }
      }
     void middleelement(){
       Node* slow=head;
       Node* fast=head;
       while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
       cout<<"the middle element is "<<slow->data<<endl;



    }







    };
    int main(){

        List fai;
        fai.push_list(10);
        fai.push_list(20);
        fai.push_list(30);
        fai.push_list(40);
    
       
        fai.middleelement();
        return 0;
    }