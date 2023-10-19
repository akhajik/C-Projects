/*Sarena Lao
CS 136 L5 Class and Pointers
October 5, 2023*/

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Queue{
private: 
    struct Node{
        T data;
        Node* next;
    };
    Node* topNode;
    Node* backNode;
public:
    Queue() : topNode(nullptr) { }
    ~Queue() {
        while(!isEmpty()){
            dequeue();
        }
    }
    void enqueue(const T& value){
        if(isEmpty()){
            Node* newNode = new Node;
            newNode->data = value;
            topNode = newNode;
            backNode = newNode;
        } else {
            Node* newNode = new Node;
            newNode->data = value;
            backNode->next = newNode;
            backNode = newNode;
        }
    }
    void dequeue(){
        if(isEmpty()){
            throw underflow_error("Queue is empty.");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    T& front(){
        if(isEmpty()){
            throw underflow_error("Queue is empty\n");
        }
        return topNode->data;
    }
    const T& front() const{
        if(isEmpty()){
            throw underflow_error("Queue is empty\n");
        }
        return topNode->data;
    }
    bool isEmpty() const{
        return topNode == nullptr;
    }
};


int main(){

    Queue<string> queue;
    //enqueue 3 times
    queue.enqueue("Sarena");
    queue.enqueue("Rajvir");
    queue.enqueue("Arshen");
    //Sarena, Rajvir, Arshen
    cout << "Top element: " << queue.front() << endl;
    //dequeue
    queue.dequeue();
    //Rajvir, Arshen
    cout << "Top element: " << queue.front() << endl;
    queue.front() = "Professor Shahpar";
    //Professor Shahpar, Arshen
    cout << "Top element: " << queue.front() << endl;
    queue.dequeue();
    //Arshen
    cout << "Top element: " << queue.front() << endl;
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No");
    queue.dequeue();
    //empty
    cout << "\nIs the queue empty? " << (queue.isEmpty() ? "Yes" : "No");

    return 0;
}