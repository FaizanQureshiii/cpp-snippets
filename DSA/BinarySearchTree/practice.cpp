#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;
    
    Node(int val){
        value = val;
        left = nullptr;
        right = nullptr;
    }
};
class BST{
    private:
    Node* root;
    Node*insert(int value,Node*node){
        if(node==NULL){
            return new Node(value);
        }
        if(value<node->value){
            node->left=insert(value,node->left);
        }
        if(value>node->value){
            node->right=insert(value,node->right);
        }
    }
bool search(int key,Node*node){
    if(node==NULL){
    return false;
    }
if(key>node->value){
    return search(key,node->right);
}
if(key<node->value){
    return search(key,node->left);
}
}

Node*deletenode(int key ,Node*node){
if(node==NULL){
    return NULL;
}
if(key<node->value){
    node->left=deletenode(key,node->left);
}
if(key>node->value){
    node->right=deletenode(key,node->right);
}
else{
    if(!node->left && !node->right){
        delete node;
        return NULL;
    }else if(!node->left){
        Node*temp=node->right;
        delete node;
        return temp;
    }
    else if(!node->right){
        Node*temp=node->left;
        delete node;
        return temp;
        
    }
    
}
return node;
}
};