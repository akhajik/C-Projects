#include <iostream>
       using namespace std;

   template <class T>
   class Queue {
   private:
       struct Node {
           T data;
           Node* next;
       };

       Node* front;

   public:
       Queue() {
           front = nullptr;
       }

       ~Queue() {
           Node* temp;

           while (front != nullptr) {
               temp = front;
               front = front->next;
               delete temp;
           }
       }

       void push(T element) {
           Node* newNode = new Node;
           newNode->data = element;
           newNode->next = nullptr;
           if (front == nullptr) {
               front = newNode;
           }
           else {
               Node* temp = front;
               while (temp->next != nullptr) {
                   temp = temp->next;
               }
               temp->next = newNode;
           }
       }

       T pop() {
           if (front == nullptr) {
               cerr << "Queue is empty." << endl;
               exit(1);
           }
           else {
               Node* temp = front;
               T value = temp->data;
               front = front->next;
               delete temp;
               return value;
           }
       }

       T peek() {
           if (front == nullptr) {
               cerr << "Queue is empty." << endl;
               exit(1);
           }
           else {
               return front->data;
           }
       }
   };
   int main() {
       Queue<int> q;
       q.push(1);
       q.push(2);
       q.push(3);
       cout << q.pop() << endl; // prints 1
       cout << q.peek() << endl; // prints 2

       Queue<char> q1;
       q1.push('a');
       q1.push('b');
       q1.push('c');
       cout << q1.pop() << endl; // prints a
       cout << q1.peek() << endl; // prints b

       return 0;
   }