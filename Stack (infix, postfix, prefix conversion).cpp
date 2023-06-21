#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(const string& infix) {
    stack<char> stk;
    string postfix;
    for (size_t i = 0; i < infix.length(); ++i) {
        char ch = infix[i];
        if (isalnum(ch))
            postfix += ch;
        else if (ch == '(')
            stk.push(ch);
        else if (ch == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            if (!stk.empty())
                stk.pop();
        }
        else {
            while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                postfix += stk.top();
                stk.pop();
            }
            stk.push(ch);
        }
    }
    while (!stk.empty()) {
        postfix += stk.top();
        stk.pop();
    }
    return postfix;
}

string postfixToPrefix(const string& postfix) {
    stack<string> stk;
    for (size_t i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            string operand(1, ch);
            stk.push(operand);
        } else {
            string operand2 = stk.top();
            stk.pop();
            string operand1 = stk.top();
            stk.pop();
            string expression = ch + operand1 + operand2;
            stk.push(expression);
        }
    }
    return stk.top();
}

int evaluatePostfix(const string& postfix) {
    stack<int> stk;
    for (size_t i = 0; i < postfix.length(); ++i) {
        char ch = postfix[i];
        if (isdigit(ch)) {
            int operand = ch - '0';
            stk.push(operand);
        } else {
            int operand2 = stk.top();
            stk.pop();
            int operand1 = stk.top();
            stk.pop();
            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = static_cast<int>(pow(operand1, operand2));
                    break;
                default:
                    result = 0;
                    break;
            }
            stk.push(result);
        }
    }
    return stk.top();
}

int main() {
    int choice;
    string expression;
    do {
        cout << "Expression Conversion and Evaluation Menu" << endl;
        cout << "1. Convert Infix to Postfix" << endl;
        cout << "2. Convert Postfix to Prefix" << endl;
        cout << "3. Evaluate Postfix Expression" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an infix expression: ";
                cin.ignore();
                getline(cin, expression);
                cout << "Postfix expression: " << infixToPostfix(expression) << endl;
                break;
            case 2:
                cout << "Enter a postfix expression: ";
                cin.ignore();
                getline(cin, expression);
                cout << "Prefix expression: " << postfixToPrefix(expression) << endl;
                break;
            case 3:
                cout << "Enter a postfix expression: ";
                cin.ignore();
                getline(cin, expression);
                cout << "Evaluation result: " << evaluatePostfix(expression) << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        cout << endl;
    } while (choice != 4);

    return 0;
}

