#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
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

    // Sort the array using Quick Sort
    quickSort(arr, 0, size - 1);

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

