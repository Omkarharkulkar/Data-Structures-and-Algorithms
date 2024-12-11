#include <iostream>
using namespace std;

// Function to perform merge operation on two halves of the array
void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Dynamically allocate temporary arrays
    float* L = new float[n1];
    float* R = new float[n2];

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
void mergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main() {
    const int maxSize = 100; // Maximum size of the array
    float percentages[maxSize];
    int n;

    // Input for the array size
    cout << "Enter the number of second-year students: ";
    cin >> n;

    // Validate the input size
    if (n <= 0 || n > maxSize) {
        cout << "Invalid number of students. Please enter a value between 1 and " << maxSize << "." << endl;
        return 1;
    }

    // Input for the array elements
    cout << "Enter the percentages of students:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    // Sort the array using merge sort
    mergeSort(percentages, 0, n - 1);

    // Display the sorted array
    cout << "Sorted Percentages in Ascending Order:" << endl;
    for (int i = 0; i < n; i++) {
        cout << percentages[i] << " ";
    }
    cout << endl;

    return 0;
}

