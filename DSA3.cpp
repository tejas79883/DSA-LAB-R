#include <iostream>
#include <algorithm>
using namespace std;

// Node structure for the singly linked list
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

    bool isEmpty() {
        return top == NULL;
    }

    void push(char c) {
        Node* newNode = new Node;
        newNode->data = c;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (!isEmpty()) {
            char popped = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return popped;
        }
        return '\0';
    }

    char getTop() {
        if (!isEmpty()) {
            return top->data;
        }
        return '\0';
    }
};

bool isOperator(char c) {
    return (c == '^' || c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '^' || c == '$') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPrefix(Stack& s, const string& infix) {
    string prefix;

    // Reverse the infix expression
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end()); 
    
	/* Manually reverse function
    for (int i = 0; i < reversedInfix.length(); i++) 
	{
		 int lower=0;
    	 int upper=reversedInfix.size()-1;   
    char tempChar;          
    while(lower<upper)
    {
        tempChar=reversedInfix[lower];
        reversedInfix[lower]=reversedInfix[upper];
        reversedInfix[upper]=tempChar;
        lower++;
        upper--;
    }
   
    }*/

    for (int i = 0; i < reversedInfix.length(); i++) {
        if ((reversedInfix[i] >= 'a' && reversedInfix[i] <= 'z') || (reversedInfix[i] >= 'A' && reversedInfix[i] <= 'Z')) {
            prefix += reversedInfix[i];
        } else if (reversedInfix[i] == ')') {
            s.push(reversedInfix[i]);
        } else if (reversedInfix[i] == '(') {
            while ((s.getTop() != ')') && (!s.isEmpty())) {
                prefix += s.pop();
            }
            if (s.getTop() == ')') {
                s.pop(); // Discard the ')'
            }
        } else if (isOperator(reversedInfix[i])) {
            if (s.isEmpty()) {
                s.push(reversedInfix[i]);
            } else {
                if (precedence(reversedInfix[i]) == precedence(s.getTop()) && reversedInfix[i] == '^') {
                    s.push(reversedInfix[i]);
                } else {
                    while ((!s.isEmpty()) && (precedence(reversedInfix[i]) < precedence(s.getTop()))) {
                        prefix += s.pop();
                    }
                    s.push(reversedInfix[i]);
                }
            }
        }
    }

    while (!s.isEmpty()) {
        prefix += s.pop();
    }

    // Reverse the final prefix expression
    cout << "PREFIX Expression beforw : " << prefix << endl;
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    string infix, prefix;
    Stack stack;
    cout << "Enter an Infix Expression : ";
    cin >> infix;
    prefix = infixToPrefix(stack, infix);
    cout << "PREFIX Expression : " << prefix << endl;
    return 0;
}


