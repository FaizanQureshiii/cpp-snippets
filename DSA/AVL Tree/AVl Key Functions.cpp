#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int data){
        this->data=data;
        left=nullptr;
        right=nullptr;
        height=0;
    }
};
class Avl{
    public:
    Node*root;
    Avl(){
        root=nullptr;
    }

   
    int height(Node* node) {
        if (node == nullptr) return -1;
        return node->height;
    }


    int maxHeight(int a, int b) {
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    

void insert(int data) {
    root = insert(root, data);

}

    Node*insert(Node*root,int data)
    {
        if(root==NULL){
            return new Node(data);
            
        }
        if(data<root->data){
            root->left=insert(root->left,data);

            }
            else{
                root->right=insert(root->right,data);
            }
            root->height = maxHeight(height(root->left), height(root->right)) + 1;
            return rotate(root);
    }

    Node *rotate(Node* node){
        int balance=height(node->left)-height(node->right);
        if(balance>1){
            //ll
            if(height(node->left->left)>=height(node->left->right)){
                return RotateRight(node);
            }
            else if(height(node->left->right)>height(node->left->left)){
                node->left=RotateLeft(node->left);
                return RotateRight(node);
            } 
        }
        if(balance<-1){
            //rr
            if(height(node->right->right)>=height(node->right->left)){
                return RotateLeft(node);
            }
            else if(height(node->right->left)>height(node->right->right)){
                node->right=RotateRight(node->right);
                return RotateLeft(node);
            }
        }
    }
    Node*RotateRight(Node*p){
        Node*c=p->left;
        Node*t=c->right;
        c->right=p;
        p->left=t;
        p->height=maxHeight(height(p->left),height(p->right))+1;
        c->height=maxHeight(height(c->left),height(c->right))+1;
        return c;
    }
    Node* RotateLeft(Node* c) {
        Node* p = c->right;
        Node* t = p->left;

        p->left = c;
        c->right = t;

        c->height = maxHeight(height(c->left), height(c->right)) + 1;
        p->height = maxHeight(height(p->left), height(p->right)) + 1;

        return p;
    }

 
    
    Node* minvalue(Node*node){
        Node*current=node;
        while(node && node->left!=NULL){
            current=current->left;
        }
        return current;

    }
    Node*maxvalue(Node*node){
        Node*current=node;
        while(node && node->right!=NULL){
            current=current->right;
        }
        return current;
    }
    Node * search(Node*node,int key){

        if(root==NULL || root->data==key){
            return root;
        }
        else if(key<root->data){
            return search(root->left,key);
        }
        else{
            return search(root->right,key);
        }
    }
    private:
    void inorder(Node*root){
        if(root==nullptr){
            return;

        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);

    }
    void preorder(Node*root){
        if(root==nullptr){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node*root){
        if(root==nullptr){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
    public:
    void deleteNode(int data) {
        root = deleteNode(root, data);
    }
    
    Node* deleteNode(Node* root, int data) {
        if (root == NULL) {
            return NULL;
        }
    
        // Step 1: BST delete logic
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } 
        else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } 
        else {
            // Node found
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } 
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            } 
            else {
                Node* temp = minvalue(root->right); // inorder successor
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data);
            }
        }
    
        // Step 2: Update height
        root->height = maxHeight(height(root->left), height(root->right)) + 1;
    
        // Step 3: Rotate if needed
        return rotate(root);
    }


    Node* successor(Node* root, int key) {
        Node* curr = search(root, key);
        if (!curr) return nullptr;
    
        if (curr->right)
            return minvalue(curr->right);
    
        Node* succ = nullptr;
        Node* ancestor = root;
    
        while (ancestor != curr) {
            if (key < ancestor->data) {
                succ = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return succ;
    }
    




    Node* predecessor(Node* root, int key) {
        Node* curr = search(root, key);
        if (!curr) return nullptr;
    
        if (curr->left)
            return maxvalue(curr->left);
    
        Node* pred = nullptr;
        Node* ancestor = root;
    
        while (ancestor != curr) {
            if (key > ancestor->data) {
                pred = ancestor; // this could be the predecessor
                ancestor = ancestor->right;
            } else {
                ancestor = ancestor->left;
            }
        }
        return pred;
    }
    

    void mirrortree(Node*node){
        if(node==NULL){
            return;
        }
         Node*temp=node->left;
         node->left=node->right;
         node->right=temp;
         mirrortree(node->left);   // recursive function in order to change place of left subtree child

    
         mirrortree(node->right);  // recursive function in order to change place of right subtree child
    }






bool isbalanced(Node*node){
    if(node==NULL){
        return true;
    }
    int leftheight=height(node->left);
    int rightheight=height(node->right);
    if(abs(leftheight-rightheight)>1)return false;

    return isbalanced(node->left) && isbalanced(node->right);


    }



void display(){
    cout<<"inorder"<<endl;
    inorder(root);
    cout<<endl;
}


    //print 

    void printleaf(Node*node){
        if(!node){
            return;
        }
        if(!node->left &&!node->right){
            cout<<node->data<<" ";
            return;
        }
        printleaf(node->left);
        printleaf(node->right);
    }
    void printInternalNodes(Node* root) {
        if (!root) return;

        if (root->left || root->right) {
            cout << root->data << " ";
        }
    
       
        printInternalNodes(root->left);
        printInternalNodes(root->right);
    }


    int countNodes(Node*node){
        if(node==NULL){
            return 0;
        }
        else{
            return 1+countNodes(node->left)+countNodes(node->right);
        }
    }
    int getDepth(Node* root, int key, int depth = 0) {
        if (!root) return -1; // Key not found
    
        if (root->data == key)
            return depth;
    
        if (key < root->data)
            return getDepth(root->left, key, depth + 1);
        else
            return getDepth(root->right, key, depth + 1);
    }
    int sumNode(Node*node){
        if(node==NULL){
            return 0;
        }
        else{
            return node->data+ sumNode(node->left)+sumNode(node->right);
        }
    }






    
    int floor (Node* root, int key) {

        if (root == NULL) return -1;

        if (root->data == key)
            return root->data;

        if (root->data > key)
            return floor(root->left, key);

        int floorValue = floor(root->right, key);
        return (floorValue <= key) ? floorValue : root->data;
    }
    
    int ceil(Node* root, int key) {
        int ceilVal = -1;  
        while (root) {
            if (root->data == key)
                return root->data;
            else if (root->data < key)
                root = root->right;
            else {
                ceilVal = root->data;  
                root = root->left;
            }
        }
        return ceilVal;
    }

void updatevalue(Node*node,int oldvalue,int newvalue){
    if(!search(node,oldvalue)){
        cout<<"old value is not present"<<endl;
    }
    else{
        root=deleteNode(root,oldvalue);
        insert(newvalue);
        cout<<"value updated"<<endl;
        }
    
}
int getsize(Node*node){
    if(node==NULL){
        return 0;
    }
    else{
        return 1+getsize(node->left)+getsize(node->right);
    }
}

int findKthSmallest(Node* node, int k) {
    if (!node) return -1;

    int leftSize = getsize(node->left);

    if (k == leftSize + 1)
        return node->data;
    else if (k <= leftSize)
        return findKthSmallest(node->left, k);
    else
        return findKthSmallest(node->right, k - leftSize - 1);
}

int findKthLargest(Node* node, int k) {
    if (!node) return -1;

    int rightSize = getsize(node->right);

    if (k == rightSize + 1)
        return node->data;
    else if (k <= rightSize)
        return findKthLargest(node->right, k);
    else
        return findKthLargest(node->left, k - rightSize - 1);
}














};


int main() {
    Avl tree;
    int choice, value, key, oldValue, newValue, k;

    while (true) {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Display Inorder" << endl;
        cout << "5. Display Leaf Nodes" << endl;
        cout << "6. Display Internal Nodes" << endl;
        cout << "7. Check if Balanced" << endl;
        cout << "8. Count Nodes" << endl;
        cout << "9. Depth of Key" << endl;
        cout << "10. Sum of All Nodes" << endl;
        cout << "11. Floor of Key" << endl;
        cout << "12. Ceil of Key" << endl;
        cout << "13. Update Value" << endl;
        cout << "14. Kth Smallest Element" << endl;
        cout << "15. Kth Largest Element" << endl;
        cout << "16. Mirror Tree" << endl;
        cout << "17. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                tree.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                tree.deleteNode(value);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (tree.search(tree.root, key))
                    cout << "Key found!\n";
                else
                    cout << "Key not found.\n";
                break;
            case 4:
                tree.display();
                break;
            case 5:
                cout << "Leaf Nodes: ";
                tree.printleaf(tree.root);
                cout << endl;
                break;
            case 6:
                cout << "Internal Nodes: ";
                tree.printInternalNodes(tree.root);
                cout << endl;
                break;
            case 7:
                cout << (tree.isbalanced(tree.root) ? "Tree is balanced\n" : "Tree is NOT balanced\n");
                break;
            case 8:
                cout << "Total Nodes: " << tree.countNodes(tree.root) << endl;
                break;
            case 9:
                cout << "Enter key: ";
                cin >> key;
                cout << "Depth: " << tree.getDepth(tree.root, key) << endl;
                break;
            case 10:
                cout << "Sum of all nodes: " << tree.sumNode(tree.root) << endl;
                break;
            case 11:
                cout << "Enter key: ";
                cin >> key;
                cout << "Floor: " << tree.floor(tree.root, key) << endl;
                break;
            case 12:
                cout << "Enter key: ";
                cin >> key;
                cout << "Ceil: " << tree.ceil(tree.root, key) << endl;
                break;
            case 13:
                cout << "Enter old value and new value: ";
                cin >> oldValue >> newValue;
                tree.updatevalue(tree.root, oldValue, newValue);
                break;
            case 14:
                cout << "Enter k: ";
                cin >> k;
                cout << "Kth Smallest: " << tree.findKthSmallest(tree.root, k) << endl;
                break;
            case 15:
                cout << "Enter k: ";
                cin >> k;
                cout << "Kth Largest: " << tree.findKthLargest(tree.root, k) << endl;
                break;
            case 16:
                tree.mirrortree(tree.root);
                cout << "Tree mirrored successfully!\n";
                break;
            case 17:
                cout << "Exiting... Peace out!\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}