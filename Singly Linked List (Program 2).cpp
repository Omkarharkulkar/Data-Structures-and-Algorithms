#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Linked list class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted successfully." << endl;
    }

    // Function to update a node in the linked list
    void update(int oldValue, int newValue) {
        Node* current = head;
        bool found = false;

        while (current != NULL) {
            if (current->data == oldValue) {
                current->data = newValue;
                found = true;
                cout << "Node updated successfully." << endl;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Node not found in the linked list." << endl;
        }
    }

    // Function to search for a node in the linked list
    void search(int value) {
        Node* current = head;
        bool found = false;
        int index = 0;

        while (current != NULL) {
            if (current->data == value) {
                found = true;
                cout << "Node found at index " << index << "." << endl;
                break;
            }
            current = current->next;
            index++;
        }

        if (!found) {
            cout << "Node not found in the linked list." << endl;
        }
    }

    // Function to sort the linked list in ascending order using insertion sort
    void sort() {
        if (head == NULL || head->next == NULL) {
            cout << "Linked list is already sorted." << endl;
            return;
        }

        Node* sortedList = NULL;
        Node* current = head;

        while (current != NULL) {
            Node* nextNode = current->next;
            insertNodeSorted(sortedList, current);
            current = nextNode;
        }

        head = sortedList;
        cout << "Linked list sorted successfully." << endl;
    }

    // Helper function to insert a node into a sorted linked list
    void insertNodeSorted(Node*& sortedList, Node* newNode) {
        if (sortedList == NULL || newNode->data <= sortedList->data) {
            newNode->next = sortedList;
            sortedList = newNode;
        } else {
            Node* current = sortedList;

            while (current->next != NULL && current->next->data < newNode->data) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to display the linked list
    void display() {
        if (head == NULL) {
            cout << "Linked list is empty." << endl;
            return;
        }

        cout << "Linked list: ";
        Node* current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Function to delete a node from the linked list
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "Linked list is empty. Deletion failed." << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;
        bool found = false;

        while (current != NULL) {
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                found = true;
                cout << "Node deleted successfully." << endl;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (!found) {
            cout << "Node not found in the linked list. Deletion failed." << endl;
        }
    }
};

int main() {
    LinkedList linkedList;
    int choice;

    while (true) {
        cout << "\n---------- MENU ----------" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Update a node" << endl;
        cout << "3. Search for a node" << endl;
        cout << "4. Sort the linked list" << endl;
        cout << "5. Display the linked list" << endl;
        cout << "6. Delete a node" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                linkedList.insert(value);
                break;
            }
            case 2: {
                int oldValue, newValue;
                cout << "Enter the value to update: ";
                cin >> oldValue;
                cout << "Enter the new value: ";
                cin >> newValue;
                linkedList.update(oldValue, newValue);
                break;
            }
            case 3: {
                int value;
                cout << "Enter the value to search: ";
                cin >> value;
                linkedList.search(value);
                break;
            }
            case 4:
                linkedList.sort();
                break;
            case 5:
                linkedList.display();
                break;
            case 6: {
                int value;
                cout << "Enter the value to delete: ";
                cin >> value;
                linkedList.deleteNode(value);
                break;
            }
            case 7:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

