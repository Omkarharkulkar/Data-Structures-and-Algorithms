#include <iostream>
using namespace std;

// Heapify the subtree rooted at 'root' to maintain heap property
void heapify(int arr[], int n, int root, bool ascending) 
{
    int largest = root; // Initialize largest as root
    int left = 2 * root + 1; // Left child
    int right = 2 * root + 2; // Right child

    // If left child is larger than root
    if (left < n && ((ascending && arr[left] > arr[largest]) || (!ascending && arr[left] < arr[largest])))
        largest = left;

    // If right child is larger than largest so far
    if (right < n && ((ascending && arr[right] > arr[largest]) || (!ascending && arr[right] < arr[largest])))
        largest = right;

    // If largest is not root
    if (largest != root) 
	{
        swap(arr[root], arr[largest]);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest, ascending);
    }
}

// Main function to perform heap sort
void heapSort(int arr[], int n, bool ascending) 
{
    // Build a max-heap or min-heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    // Extract elements from the heap one by one
    for (int i = n - 1; i > 0; i--) 
	{
        // Move current root to end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0, ascending);
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main() 
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) 
	{
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, n);

    // Sort in ascending order
    heapSort(arr, n, true);
    cout << "Array sorted in ascending order: ";
    printArray(arr, n);

    // Sort in descending order
    heapSort(arr, n, false);
    cout << "Array sorted in descending order: ";
    printArray(arr, n);

    return 0;
}

