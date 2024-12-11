#include <iostream>
#include <cstdlib> // For exit()
#include <cmath>   // For abs()
using namespace std;

const int N = 8;

// Stack to store the positions of queens
struct Stack {
    int items[N];
    int top;
};

// Function to initialize the stack
void initStack(Stack& stack) {
    stack.top = -1;
}

// Function to check if the stack is empty
bool isEmpty(const Stack& stack) {
    return stack.top == -1;
}

// Function to push an item onto the stack
void push(Stack& stack, int item) {
    if (stack.top == N - 1) {
        cerr << "Stack overflow. Cannot push." << endl;
        exit(EXIT_FAILURE);
    }
    stack.items[++stack.top] = item;
}

// Function to pop an item from the stack
int pop(Stack& stack) {
    if (isEmpty(stack)) {
        cerr << "Stack underflow. Cannot pop." << endl;
        exit(EXIT_FAILURE);
    }
    return stack.items[stack.top--];
}

// Function to check if placing a queen at the current position is safe
bool isSafe(const Stack& stack, int row, int col) {
    for (int i = 0; i <= stack.top; ++i) {
        int prevRow = i;
        int prevCol = stack.items[i];

        // Check if queens are in the same column or on the same diagonal
        if (col == prevCol || abs(row - prevRow) == abs(col - prevCol)) {
            return false; // Queen clashes with another queen
        }
    }
    return true;
}

// Function to solve the 8-Queens problem using backtracking and a stack
void solveQueensProblem() {
    Stack stack;
    initStack(stack);

    int row = 0;
    int col = 0;

    while (row < N) {
        while (col < N) {
            if (isSafe(stack, row, col)) {
                push(stack, col);
                break;
            }
            col++;
        }

        if (col == N) {
            if (isEmpty(stack)) {
                cout << "No solution exists." << endl;
                return;
            }

            col = pop(stack) + 1;
            row--;
        } else {
            if (stack.top == N - 1) {
                cout << "Solution found:" << endl;
                for (int i = 0; i < N; ++i) {
                    cout << "(" << i + 1 << ", " << stack.items[i] + 1 << ") ";
                }
                cout << endl;
                return;
            }

            row++;
            col = 0;
        }
    }
}

int main() {
    solveQueensProblem();
    return 0;
}

