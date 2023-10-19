#include <iostream>
using namespace std;

struct Car {
    string brand;
    int year;
    double range;
};

const int MAX_SIZE = 10;
Car queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(Car s) {
    if (rear == MAX_SIZE - 1) {
        cout << "Queue is full" << endl;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = s;
    }
}

Car dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
        Car s;
        s.brand = " ";
        s.year = 0;
        s.range = 0.0;
        return s;
    }
    else {
        Car temp = queue[front];
        front++;
        return temp;
    }
}

void display() {
    if (front == -1) {
        cout << "Queue is empty" << endl;
    }
    else {
        for (int i = front; i <= rear; i++) {
            cout << "brand: " << queue[i].brand << endl;
            cout << "Year: " << queue[i].year << endl;
            cout << "range: " << queue[i].range << endl;
            cout << endl;
        }
    }
}

bool inQueue(Car& s) {
    for (int i = front; i <= rear; i++) {
        if (queue[i].brand == s.brand && queue[i].year == s.year && queue[i].range == s.range) {
            return true;
        }
    }
    return false;
}

int main() {
    int choice;
    Car s;
    do {
        cout << "Queue Menu" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Display" << endl;
        cout << "4.Check if element is in queue" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: \n\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter car's brand: ";
            cin >> s.brand;
            cout << "Enter  car's year: ";
            cin >> s.year;
            cout << "Enter car's range: ";
            cin >> s.range;
            enqueue(s);
            break;
        case 2:
            s = dequeue();
            cout << "Dequeued car: " << s.brand << endl;
            cout << endl;
            break;
        case 3:
            display();
            cout << endl;
            break;
        case 4:
            cout << "\nEnter car's brand: ";
            cin >> s.brand;
            cout << "Enter car's  year: ";
            cin >> s.year;
            cout << "Enter car's range: ";
            cin >> s.range;
            if (inQueue(s)) {
                cout << "\n[EXIST] Element is in queue" << endl;
            }
            else {
                cout << "\n[NOT EXIST] Element is not in queue" << endl;
            }
            cout << endl;
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 5);
    return 0;
}
