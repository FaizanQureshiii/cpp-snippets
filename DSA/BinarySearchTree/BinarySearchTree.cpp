#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

class bst {
public:
    Node* root;

    bst() {
        root = nullptr;
    }


    Node* insert(Node* root, int val) {

        if (root == nullptr) {
        
            return new Node(val);
        
        }
        if (val < root->value) {

            root->left = insert(root->left, val);

        } 
        else {
            root->right = insert(root->right, val);
        }
        return root;
    }



    void insert(int val) {

        root = insert(root, val);
    }





    bool search(int val, Node* node) {

        if (node == nullptr){

         return false;
        }
        if (val == node->value) {

            return true;
        }
        else if (val < node->value) {

            return search(val, node->left);}

        else {
            return search(val, node->right);
        }
    }

    bool search(int val) {

        return search(val, root);
    }




    Node* deleteNode(Node* root, int val) {

        if (val < root->value) {

            root->left = deleteNode(root->left, val);

        }
         else if (val > root->value) {
            root->right = deleteNode(root->right, val);
        }
         else {
            if (!root->left) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
             else if (!root->right) {
                Node* temp = root->left;
                delete root;
                return temp;
            
            }
        }
        return root;
    }

    void deleteNode(int val) {
        root = deleteNode(root, val);
    }



    int findmin(Node* node) {

        while (node->left != nullptr) {

            node = node->left;
        }
        return node->value;
    }

    void findmin() {
        cout << "Minimum value: " << findmin(root) << endl;
    }




    int findmax(Node* node) {

        while (node->right != nullptr) {
            node = node->right;
        }
        return node->value;
    }

    void findmax() {
        cout << "Maximum value: " << findmax(root) << endl;
    }




    int countnode(Node* node) {
        
        return 1 + countnode(node->left) + countnode(node->right);
    }

    void countnode() {
        cout << "Total nodes: " << countnode(root) << endl;
    }

    


    void mirror(Node* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    void mirror() {
        mirror(root);
        cout << "Mirror Inorder: ";
        inorder(root);
        cout << endl;
    }



    int kthsmallest(Node* node, int& k, int& count) {
        if (node == nullptr) {
            return -1;
        }

        int left = kthsmallest(node->left, k, count);

        if (left != -1) return left;

        count++;
        
        if (count == k) {
            return node->value;
        }
        return kthsmallest(node->right, k, count);
    }

    void kthsmallest(int k) {
        int count = 0;
        cout << "k-th smallest: " <<  kthsmallest(root, k, count)<< endl;
    }

    


    int kthlargest(Node* node, int& k, int& count) {

        if (node == nullptr) {
            return -1;
        }
        int right = kthlargest(node->right, k, count);

        if (right != -1) {
            return right;
        }
        count++;
        if (count == k) {
            return node->value;
        }
        return kthlargest(node->left, k, count);
    }

    void kthlargest(int k) {
        int count = 0;
        cout << "k-th largest: " <<  kthlargest(root, k, count)<< endl;
    }


  


    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void inorder() {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }




    int sumofallnodes(Node* node, int& sum) {

        sum =sum + node->value;
        return sumofallnodes(node->left, sum) + sumofallnodes(node->right, sum) + node->value;
    }

    void Sumofallnodes() {
        int sum = 0;
        cout << "Sum of all nodes: " << sumofallnodes(root, sum) << endl;
    }





    void sumofevenodd(Node* node, int& sumeven, int& sumodd, int& counteven, int& countodd) {

        if (node == nullptr) return;

        if (node->value % 2 == 0) {

            sumeven =sumeven+ node->value;
            counteven++;

        }
         else {
            sumodd = sumodd + node->value;
            countodd++;
        }

        sumofevenodd(node->left, sumeven, sumodd, counteven, countodd);
        sumofevenodd(node->right, sumeven, sumodd, counteven, countodd);
    }


    void sumofevenodd() {
        int sumeven = 0;
        int sumodd = 0;
        int  counteven = 0;
        int countodd = 0;
        sumofevenodd(root, sumeven, sumodd, counteven, countodd);
        cout << "Sum of even nodes: " << sumeven << endl;
        cout << "Count of even nodes: " << counteven << endl;
        cout << "Sum of odd nodes: " << sumodd << endl;
        cout << "Count of odd nodes: " << countodd << endl;
    }







    bool isBSTInorder(Node* node, Node*& prev) {
        if (node == nullptr) return true;
        if (!isBSTInorder(node->left, prev)) return false;
        if (prev != nullptr && node->value <= prev->value) return false;
        prev = node;
        return isBSTInorder(node->right, prev);
    }

    bool isBST() {
        Node* prev = nullptr;
        return isBSTInorder(root, prev);
    }

 



    int height(Node* node) {

        if (node == nullptr) {
            return 0;
        }
        int left = height(node->left);
        int right = height(node->right);
        return max(left, right) + 1;
    }

    void height() {
        cout << "Height of tree: " << height(root) << endl;
    }



   


    void average(Node* node, int& sum, int& count) {
        if (node == nullptr) {
            return;
        }

        sum += node->value;
        count++;

        average(node->left, sum, count);
        average(node->right, sum, count);
    }

    void average() {
        int sum = 0;
        int count = 0;
        average(root, sum, count); 
            cout << "Average of tree: " <<sum/count << endl;
    }




    

    bool printPathToNode(Node* node, int val) {
        if (node == nullptr) return false;
    
        if (node->value == val) {
            cout << node->value << " ";
            return true;
        }
    
        if (val < node->value && printPathToNode(node->left, val)) {
            cout << node->value << " ";
            return true;
        }
        if (val > node->value && printPathToNode(node->right, val)) {
            cout << node->value << " ";
            return true;
        }
    
        return false;
    }
    
    void printpath(int val) {
        cout << "Path to " << val << ": ";
        if (!printPathToNode(root, val)) {
            cout << "Node not found";
        }
        cout << endl;
    }
    

 



    void printLeaves(Node* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->value << " ";
            return;
        }
        printLeaves(node->left);
        printLeaves(node->right);
    }

    void printLeaves() {
        cout << "Leaf nodes: ";
        printLeaves(root);
        cout << endl;
    }





int floor(Node* node, int val) {
    int result = -1;
    while (node) {
        if (node->value == val) return node->value;
        if (node->value > val) {
            node = node->left;
        } else {
            result = node->value;
            node = node->right;
        }
    }
    return result;
}



void floor(int val) {
    int res = floor(root, val);
    if (res == -1) cout << "No floor found for " << val << endl;
    else cout << "Floor of " << val << ": " << res << endl;
}




int ceil(Node* node, int val) {
    int result = -1;

    while (node) {
        if (node->value == val) return node->value;

        if (node->value < val) {
            node = node->right;
        }
         else {
            result = node->value;
            node = node->left;
        }
    }
    return result;
}

void ceil(int val) {
    int res = ceil(root, val);
    if (res == -1) cout << "No ceil found for " << val << endl;
    else cout << "Ceil of " << val << ": " << res << endl;
}





void updateValue(int oldVal, int newVal) {

    if (!search(oldVal)) {
        cout << "Value " << oldVal << " not found to update." << endl;
        return;
    }

    deleteNode(oldVal);
    
    insert(newVal);
    cout << "Updated " << oldVal << " to " << newVal << "." << endl;
}

};
