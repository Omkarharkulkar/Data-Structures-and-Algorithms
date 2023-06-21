#include <iostream>
#include <string>
using namespace std;

struct Town {
    string name;
    int population;
};

void swap(Town& a, Town& b) {
    Town temp = a;
    a = b;
    b = temp;
}

void insertionSort(Town arr[], int size) {
    for (int i = 1; i < size; i++) {
        Town key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].population > key.population) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int partition(Town arr[], int low, int high) {
    int pivot = arr[high].population;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].population < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Town arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void printArray(Town arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i].name << " (" << arr[i].population << ") ";
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the number of towns: ";
    cin >> size;

    Town* towns = new Town[size];

    cout << "Enter the details of towns:\n";
    for (int i = 0; i < size; i++) {
        cout << "Town " << i + 1 << ":\n";
        cout << "Name: ";
        cin.ignore();
        getline(cin, towns[i].name);
        cout << "Population: ";
        cin >> towns[i].population;
    }

    int choice;
    cout << "\nMenu:\n";
    cout << "1. Sort using Insertion Sort\n";
    cout << "2. Sort using Quick Sort\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            insertionSort(towns, size);
            cout << "\nSorted towns using Insertion Sort:\n";
            printArray(towns, size);
            break;
        case 2:
            quickSort(towns, 0, size - 1);
            cout << "\nSorted towns using Quick Sort:\n";
            printArray(towns, size);
            break;
        default:
            cout << "Invalid choice!";
            break;
    }

    delete[] towns;

    return 0;
}

