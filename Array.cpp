#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the array

// Function to read data from the user
void readData(int arr[], int& size) {
    cout << "Enter the number of elements: ";
    cin >> size;

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

// Function to display the array elements
void displayData(const int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to insert an element into the array
void insertElement(int arr[], int& size, int element, int position) {
    if (size >= MAX_SIZE) {
        cout << "Array is full. Cannot insert element." << endl;
        return;
    }

    if (position < 0 || position > size) {
        cout << "Invalid position. Cannot insert element." << endl;
        return;
    }

    // Shift elements to the right from the given position
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the element at the given position
    arr[position] = element;

    size++; // Increase the size of the array

    cout << "Element inserted successfully." << endl;
}

// Function to update an element in the array
void updateElement(int arr[], int size, int element, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position. Cannot update element." << endl;
        return;
    }

    // Update the element at the given position
    arr[position] = element;

    cout << "Element updated successfully." << endl;
}

// Function to delete an element from the array
void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position. Cannot delete element." << endl;
        return;
    }

    // Shift elements to the left from the given position
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Decrease the size of the array

    cout << "Element deleted successfully." << endl;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        cout << "\n----- Menu -----" << endl;
        cout << "1. Read data" << endl;
        cout << "2. Display data" << endl;
        cout << "3. Insert element" << endl;
        cout << "4. Update element" << endl;
        cout << "5. Delete element" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                readData(arr, size);
                break;
            case 2:
                displayData(arr, size);
                break;
            case 3: {
                int element, position;
                cout << "Enter the element to insert: ";
                cin >> element;
                cout << "Enter the position to insert at: ";
                cin >> position;
                insertElement(arr, size, element, position);
                break;
            }
            case 4: {
                int element, position;
                cout << "Enter the element to update: ";
                cin >> element;
                cout << "Enter the position to update at: ";
                cin >> position;
                updateElement(arr, size, element, position);
                break;
            }
            case 5: {
                int position;
                cout << "Enter the position to delete from: ";
                cin >> position;
                deleteElement(arr, size, position);
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

