#include <iostream>
using namespace std;

// Function to compute the nth term of a linear recurrence sequence
int linearRecurrence(int n, int initialTerms[], int coefficients[], int m) {
    if (n < m)
        return initialTerms[n];

    int* sequence = new int[n + 1];  // Dynamically allocate memory for the sequence
    for (int i = 0; i < m; ++i) {
        sequence[i] = initialTerms[i];
    }

    for (int i = m; i <= n; ++i) {
        int term = 0;
        for (int j = 0; j < m; ++j) {
            term += coefficients[j] * sequence[i - j - 1];
        }
        sequence[i] = term;
    }

    int result = sequence[n];
    delete[] sequence;  // Free the dynamically allocated memory
    return result;
}

int main() {
    int m; // Number of initial terms
    cout << "Enter the number of initial terms: ";
    cin >> m;

    int* initialTerms = new int[m];
    cout << "Enter the initial terms: ";
    for (int i = 0; i < m; ++i) {
        cin >> initialTerms[i];
    }

    int* coefficients = new int[m];
    cout << "Enter the coefficients: ";
    for (int i = 0; i < m; ++i) {
        cin >> coefficients[i];
    }

    int n; // Term to compute
    cout << "Enter the term to compute: ";
    cin >> n;

    int result = linearRecurrence(n, initialTerms, coefficients, m);
    cout << "The " << n << "th term of the sequence: " << result << endl;

    // Free dynamically allocated memory
    delete[] initialTerms;
    delete[] coefficients;

    return 0;
}

