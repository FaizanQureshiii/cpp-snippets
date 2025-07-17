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

class LinkedList{
    public:
    Node*head;
    Node*tail;
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
    void Push_front(int val){
       Node* newNode=new Node(val);
       if(head==NULL){
        head=newNode;
        tail=newNode;
       } 
       else{
        newNode->next=head;
        head=newNode;
       }
    
    }
    void Push_back(int val){
        Node * newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }

    }
    void pop_front(){
        if(head==NULL){
            return;
        }
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
void insert(int val,int pos){
    Node*newNode=new Node(val);
    if(pos==0){
        Push_front(val);
        return ;
    }
    if(pos>0){
        Node*temp=head;
        for(int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
       

    }
}
void pop_back(){
    Node*temp=head;
    if(head==NULL){
        cout<<"list is empty"<<endl;
        return ;

    }
    while(temp->next!=tail){
        temp=temp->next;

    }
    temp->next=NULL;
    delete tail;
    temp=tail;
 }
void Printall(){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }

}
void remove(Node* head){
    Node* current=head;
    while(current!=NULL){
        Node*runner=current;
        while(runner!=NULL){
            if(runner->next->data==current->data){
                Node*temp=runner->next;
                runner->next=runner->next->next;
                delete temp;
            }
            else{
                runner=runner->next;
            }
        }
        current=current->next;
    }
}
void bubblesort(Node*head){
    Node*current=head;
    Node*nextnode;
    int temp;
    
}
};