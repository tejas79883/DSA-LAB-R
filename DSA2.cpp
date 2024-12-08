#include <algorithm>
using namespace std;

// Node st#include <iostream>
sructure for the singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack class using singly linked list
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Function to push a character onto the stack
    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    // Function to pop a character from the stack
    char pop() {
        if (!isEmpty()) {
            char popped = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return popped;
        }
        return '\0'; // '\0' indicates an empty character
    }

    // Function to get the top element of the stack
    char getTop() {
        if (!isEmpty()) {
            return top->data;
        }
        return '\0'; // '\0' indicates an empty character
    }
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^'|| c == '$');
}

int precedence(char c) {
    if (c == '^' || c == '$') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// INFIX TO POSTFIX CONVERSION FUNCTION
string InfixToPostfix(Stack& s, const string& infix) {
    string postfix;

    for (int i = 0; i < infix.length(); i++) {
        if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= '9')|| (infix[i] >= '0' && infix[i] <= 'Z')) {
            postfix += infix[i];
        } else if (infix[i] == '(') {
            s.push(infix[i]);
        } else if (infix[i] == ')') {
            while ((s.getTop() != '(') && (!s.isEmpty())) {
                postfix += s.pop();
            }

            if (s.getTop() == '(') {
                s.pop();
            }
        } else if (isOperator(infix[i])) {
            if (s.isEmpty()) {
                s.push(infix[i]);
            } else {
                if (precedence(infix[i]) == precedence(s.getTop()) && infix[i] == '^') {
                    s.push(infix[i]);
                } else {
                    while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.getTop()))) {
                        postfix += s.pop();
                    }
                    s.push(infix[i]);
                }
            }
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    string infix, postfix;
    cout << "Enter an Infix EXPRESSION :";
    cin >> infix;
    Stack stack;
    postfix = InfixToPostfix(stack, infix);
    cout << "\nPOSTFIX EXPRESSION :" << postfix << endl;
    return 0;
}




