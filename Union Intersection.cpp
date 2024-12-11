#include <iostream>
using namespace std;

// Function to find and print the union of two arrays
void findUnion(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    cout << "Union: ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i++] << " ";
        } else if (arr2[j] < arr1[i]) {
            cout << arr2[j++] << " ";
        } else {
            cout << arr1[i++] << " ";
            j++;
        }
    }
    // Print remaining elements of arr1
    while (i < m) {
        cout << arr1[i++] << " ";
    }
    // Print remaining elements of arr2
    while (j < n) {
        cout << arr2[j++] << " ";
    }
    cout << endl;
}

// Function to find and print the intersection of two arrays
void findIntersection(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    cout << "Intersection: ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
}

// Function to find and print the difference (arr1 - arr2)
void findDifference(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    cout << "Difference (arr1 - arr2): ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        } else if (arr2[j] < arr1[i]) {
            j++;
        } else {
            i++;
            j++;
        }
    }
    // Print remaining elements of arr1
    while (i < m) {
        cout << arr1[i++] << " ";
    }
    cout << endl;
}

// Function to find and print the symmetric difference of two arrays
void findSymmetricDifference(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    cout << "Symmetric Difference: ";
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i++] << " ";
        } else if (arr2[j] < arr1[i]) {
            cout << arr2[j++] << " ";
        } else {
            i++;
            j++;
        }
    }
    // Print remaining elements of arr1
    while (i < m) {
        cout << arr1[i++] << " ";
    }
    // Print remaining elements of arr2
    while (j < n) {
        cout << arr2[j++] << " ";
    }
    cout << endl;
}

int main() {
    int m, n;

    // Input size and elements of the first array
    cout << "Enter the size of the first array: ";
    cin >> m;
    int arr1[m];
    cout << "Enter the elements of the first sorted array: ";
    for (int i = 0; i < m; i++)
        cin >> arr1[i];

    // Input size and elements of the second array
    cout << "Enter the size of the second array: ";
    cin >> n;
    int arr2[n];
    cout << "Enter the elements of the second sorted array: ";
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    // Perform operations and display results
    findUnion(arr1, m, arr2, n);
    findIntersection(arr1, m, arr2, n);
    findDifference(arr1, m, arr2, n);
    findSymmetricDifference(arr1, m, arr2, n);

    return 0;
}

