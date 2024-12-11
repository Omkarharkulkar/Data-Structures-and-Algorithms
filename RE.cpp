#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

// Utility function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix to postfix
string infixToPostfix(const string& infix) {
    stack<char> s;
    string postfix = "";

    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix += c; // Add operands (letters/numbers) to postfix
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty() && s.top() == '(') s.pop(); // Remove '('
        } else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators from stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

// Function to convert postfix to prefix
string postfixToPrefix(const string& postfix) {
    stack<string> s;

    for (size_t i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isalnum(c)) {
            s.push(string(1, c)); // Push operands to stack
        } else if (isOperator(c)) {
            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();
            string prefix = c + op1 + op2;
            s.push(prefix);
        }
    }
    return s.top();
}

// Function to evaluate postfix expression
int evaluatePostfix(const string& postfix) {
    stack<int> s;

    for (size_t i = 0; i < postfix.length(); i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            s.push(c - '0'); // Convert char to integer
        } else if (isOperator(c)) {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();
            int result;
            switch (c) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default: result = 0; // Should never happen
            }
            s.push(result);
        }
    }
    return s.top();
}

int main() {
    int choice;
    string expression;

    do {
        cout << "\n--- Expression Conversion & Evaluation Menu ---\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Convert Postfix to Prefix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Infix Expression: ";
                cin >> expression;
                cout << "Postfix Expression: " << infixToPostfix(expression) << endl;
                break;

            case 2:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Prefix Expression: " << postfixToPrefix(expression) << endl;
                break;

            case 3:
                cout << "Enter Postfix Expression: ";
                cin >> expression;
                cout << "Evaluation Result: " << evaluatePostfix(expression) << endl;
                break;

            case 4:
                cout << "Exiting Program. Thank you!\n";
                break;

            default:
                cout << "Invalid Option! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

