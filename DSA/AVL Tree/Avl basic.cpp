#include<iostream>
using namespace std;

class Node {
public:
    int value;
    int height;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVL {
public:
    Node* root;

    AVL() {
        root = nullptr;
    }

    int height(Node* node) {
        if (node == nullptr)
            return 0;
        else
            return node->height;
    }
    

    int getBalance(Node* node) {
        if (node == nullptr)
            return 0;
    
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
    
        return leftHeight - rightHeight;
    }
    

    int maxHeight(int a, int b) {
        if (a > b)
            return a;
        else
            return b;
    }
    

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = maxHeight(height(y->left), height(y->right)) + 1;
        x->height = maxHeight(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = maxHeight(height(x->left), height(x->right)) + 1;
        y->height = maxHeight(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* rotate(Node* node) {
        int balance = height(node->left) - height(node->right);
        if (balance > 1) {
            if (height(node->left->left) >= height(node->left->right))
                return rotateRight(node);
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }
        if (balance < -1) {
            if (height(node->right->right) >= height(node->right->left))
                return rotateLeft(node);
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }
        return node;
    }

    Node* insert(Node* node, int val) {
        if (node==NULL){

        return new Node(val);
        }
        if (val < node->value){
            node->left = insert(node->left, val);
        
            }
                else{
            node->right = insert(node->right, val);
                }
        node->height = 1 + maxHeight(height(node->left), height(node->right));
        return rotate(node);
    
}

    void insert(int val) {
        root = insert(root, val);
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void inorder() {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->value == val) return true;
        if (val < node->value) return search(node->left, val);
        return search(node->right, val);
    }

    bool search(int val) {
        return search(root, val);
    }

    int findmin(Node* node) {
        while (node && node->left) node = node->left;
        return node->value;
    }

    void findmin() {
        cout << "Minimum: " << findmin(root) << endl;
    }

    int findmax(Node* node) {
        while (node && node->right) node = node->right;
        return node->value;
    }

    void findmax() {
        cout << "Maximum: " << findmax(root) << endl;
    }

    int count(Node* node) {
        if (!node) return 0;
        return 1 + count(node->left) + count(node->right);
    }

    void count() {
        cout << "Node count: " << count(root) << endl;
    }

    int treeHeight() {
        return height(root);
    }

    bool printPath(Node* node, int val) {
        if (!node) return false;
        if (node->value == val) {
            cout << node->value << " ";
            return true;
        }
        if ((val < node->value && printPath(node->left, val)) ||
            (val > node->value && printPath(node->right, val))) {
            cout << node->value << " ";
            return true;
        }
        return false;
    }

    void printPath(int val) {
        cout << "Path to " << val << ": ";
        if (!printPath(root, val)) cout << "Not found";
        cout << endl;
    }

    void printLeaves(Node* node) {
        if (!node) return;
        if (!node->left && !node->right) {
            cout << node->value << " ";
            return;
        }
        printLeaves(node->left);
        printLeaves(node->right);
    }

    void printLeaves() {
        cout << "Leaves: ";
        printLeaves(root);
        cout << endl;
    }

    int kthSmallest(Node* node, int& k, int& count) {
        if (!node) return -1;
        int left = kthSmallest(node->left, k, count);
        if (left != -1) return left;
        count++;
        if (count == k) return node->value;
        return kthSmallest(node->right, k, count);
    }

    void kthSmallest(int k) {
        int count = 0;
        int res = kthSmallest(root, k, count);
        if (res == -1)
            cout << "k-th smallest not found\n";
        else
            cout << "k-th smallest: " << res << endl;
    }

    int kthLargest(Node* node, int& k, int& count) {
        if (!node) return -1;
        int right = kthLargest(node->right, k, count);
        if (right != -1) return right;
        count++;
        if (count == k) return node->value;
        return kthLargest(node->left, k, count);
    }

    void kthLargest(int k) {
        int count = 0;
        int res = kthLargest(root, k, count);
        if (res == -1)
            cout << "k-th largest not found\n";
        else
            cout << "k-th largest: " << res << endl;
    }

    void mirror(Node* node) {
        if (!node) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    void mirror() {
        mirror(root);
        cout << "Mirror image created.\n";
        inorder();
    }

    int sumOfAll(Node* node,int &sum) {
        if (!node) return 0;
        sum=sum+node->value;
        sumOfAll(node->left,sum);
        sumOfAll(node->right,sum);
        return sum;
    }
void sumOfAll(){
    int sum=0;
    sumOfAll(root,sum);
    cout<<"Sum of all nodes: "<<sum<<endl;
}; // <--- Don’t forget the semicolon here!
};
int main() {
    AVL tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.inorder();
    tree.findmin();
    tree.findmax();
    tree.count();
    tree.sumOfAll();
    cout << "Height: " << tree.treeHeight() << endl;
    tree.printPath(60);
    tree.printLeaves();
    tree.kthSmallest(3);
    tree.kthLargest(2);
    tree.mirror();

    return 0;
}
