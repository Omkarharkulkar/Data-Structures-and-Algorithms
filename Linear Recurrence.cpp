#include <iostream>
#include <vector>
using namespace std;

// Function to compute the nth term of a linear recurrence sequence
int linearRecurrence(int n, const vector<int>& initialTerms, const vector<int>& coefficients) {
    int m = initialTerms.size();
    if (n < m)
        return initialTerms[n];

    vector<int> sequence = initialTerms;
    for (int i = m; i <= n; ++i) {
        int term = 0;
        for (int j = 0; j < m; ++j) {
            term += coefficients[j] * sequence[i - j - 1];
        }
        sequence.push_back(term);
    }

    return sequence[n];
}

int main() {
    int m; // Number of initial terms
    cout << "Enter the number of initial terms: ";
    cin >> m;

    vector<int> initialTerms(m);
    cout << "Enter the initial terms: ";
    for (int i = 0; i < m; ++i) {
        cin >> initialTerms[i];
    }

    vector<int> coefficients(m);
    cout << "Enter the coefficients: ";
    for (int i = 0; i < m; ++i) {
        cin >> coefficients[i];
    }

    int n; // Term to compute
    cout << "Enter the term to compute: ";
    cin >> n;

    int result = linearRecurrence(n, initialTerms, coefficients);
    cout << "The " << n << "th term of the sequence: " << result << endl;

    return 0;
}

