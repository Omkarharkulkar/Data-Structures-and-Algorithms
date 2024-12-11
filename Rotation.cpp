#include <iostream>
using namespace std;

int main() {
    int n = 2, m = 6;
    int array[10] = {1, 2, 3, 4, 5, 6, 7};

    // Check bounds to avoid accessing elements outside the array
    if (m >= 10 || n >= 10) {
        cout << "Indices out of bounds!" << endl;
        return 1;
    }

    // Print elements from n to m
    cout << "Shifted array: ";
    for (int i = n; i <= m; i++) {
        cout << array[i] << " ";
    }

    // Print elements from 0 to n-1
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

