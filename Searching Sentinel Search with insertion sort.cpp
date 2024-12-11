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

int sentinelSearch(int arr[], int size, int target) 
{
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

    // Sort the array using insertion sort
    insertionSort(arr, size);

    cout << "Sorted array: ";
    printArray(arr, size);

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;

    // Perform sentinel search on the sorted array
    int result = sentinelSearch(arr, size, target);

    if (result == -1)
        cout << "Target not found." << endl;
    else
        cout << "Target found at index " << result << endl;

    delete[] arr;

    return 0;
}

