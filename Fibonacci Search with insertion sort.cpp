#include <iostream>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int fibonacciSearch(int arr[], int size, int target) {
    int fib2 = 0; // (n-2)th Fibonacci number
    int fib1 = 1; // (n-1)th Fibonacci number
    int fib = fib2 + fib1; // nth Fibonacci number

    while (fib < size) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, size - 1);

        if (arr[i] < target) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > target) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if (fib1 == 1 && arr[offset + 1] == target) {
        return offset + 1;
    }

    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // Sort the array using insertion sort
    insertionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    // Perform Fibonacci search on the sorted array
    int result = fibonacciSearch(arr, size, target);

    if (result == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << result << endl;

    delete[] arr;

    return 0;
}

