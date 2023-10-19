#include <iostream>
#include <stack>
#include <cmath>
#include<string>

using namespace std;

int evaluatePostfix(string exp) {
    stack<int> s;

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            s.push(num);
            i--;
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^' || exp[i] == '%' || exp[i] == 'sqrt') {
            if (s.size() < 2) {
                cout << "Error: Insufficient operands" << endl;
                return -1;
            }
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();
            int result;
            switch (exp[i]) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/': result = num1 / num2; break;
            case '^': result = pow(num1, num2); break;
            case '%': result = num1 % num2; break;
            case 's': result = sqrt(num2); break;
            }
            s.push(result);
        }
        else {
            cout << "Error: Invalid Operator" << endl;
            return -1;
        }
    }
    if (s.size() == 1)
        return s.top();
    else {
        cout << "Error: Insufficient Operators" << endl;
        return -1;
    }
}

int main() {
    string exp;
    cout << "enter postfix expression:\n" << endl;
    getline(cin,exp);
    cout << evaluatePostfix(exp);

   

    return 0;
}

