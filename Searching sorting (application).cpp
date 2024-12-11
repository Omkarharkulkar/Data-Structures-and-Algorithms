#include <iostream>
#include <cstring> // For string manipulation
#define MAX 50
using namespace std;

struct Student {
    int rollNo;
    char name[50];
    float sgpa;
    char department[50];
};

void inputStudents(Student students[], int n);
void displayStudents(Student students[], int n);

// Bubble Sort for Roll Numbers
void bubbleSort(Student students[], int n);

// Insertion Sort for Names
void insertionSort(Student students[], int n);

// Quick Sort for SGPA
int partition(Student students[], int low, int high);
void quickSort(Student students[], int low, int high);

// Linear Search for SGPA
void searchBySGPA(Student students[], int n, float sgpa);

// Binary Search for Name
void binarySearchByName(Student students[], int n, const char key[]);

// Fibonacci Search for Department
bool isComputerDept(Student students[], int n, const char key[]);

// Helper functions
void swap(Student &a, Student &b);

int main() {
    int n, choice;
    cout << "Enter the number of students: ";
    cin >> n;

    Student students[MAX];
    inputStudents(students, n);

    while (true) {
        cout << "\nStudent Database Operations:\n";
        cout << "1. Design Roll Call List (Bubble Sort by Roll Numbers)\n";
        cout << "2. Arrange Alphabetically (Insertion Sort by Name)\n";
        cout << "3. Find Top 10 Toppers (Quick Sort by SGPA)\n";
        cout << "4. Search by SGPA (Linear Search)\n";
        cout << "5. Search by Name (Binary Search)\n";
        cout << "6. Check if Student is in Computer Department (Fibonacci Search)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            bubbleSort(students, n);
            cout << "Roll Call List:\n";
            displayStudents(students, n);
            break;
        case 2:
            insertionSort(students, n);
            cout << "Alphabetical Order:\n";
            displayStudents(students, n);
            break;
        case 3:
            quickSort(students, 0, n - 1);
            cout << "Top 10 Toppers:\n";
            displayStudents(students, min(n, 10));
            break;
        case 4: {
            float sgpa;
            cout << "Enter SGPA to search: ";
            cin >> sgpa;
            searchBySGPA(students, n, sgpa);
            break;
        }
        case 5: {
            char key[50];
            cout << "Enter name to search: ";
            cin.ignore();
            cin.getline(key, 50);
            insertionSort(students, n); // Names must be sorted for binary search
            binarySearchByName(students, n, key);
            break;
        }
        case 6: {
            char key[50];
            cout << "Enter student name to check for Computer Department: ";
            cin.ignore();
            cin.getline(key, 50);
            if (isComputerDept(students, n, key)) {
                cout << "The student belongs to the Computer Department.\n";
            } else {
                cout << "The student does not belong to the Computer Department.\n";
            }
            break;
        }
        case 7:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

// Input and Display Functions
void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for student " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore();
        cout << "Name: ";
        cin.getline(students[i].name, 50);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
        cin.ignore();
        cout << "Department: ";
        cin.getline(students[i].department, 50);
    }
}

void displayStudents(Student students[], int n) {
    cout << "Roll No\tName\t\tSGPA\tDepartment\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].sgpa << "\t" << students[i].department << "\n";
    }
}

// Bubble Sort
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                swap(students[j], students[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(Student students[], int n) {
    for (int i = 1; i < n; ++i) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && strcmp(students[j].name, key.name) > 0) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

// Quick Sort
int partition(Student students[], int low, int high) {
    float pivot = students[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (students[j].sgpa > pivot) { // Descending order
            ++i;
            swap(students[i], students[j]);
        }
    }
    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(Student students[], int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

// Linear Search for SGPA
void searchBySGPA(Student students[], int n, float sgpa) {
    bool found = false;
    cout << "Students with SGPA " << sgpa << ":\n";
    for (int i = 0; i < n; ++i) {
        if (students[i].sgpa == sgpa) {
            cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].sgpa << "\t" << students[i].department << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with SGPA " << sgpa << ".\n";
    }
}

// Binary Search for Name
void binarySearchByName(Student students[], int n, const char key[]) {
    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (strcmp(students[mid].name, key) == 0) {
            cout << "Student Found:\n";
            cout << students[mid].rollNo << "\t" << students[mid].name << "\t" << students[mid].sgpa << "\t" << students[mid].department << "\n";
            found = true;
            break;
        }
        if (strcmp(students[mid].name, key) > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    if (!found) {
        cout << "No student found with name " << key << ".\n";
    }
}

// Fibonacci Search for Department
bool isComputerDept(Student students[], int n, const char key[]) {
    int fibMMm2 = 0; // (m-2)th Fibonacci
    int fibMMm1 = 1; // (m-1)th Fibonacci
    int fibM = fibMMm2 + fibMMm1; // mth Fibonacci

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;
    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        if (strcmp(students[i].name, key) < 0) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (strcmp(students[i].name, key) > 0) {
            fibM = fibMMm2;
            fibMMm1 -= fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        } else {
            return strcmp(students[i].department, "Computer") == 0;
        }
    }
    return false;
}

// Swap Function
void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}

