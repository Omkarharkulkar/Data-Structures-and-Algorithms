#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student's placement information
struct PlacementInfo {
    string name;
    string company;
    int salary;
    PlacementInfo* next;
};

// Function to create a new placement info node
PlacementInfo* createNode(string name, string company, int salary) {
    PlacementInfo* newNode = new PlacementInfo;
    newNode->name = name;
    newNode->company = company;
    newNode->salary = salary;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new placement info at the beginning of the list
void insertPlacementInfo(PlacementInfo*& head, string name, string company, int salary) {
    PlacementInfo* newNode = createNode(name, company, salary);
    newNode->next = head;
    head = newNode;
    cout << "Placement information inserted successfully." << endl;
}

// Function to display all placement information in the list
void displayPlacementInfo(const PlacementInfo* head) {
    if (head == NULL) {
        cout << "No placement information available." << endl;
        return;
    }

    cout << "Placement Information List:" << endl;
    cout << "Name\t\tCompany\t\tSalary" << endl;

    const PlacementInfo* current = head;
    while (current != NULL) {
        cout << current->name << "\t\t" << current->company << "\t\t" << current->salary << endl;
        current = current->next;
    }
}

// Function to search for a placement info by name
void searchPlacementInfo(const PlacementInfo* head, string name) {
    if (head == NULL) {
        cout << "No placement information available." << endl;
        return;
    }

    const PlacementInfo* current = head;
    while (current != NULL) {
        if (current->name == name) {
            cout << "Placement Information Found:" << endl;
            cout << "Name: " << current->name << endl;
            cout << "Company: " << current->company << endl;
            cout << "Salary: " << current->salary << endl;
            return;
        }
        current = current->next;
    }

    cout << "Placement information not found." << endl;
}

// Function to update a placement info by name
void updatePlacementInfo(PlacementInfo* head, string name, string newCompany, int newSalary) {
    PlacementInfo* current = head;
    while (current != NULL) {
        if (current->name == name) {
            current->company = newCompany;
            current->salary = newSalary;
            cout << "Placement information updated successfully." << endl;
            return;
        }
        current = current->next;
    }

    cout << "Placement information not found." << endl;
}

// Function to delete a placement info by name
void deletePlacementInfo(PlacementInfo*& head, string name) {
    if (head == NULL) {
        cout << "No placement information available." << endl;
        return;
    }

    PlacementInfo* current = head;
    PlacementInfo* prev = NULL;

    // If the first node matches the name
    if (current != NULL && current->name == name) {
        head = current->next;
        delete current;
        cout << "Placement information deleted successfully." << endl;
        return;
    }

    while (current != NULL && current->name != name) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Placement information not found." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
    cout << "Placement information deleted successfully." << endl;
}

// Function to sort the placement information list by name in ascending order
void sortPlacementInfo(PlacementInfo*& head) {
    if (head == NULL || head->next == NULL) {
        cout << "No placement information available or only one node exists. Sorting not required." << endl;
        return;
    }

    PlacementInfo* current = head;
    PlacementInfo* index = NULL;
    string tempName;
    string tempCompany;
    int tempSalary;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->name > index->name) {
                tempName = current->name;
                tempCompany = current->company;
                tempSalary = current->salary;
                current->name = index->name;
                current->company = index->company;
                current->salary = index->salary;
                index->name = tempName;
                index->company = tempCompany;
                index->salary = tempSalary;
            }

            index = index->next;
        }

        current = current->next;
    }

    cout << "Placement information sorted successfully." << endl;
}

// Function to delete all placement information and free memory
void deleteAllPlacementInfo(PlacementInfo*& head) {
    PlacementInfo* current = head;
    PlacementInfo* next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }

    head = NULL;
    cout << "All placement information deleted successfully." << endl;
}

int main() {
    PlacementInfo* head = NULL;
    int choice;
    string name, company;
    int salary;

    do {
        cout << "\n--- Placement Information System ---" << endl;
        cout << "1. Insert Placement Information" << endl;
        cout << "2. Display Placement Information" << endl;
        cout << "3. Search Placement Information" << endl;
        cout << "4. Update Placement Information" << endl;
        cout << "5. Delete Placement Information" << endl;
        cout << "6. Sort Placement Information" << endl;
        cout << "7. Delete All Placement Information" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Company: ";
                getline(cin, company);
                cout << "Enter Salary: ";
                cin >> salary;
                insertPlacementInfo(head, name, company, salary);
                break;
            case 2:
                displayPlacementInfo(head);
                break;
            case 3:
                cout << "\nEnter Name to Search: ";
                cin.ignore();
                getline(cin, name);
                searchPlacementInfo(head, name);
                break;
            case 4:
                cout << "\nEnter Name to Update: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter New Company: ";
                getline(cin, company);
                cout << "Enter New Salary: ";
                cin >> salary;
                updatePlacementInfo(head, name, company, salary);
                break;
            case 5:
                cout << "\nEnter Name to Delete: ";
                cin.ignore();
                getline(cin, name);
                deletePlacementInfo(head, name);
                break;
            case 6:
                sortPlacementInfo(head);
                break;
            case 7:
                deleteAllPlacementInfo(head);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}

