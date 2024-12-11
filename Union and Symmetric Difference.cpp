#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Dynamically allocate temporary arrays
    int* L = new int[n1];
    int* R = new int[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free the dynamically allocated memory
    delete[] L;
    delete[] R;
}

// Function to perform merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to find the union and symmetric difference of two sorted arrays
void findUnionSymmetricDiff(int arr1[], int n1, int arr2[], int n2) {
    int i = 0, j = 0;

    // Print Union
    cout << "Union: ";
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        } else if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        } else {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
    }

    // Print remaining elements of the arrays
    while (i < n1) {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n2) {
        cout << arr2[j] << " ";
        j++;
    }
    cout << endl;

    // Print Symmetric Difference
    i = 0;
    j = 0;
    cout << "Symmetric Difference: ";
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            cout << arr1[i] << " ";
            i++;
        } else if (arr1[i] > arr2[j]) {
            cout << arr2[j] << " ";
            j++;
        } else {
            i++;
            j++;
        }
    }

    // Print remaining elements of the arrays
    while (i < n1) {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n2) {
        cout << arr2[j] << " ";
        j++;
    }
    cout << endl;
}

int main() {
    const int maxSize = 100; // Maximum size of the arrays
    int arr1[maxSize], arr2[maxSize];
    int n1, n2;

    // Input for the first array
    cout << "Enter the size of the first array: ";
    cin >> n1;

    if (n1 <= 0 || n1 > maxSize) {
        cout << "Invalid size for the first array." << endl;
        return 1;
    }

    cout << "Enter the elements of the first array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    // Input for the second array
    cout << "Enter the size of the second array: ";
    cin >> n2;

    if (n2 <= 0 || n2 > maxSize) {
        cout << "Invalid size for the second array." << endl;
        return 1;
    }

    cout << "Enter the elements of the second array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    // Sort both arrays
    mergeSort(arr1, 0, n1 - 1);
    mergeSort(arr2, 0, n2 - 1);

    // Find and print union and symmetric difference
    findUnionSymmetricDiff(arr1, n1, arr2, n2);

    return 0;
}

