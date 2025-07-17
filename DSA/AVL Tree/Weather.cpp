#include <iostream>
#include <string>
using namespace std;

class WeatherNode {
public:
    string city;
    float temperature;
    float humidity;
    float windSpeed;
    int height;
    WeatherNode* left;
    WeatherNode* right;

    WeatherNode(string c, float t, float h, float w) {
        city = c;
        temperature = t;
        humidity = h;
        windSpeed = w;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

class WeatherAVL {
private:
    WeatherNode* root;

    int height(WeatherNode* node) {
        if (node == NULL) return 0;
        return node->height;
    }

    int getBalance(WeatherNode* node) {
        if (node == NULL) return 0;
        return height(node->left) - height(node->right);
    }

    WeatherNode* rightRotate(WeatherNode* y) {
        WeatherNode* x = y->left;
        WeatherNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    WeatherNode* leftRotate(WeatherNode* x) {
        WeatherNode* y = x->right;
        WeatherNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    WeatherNode* insert(WeatherNode* node, string city, float temp, float hum, float wind) {
        if (node == NULL) return new WeatherNode(city, temp, hum, wind);

        if (city < node->city)
            node->left = insert(node->left, city, temp, hum, wind);
        else if (city > node->city)
            node->right = insert(node->right, city, temp, hum, wind);
        else
            return node;

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && city < node->left->city) return rightRotate(node);
        if (balance < -1 && city > node->right->city) return leftRotate(node);
        if (balance > 1 && city > node->left->city) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && city < node->right->city) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    WeatherNode* minValueNode(WeatherNode* node) {
        WeatherNode* current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    WeatherNode* deleteNode(WeatherNode* root, string city) {
        if (root == NULL) return root;

        if (city < root->city)
            root->left = deleteNode(root->left, city);
        else if (city > root->city)
            root->right = deleteNode(root->right, city);
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            else if (root->left == NULL) {
                WeatherNode* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL) {
                WeatherNode* temp = root->left;
                delete root;
                return temp;
            }
            WeatherNode* temp = minValueNode(root->right);
            root->city = temp->city;
            root->temperature = temp->temperature;
            root->humidity = temp->humidity;
            root->windSpeed = temp->windSpeed;
            root->right = deleteNode(root->right, temp->city);
        }

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    void inOrder(WeatherNode* node) {
        if (node == NULL) return;
        inOrder(node->left);
        cout << node->city << " | Temp: " << node->temperature << "°C | Humidity: " << node->humidity << "% | Wind: " << node->windSpeed << "km/h\n";
        inOrder(node->right);
    }

    WeatherNode* search(WeatherNode* node, string city) {
        if (node == NULL || node->city == city)
            return node;
        if (city < node->city)
            return search(node->left, city);
        else
            return search(node->right, city);
    }

    void maxMinTemp(WeatherNode* node, WeatherNode*& maxNode, WeatherNode*& minNode) {
        if (node == NULL) return;
        maxMinTemp(node->left, maxNode, minNode);
        if (maxNode == NULL || node->temperature > maxNode->temperature) maxNode = node;
        if (minNode == NULL || node->temperature < minNode->temperature) minNode = node;
        maxMinTemp(node->right, maxNode, minNode);
    }

    int countNodes(WeatherNode* node) {
        if (node == NULL) return 0;
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    float totalTemperature(WeatherNode* node) {
        if (node == NULL) return 0;
        return node->temperature + totalTemperature(node->left) + totalTemperature(node->right);
    }

    // ✅ NEW: Cities in temp range
    void citiesInTempRange(WeatherNode* node, float min, float max) {
        if (!node) return;
        citiesInTempRange(node->left, min, max);
        if (node->temperature >= min && node->temperature <= max)
            cout << node->city << " (" << node->temperature << "°C)\n";
        citiesInTempRange(node->right, min, max);
    }

    // ✅ NEW: Print leaf cities
    void printLeafCities(WeatherNode* node) {
        if (!node) return;
        if (!node->left && !node->right)
            cout << node->city << " ";
        printLeafCities(node->left);
        printLeafCities(node->right);
    }

    // ✅ NEW: Print kth hottest
    void printKthHottest(WeatherNode* node, int& k, string& result) {
        if (!node || k <= 0) return;
        printKthHottest(node->right, k, result);
        k--;
        if (k == 0) {
            result = node->city + " (" + to_string(node->temperature) + "°C)";
            return;
        }
        printKthHottest(node->left, k, result);
    }

public:
    WeatherAVL() {
        root = NULL;
    }

    void insertWeatherData(string city, float temp, float hum, float wind) {
        root = insert(root, city, temp, hum, wind);
    }

    void deleteCity(string city) {
        root = deleteNode(root, city);
    }

    void searchCity(string city) {
        WeatherNode* result = search(root, city);
        if (result != NULL)
            cout << city << " Found: Temp=" << result->temperature << "°C, Hum=" << result->humidity << "%, Wind=" << result->windSpeed << "km/h\n";
        else
            cout << city << " not found in database.\n";
    }

    void displayWeatherReport() {
        cout << "\n🌍 Weather Report:\n------------------\n";
        inOrder(root);
    }

    void updateTemperature(string city, float newTemp) {
        WeatherNode* node = search(root, city);
        if (node != NULL) node->temperature = newTemp;
    }

    void updateHumidity(string city, float newHumidity) {
        WeatherNode* node = search(root, city);
        if (node != NULL) node->humidity = newHumidity;
    }

    void updateWindSpeed(string city, float newWindSpeed) {
        WeatherNode* node = search(root, city);
        if (node != NULL) node->windSpeed = newWindSpeed;
    }

    void getCityWithMaxTemp() {
        WeatherNode* maxNode = NULL, * minNode = NULL;
        maxMinTemp(root, maxNode, minNode);
        if (maxNode != NULL)
            cout << "🔥 Hottest City: " << maxNode->city << " (" << maxNode->temperature << "°C)\n";
    }

    void getCityWithMinTemp() {
        WeatherNode* maxNode = NULL, * minNode = NULL;
        maxMinTemp(root, maxNode, minNode);
        if (minNode != NULL)
            cout << "❄ Coldest City: " << minNode->city << " (" << minNode->temperature << "°C)\n";
    }

    void countCities() {
        cout << "🏙 Total Cities: " << countNodes(root) << endl;
    }

    void averageTemperature() {
        int totalCities = countNodes(root);
        float sumTemp = totalTemperature(root);
        if (totalCities > 0)
            cout << "🌡 Average Temperature: " << (sumTemp / totalCities) << "°C\n";
    }

    // 🆕 New Public Functions

    void compareCities(string c1, string c2) {
        WeatherNode* n1 = search(root, c1);
        WeatherNode* n2 = search(root, c2);
        if (!n1 || !n2) cout << "One or both cities not found.\n";
        else {
            cout << "\n🔍 Comparing " << c1 << " vs " << c2 << ":\n";
            cout << "Temp: " << n1->temperature << " vs " << n2->temperature << "\n";
            cout << "Humidity: " << n1->humidity << " vs " << n2->humidity << "\n";
            cout << "Wind: " << n1->windSpeed << " vs " << n2->windSpeed << "\n";
        }
    }

    void showCitiesInTempRange(float min, float max) {
        cout << "\n🌡 Cities between " << min << "°C and " << max << "°C:\n";
        citiesInTempRange(root, min, max);
    }

    void showLeafCities() {
        cout << "\n🍃 Leaf Cities: ";
        printLeafCities(root);
        cout << endl;
    }

    void showKthHottest(int k) {
        string result = "Not enough cities.";
        printKthHottest(root, k, result);
        cout << "🔥 " << k << "th Hottest City: " << result << endl;
    }
};

// 🌈 MAIN FUNCTION 🌈
int main() {
    WeatherAVL system;

    system.insertWeatherData("Lahore", 42.0, 18.5, 13);
    system.insertWeatherData("Karachi", 35.6, 60.0, 20);
    system.insertWeatherData("Islamabad", 30.0, 40.0, 10);
    system.insertWeatherData("Peshawar", 38.5, 35.0, 8);
    system.insertWeatherData("Quetta", 28.0, 25.0, 15);

    system.displayWeatherReport();
    system.searchCity("Lahore");
    system.updateTemperature("Lahore", 44.2);
    system.updateHumidity("Karachi", 65.5);
    system.updateWindSpeed("Islamabad", 12);

    system.getCityWithMaxTemp();
    system.getCityWithMinTemp();
    system.countCities();
    system.averageTemperature();

    system.compareCities("Lahore", "Karachi");
    system.showCitiesInTempRange(30, 40);
    system.showLeafCities();
    system.showKthHottest(2);

    system.deleteCity("Quetta");
    system.displayWeatherReport();

    return 0;
}
