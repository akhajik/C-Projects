#include <iostream>
using namespace std;

//---------------N O D E-----------------

template <typename T>
class Node {
public:
    T data;
    Node* next;


    Node(T val) : data(val), next(nullptr) {}
    T getData() const { return data; }
    void setData(T val) { data = val; }
    Node* getNext() const { return next; }
    void setNext(Node* node) { next = node; }
};

//--------------- L I N K E D   L I S T -----------------

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() :head(nullptr) {}

    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current->setNext(newNode);
        }
    }

    void deletByValue(T val) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current != nullptr && current->getData() != val) {
            prev = current;
            current = current->getNext();
        }

        if (current != nullptr) {
            if (prev == nullptr) {
                head = current->getNext();
            }
            else {
                prev->setNext(current->getNext());
            }
            delete current;
        }
    }

    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }

    bool search(T val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == val) {
                return true;
            }
            current = current->getNext();
        }
        return false;
    }

    void splitListIntoHalves(LinkedList<T>& firstHalf, LinkedList<T>& secondHalf) {
        Node<T>* current = head;
        Node<T>* temp = head;

        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        // Traverse the list to find the middle using current and temp pointers
        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next->next;
            current = current->next;
        }

        // Split the list into two halves
        firstHalf.head = head;
        secondHalf.head = current->next;
        current->next = nullptr;
    }

    void removeDuplicates() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node<T>* current = head;
        Node<T>* check;
        Node<T>* temp;

        while (current != nullptr && current->next != nullptr) {
            check = current;
            while (check->next != nullptr) {
                if (current->data == check->next->data) {
                    temp = check->next;
                    check->next = check->next->next;

                    cout << "Removed duplicate: " << temp->data << endl;

                    delete temp;
                }
                else {
                    check = check->next;
                }
            }
            current = current->next;
        }
    }

    void mergeSortedLists(LinkedList<T>& list1, LinkedList<T>& list2) {
        Node<T>* merged = nullptr;
        Node<T>* temp = nullptr;

        Node<T>* current1 = list1.head;
        Node<T>* current2 = list2.head;

        while (current1 != nullptr && current2 != nullptr) {
            Node<T>* newNode = nullptr;
            if (current1->getData() <= current2->getData()) {
                newNode = new Node<T>(current1->getData());
                current1 = current1->getNext();
            }
            else {
                newNode = new Node<T>(current2->getData());
                current2 = current2->getNext();
            }

            if (merged == nullptr) {
                merged = newNode;
                temp = merged;
            }
            else {
                temp->setNext(newNode);
                temp = newNode;
            }
        }

        while (current1 != nullptr) {
            Node<T>* newNode = new Node<T>(current1->getData());
            temp->setNext(newNode);
            temp = newNode;
            current1 = current1->getNext();
        }

        while (current2 != nullptr) {
            Node<T>* newNode = new Node<T>(current2->getData());
            temp->setNext(newNode);
            temp = newNode;
            current2 = current2->getNext();
        }

        head = merged;
    }
};

int main() {
    LinkedList<int> list;
    list.insertAtStart(20);
    list.insertAtEnd(30);
    list.insertAtStart(10);
    list.insertAtEnd(40);

    cout << "LinkedList: ";
    list.print();

    int d = 30;
    list.deletByValue(d);
    cout << "Deleted [" << d << "]" << endl;
    list.print();

    int s = 10;
    if (list.search(s)) {
        cout << s << " is in the list." << endl;
    }
    else {
        cout << s << " is NOT in the list." << endl;
    }

    LinkedList<string> list2;
    list2.insertAtStart("\nBegin");
    list2.insertAtEnd("\nEnd");
    list2.insertAtStart("\n\ntesting linked list ");

    cout << "LinkedList 2: ";
    list2.print();

    LinkedList<int> firstHalf;
    LinkedList<int> secondHalf;
    list.splitListIntoHalves(firstHalf, secondHalf);
    cout << "First half: ";
    firstHalf.print();
    cout << "Second half: ";
    secondHalf.print();

    list.insertAtEnd(30);
    list.insertAtEnd(20);
    list.insertAtEnd(10);
    list.print();
    list.removeDuplicates();
    list.print();

    LinkedList<int> list1;
    LinkedList<int> list3;
    list1.insertAtEnd(2);
    list1.insertAtEnd(4);
    list1.insertAtEnd(6);
    list1.insertAtEnd(8);
    list3.insertAtEnd(1);
    list3.insertAtEnd(3);
    list3.insertAtEnd(5);
    list3.insertAtEnd(7);

    cout << "Merged Lists: ";
    list1.mergeSortedLists(list3, list);
    list.print();

    return 0;
}