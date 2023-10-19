#include <iostream>
#include <string>
#include<stdio.h>
#include<cmath>
using namespace std;

const int MAX_SIZE = 100;

struct Stack
{
    int data[MAX_SIZE];
    int top;
};

void initStack(Stack& s) //call by reference( can change it )-->&
{
    s.top = -1;
}

bool isEmpty(Stack s) {
    return s.top == -1;
}
bool isFull(const Stack& s) {
    return s.top == MAX_SIZE - 1;
}
void push(Stack& s, int item) {
    if (isFull(s)) {
        cout << "stack is full and there is no space to push new item " << endl;
    }
    else
    {
        s.data[(++s.top)] = item;
        cout << "'" << item << "'" << " pushed on top of stack" << endl;
    }
}
int pop(Stack&s) {
    
    
    if (isEmpty(s)) {
        cout << " stack is empty and there is nothing to pops up!" << endl;
        return -1;//Return an error
    }
    else
    {
        int item = s.data[(s.top--)];
        return item;
    }
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int doOperation(char op, int op1, int op2) {
    if (op == '+') {
        return op1 + op2;
    }
    else if (op == '-') {
        return op1 - op2;
    }
    else if (op == '*') {
        return op1 * op2;
    }
    else if (op == '/') {
        return op1 / op2;
    }
    else {
        return 0;
    }
}
int evaluate(string& expr) {
    Stack operands;
    initStack(operands);

    for (char ch : expr) {

        if (isdigit(ch)) { // when find an operand (a digit)

             push(operands, ch - '0'); // push it onto the stack
        }

        else if (isOperator(ch)) {
            if (isEmpty(operands)) {
                cout << "Error" << endl;
            }

            int op2 = pop(operands);

            if (isEmpty(operands)) {
                cout << "error" << endl;
            }
            int op1 = pop(operands);
            int result = doOperation(ch, op1, op2);
            push(operands, result);
        }
        else if (ch != ' ') {
            cout << "error" << endl;
        }
    }

    return pop(operands);
}
 


int main() {
    string expr;
    Stack s;
    cout << "Enter a postfix expression:" << endl;
    getline(cin, expr);
    int result =evaluate(expr);
    cout << "Result = " << result << endl;
    return 0;
}


