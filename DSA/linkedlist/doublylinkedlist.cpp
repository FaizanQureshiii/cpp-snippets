#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node*next;
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};
class linklist{
    Node* head;
    public:
    linklist(){
        head=NULL;
    }
    void pushfront(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            return;
        }
        newNode->next=head;
        head->prev=newNode;
        head=newNode;

    }
    void pushback(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
        
    }

    void insertatpos(int data,int pos){
        Node* newNode=new Node(data);
        if(pos==0){
            pushfront(data);
            return;
        }
        Node * temp=head;
        while(temp->next->data!=pos-1){
            temp=temp->next;
        }
         
        newNode->next=temp->next;
        temp->prev=temp;
        temp->next->prev=newNode;
        temp->next=newNode;
    
    }

    void popfront(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        
    }
    void popback(){
        Node*temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
         temp->prev->next=NULL;
         temp->prev=NULL;
         delete temp;
    }
    
}