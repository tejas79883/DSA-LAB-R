#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX_SIZE = 20; // Adjust the size as needed

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int value) {
        if (top < MAX_SIZE - 1) {
            arr[++top] = value;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        } else {
            cout << "Stack underflow!" << endl;
            return INT_MIN; // Indicates an error
        }
    }

    int getTop() {
        if (!isEmpty()) {
            return arr[top];
        }
        return INT_MIN; // Indicates an error
    }
};

bool isOperator(char c) {
    return (c == '^' || c == '+' || c == '-' || c == '*' || c == '/');
}

int prefixToInfix(string prefix) {
    Stack s;
    int ans = 0;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        if (prefix[i] >= '0' && prefix[i] <= '9') {
            s.push(prefix[i] - '0');
        } else if (isOperator(prefix[i])) {
            int op1 = s.pop();
            int op2 = s.pop();

            switch (prefix[i]) {
                case '+':
                    ans = op1 + op2;
                    break;
                case '-':
                    ans = op1 - op2;
                    break;
                case '*':
                    ans = op1 * op2;
                    break;
                case '/':
                    ans = op1 / op2;
                    break;
                case '^':
                    ans = int(pow(op1, op2));
                    break;
                default:
                    break;
            }

            s.push(ans);
        }
    }
    return s.getTop();
}

int main() {
    string prefix;
    int infix;
    cout << "Enter a PREFIX Expression : ";
    cin >> prefix;
    infix = prefixToInfix( prefix);
	cout << "Your Evaluated PREFIX EXPRESSION is : " << infix << endl;

    return 0;
}

