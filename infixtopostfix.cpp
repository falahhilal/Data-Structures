#include <iostream>
#include <string>
#include <cctype>  
using namespace std;
class Stack {
    private:
        char arr[50];  
        int top;
    public:
        Stack() { top = -1; }  

        bool isEmpty() {
            return top == -1;
        }

        void push(char i) {
            arr[++top] = i;
        }

        char pop() {
            if(isEmpty()) {
                cout << "Stack is empty!" << endl;
                return '\0';  
            }
            else {
                return arr[top--];
            }
        }

        char peek() {
            if (!isEmpty()) {
                return arr[top];
            }
            return '\0';
        }
};

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(string infix) {
    string postfix = "";
    Stack s;

    for (int i=0;i<infix.length();i++) {
        char c = infix[i];
        if (isalpha(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (s.peek() == '(') {
                s.pop();  
            }
        }
        else {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

int main() {
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << expression << endl;
    string postfix = infixToPostfix(expression);
    cout << "Postfix: " << postfix << endl;
    return 0;
}


