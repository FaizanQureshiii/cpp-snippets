#include<iostream>
#include<string>
using namespace std;

struct Car {
    string ServiceType;
    int carid;
    int washtime;
};

class Queuee {
public:
    Car queuee[5];
    int rear;
    int front;
    int size;
    int count;

    Queuee() {
        rear = -1;
        front = -1;
        count = 0;
        size = 5;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    void Enqueuee(Car car) {
        if (isFull()) {
            cout << "Queue is full 🛑\n";
        } else {
            rear = (rear + 1) % size;
            queuee[rear] = car;
            count++;
            cout << "✅ Car added: ID " << car.carid << ", Service: " << car.ServiceType << "\n";
        }
    }

    void dequeuee() {
        if (isEmpty()) {
            cout << "Queue is empty 🕳️\n";
        } else {
            front = (front + 1) % size;
            cout << "🚗 Car removed: ID " << queuee[front].carid << "\n";
            count--;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty 🕳️\n";
            return;
        }
        int next = (front + 1) % size;
        cout << "🧼 Next car to be washed:\n";
        cout << "Car ID: " << queuee[next].carid
             << ", Service: " << queuee[next].ServiceType
             << ", Time: " << queuee[next].washtime << " mins\n";
    }

    void displayqueuee() {
        if (isEmpty()) {
            cout << "Queue is empty 🕳️\n";
            return;
        }
        cout << "🚘 Cars in queue:\n";
        int i = (front + 1) % size;
        for (int j = 0; j < count; j++) {
            cout << "Car ID: " << queuee[i].carid
                 << ", Service: " << queuee[i].ServiceType
                 << ", Time: " << queuee[i].washtime << " mins\n";
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
int main() {
    Queuee carQueue;
    int choice;
    
    do {
        cout << "\n--- Car Wash Service ---\n";
        cout << "1. Enqueue a car\n";
        cout << "2. Dequeue a car\n";
        cout << "3. Display all cars\n";
        cout << "4. Peek next car\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Car car;
            cout << "Enter Car ID: ";
            cin >> car.carid;
            cout << "Enter Service Type (Basic/Premium): ";
            cin >> car.ServiceType;
            cout << "Enter Time required (in minutes): ";
            cin >> car.washtime;
            carQueue.Enqueuee(car);
        } 
        else if (choice == 2) {
            carQueue.dequeuee();
        } 
        else if (choice == 3) {
            carQueue.displayqueuee();
        } 
        else if (choice == 4) {
            carQueue.peek();
        } 
        else if (choice == 5) {
            cout << "Exiting Car Wash Service. Goodbye!\n";
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}