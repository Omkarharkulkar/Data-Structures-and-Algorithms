#include <iostream>
using namespace std;

// Function to calculate factorial
unsigned long long factorial(int num) {
    if (num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

// Function to calculate permutations (nPr)
unsigned long long permutations(int n, int r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return factorial(n) / factorial(n - r);
}

// Function to calculate combinations (nCr)
unsigned long long combinations(int n, int r) {
    if (n < r || n < 0 || r < 0)
        return 0;
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    int n, r;

    // Get user input for n and r
    cout << "ENTER THE VALUE OF N: ";
    cin >> n;

    cout << "ENTER THE VALUE OF R: ";
    cin >> r;

    // Validate inputs
    if (r > n) {
        cout << "Invalid input. R cannot be greater than N.\n";
        return 1;
    }
    if (n < 0 || r < 0) {
        cout << "Invalid input. N and R cannot be negative.\n";
        return 1;
    }

    // Calculate and display permutations
    cout << "Permutations P(" << n << ", " << r << ") = " << permutations(n, r) << endl;

    // Calculate and display combinations
    cout << "Combinations C(" << n << ", " << r << ") = " << combinations(n, r) << endl;

    return 0;
}

