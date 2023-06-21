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

int sentinelSearch(int arr[], int size, int target) {
    int last = arr[size - 1];
    arr[size - 1] = target;

    int i = 0;
    while (arr[i] != target)
        i++;

    arr[size - 1] = last;

    if (i < size - 1 || arr[size - 1] == target)
        return i;
    else
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

    // Perform Sentinel Search on the sorted array
    int result = sentinelSearch(arr, size, target);

    if (result == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << result << endl;

    delete[] arr;

    return 0;
}

