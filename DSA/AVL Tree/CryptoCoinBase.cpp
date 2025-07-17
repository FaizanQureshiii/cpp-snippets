#include <iostream>
#include <string>
using namespace std;

class CoinNode {
public:
    string name;
    float price;
    float quantity;
    int height;
    CoinNode* left;
    CoinNode* right;

    CoinNode(string name, float price, float quantity)
        : name(name), price(price), quantity(quantity), height(1), left(nullptr), right(nullptr) {}
};

class PortfolioAVL {
private:
    CoinNode* root;

    // 11. height()
    int height(CoinNode* node) {
        return node ? node->height : 0;
    }

    // 13. getBalance()
    int getBalance(CoinNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // 12. rightRotate()
    CoinNode* rightRotate(CoinNode* y) {
        CoinNode* x = y->left;
        CoinNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));
        return x;
    }

    // 11. leftRotate()
    CoinNode* leftRotate(CoinNode* x) {
        CoinNode* y = x->right;
        CoinNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    // Insert Helper
    CoinNode* insert(CoinNode* node, string name, float price, float quantity) {
        if (!node) return new CoinNode(name, price, quantity);

        if (name < node->name)
            node->left = insert(node->left, name, price, quantity);
        else if (name > node->name)
            node->right = insert(node->right, name, price, quantity);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && name < node->left->name) return rightRotate(node);
        if (balance < -1 && name > node->right->name) return leftRotate(node);
        if (balance > 1 && name > node->left->name) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && name < node->right->name) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    // 15. minValueNode()
    CoinNode* minValueNode(CoinNode* node) {
        CoinNode* current = node;
        while (current->left != nullptr) current = current->left;
        return current;
    }

    // Delete Helper
    CoinNode* deleteNode(CoinNode* root, string name) {
        if (!root) return root;

        if (name < root->name)
            root->left = deleteNode(root->left, name);
        else if (name > root->name)
            root->right = deleteNode(root->right, name);
        else {
            if (!root->left || !root->right) {
                CoinNode* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                } else *root = *temp;
                delete temp;
            } else {
                CoinNode* temp = minValueNode(root->right);
                root->name = temp->name;
                root->price = temp->price;
                root->quantity = temp->quantity;
                root->right = deleteNode(root->right, temp->name);
            }
        }

        if (!root) return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    CoinNode* search(CoinNode* node, string name) {
        if (!node || node->name == name) return node;
        return (name < node->name) ? search(node->left, name) : search(node->right, name);
    }

    void inOrder(CoinNode* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->name << " | Price: $" << node->price
             << " | Qty: " << node->quantity
             << " | Value: $" << (node->price * node->quantity) << endl;
        inOrder(node->right);
    }

    float getTotalValue(CoinNode* node) {
        if (!node) return 0;
        return node->price * node->quantity + getTotalValue(node->left) + getTotalValue(node->right);
    }

    int countCoins(CoinNode* node) {
        if (!node) return 0;
        return 1 + countCoins(node->left) + countCoins(node->right);
    }

    void findMaxMin(CoinNode* node, CoinNode*& maxNode, CoinNode*& minNode) {
        if (!node) return;
        findMaxMin(node->left, maxNode, minNode);
        float val = node->price * node->quantity;
        if (!maxNode || val > maxNode->price * maxNode->quantity) maxNode = node;
        if (!minNode || val < minNode->price * minNode->quantity) minNode = node;
        findMaxMin(node->right, maxNode, minNode);
    }

public:
    PortfolioAVL() : root(nullptr) {}

    // 1. insertCoin()
    void insertCoin(string name, float price, float quantity) {
        root = insert(root, name, price, quantity);
    }

    // 2. deleteCoin()
    void deleteCoin(string name) {
        root = deleteNode(root, name);
    }

    // 3. searchCoin()
    void searchCoin(string name) {
        CoinNode* node = search(root, name);
        if (node)
            cout << node->name << " found! Price: $" << node->price << ", Quantity: " << node->quantity << endl;
        else
            cout << name << " not found in portfolio.\n";
    }

    // 4. displayPortfolio()
    void displayPortfolio() {
        cout << "\n📊 Portfolio Overview:\n";
        inOrder(root);
    }

    // 5. getPortfolioValue()
    void getPortfolioValue() {
        cout << "💰 Total Value: $" << getTotalValue(root) << endl;
    }

    // 6. countTotalCoins()
    void countTotalCoins() {
        cout << "🪙 Total Coins: " << countCoins(root) << endl;
    }

    // 7. updateCoinPrice()
    void updateCoinPrice(string name, float newPrice) {
        CoinNode* node = search(root, name);
        if (node) node->price = newPrice;
    }

    // 8. updateCoinQuantity()
    void updateCoinQuantity(string name, float newQty) {
        CoinNode* node = search(root, name);
        if (node) node->quantity = newQty;
    }

    // 9. showMaxValueCoin()
    void showMaxValueCoin() {
        CoinNode* maxNode = nullptr, * minNode = nullptr;
        findMaxMin(root, maxNode, minNode);
        if (maxNode) cout << "🚀 Highest Value Coin: " << maxNode->name << " ($" << (maxNode->price * maxNode->quantity) << ")\n";
    }

    // 10. showMinValueCoin()
    void showMinValueCoin() {
        CoinNode* maxNode = nullptr, * minNode = nullptr;
        findMaxMin(root, maxNode, minNode);
        if (minNode) cout << "📉 Lowest Value Coin: " << minNode->name << " ($" << (minNode->price * minNode->quantity) << ")\n";
    }
};

int main() {
    PortfolioAVL pf;

    pf.insertCoin("Bitcoin", 70000, 0.5);
    pf.insertCoin("Ethereum", 4000, 2);
    pf.insertCoin("Solana", 150, 10);
    pf.insertCoin("Dogecoin", 0.1, 5000);
    pf.insertCoin("Cardano", 0.5, 1000);

    pf.displayPortfolio();
    pf.getPortfolioValue();
    pf.countTotalCoins();
    pf.searchCoin("Ethereum");
    pf.updateCoinPrice("Ethereum", 4500);
    pf.updateCoinQuantity("Bitcoin", 0.6);
    pf.showMaxValueCoin();
    pf.showMinValueCoin();
    pf.deleteCoin("Solana");
    pf.displayPortfolio();

    return 0;
}