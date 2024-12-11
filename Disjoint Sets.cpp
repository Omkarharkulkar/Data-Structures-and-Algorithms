#include <iostream>
using namespace std;

// Function to check if two arrays are disjoint
bool areDisjoint(int array1[], int array2[], int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (array1[i] == array2[j]) {
                return false; // Found a common element
            }
        }
    }
    return true; // No common elements
}

int main() {
    int n1 = 3, n2 = 3;
    int array1[10] = {1, 2, 3};
    int array2[10] = {4, 5, 3};

    // Display first array
    cout << "Array 1: ";
    for (int i = 0; i < n1; i++) {
        cout << array1[i] << " ";
    }
    cout << endl;

    // Display second array
    cout << "Array 2: ";
    for (int i = 0; i < n2; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;

    // Check if arrays are disjoint
    if (areDisjoint(array1, array2, n1, n2)) {
        cout << "The arrays are disjoint." << endl;
    } else {
        cout << "The arrays are not disjoint." << endl;
    }

    return 0;
}

