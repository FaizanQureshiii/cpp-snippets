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
    List(){
        head=NULL;
        tail=NULL;
      }

      void push_list(int value){                         // Worst-case time complexity: O(n)
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
      void reverseList(){
        Node* prev=NULL;
        Node*current=head;
        Node*next=NULL;
        while(current!=NULL){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        cout<<"reverse of link list is :";
        while(prev!=NULL){
            cout<<prev->data<<" ";
            prev=prev->next;
        }
      }











    };

    int main(){
        List list;
        list.push_list(1);
        list.push_list(2);
        list.push_list(3);
        list.push_list(4);
        list.push_list(5);
        list.reverseList();
    }