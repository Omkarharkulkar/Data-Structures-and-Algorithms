#include <iostream>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert a node at the beginning of the list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

        cout << "Node inserted at the beginning." << endl;
    }

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        cout << "Node inserted at the end." << endl;
    }

    // Function to insert a node after a given position
    void insertAfterPosition(int value, int position) {
        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
            cout << "Node inserted at position " << position << "." << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;

        cout << "Node inserted at position " << position << "." << endl;
    }

    // Function to delete a node from the beginning of the list
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = head;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        cout << "Node deleted from the beginning." << endl;
    }

    // Function to delete a node from the end of the list
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* temp = tail;

        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        cout << "Node deleted from the end." << endl;
    }

    // Function to delete a node at a given position
    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        if (position <= 0) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* current = head;
        int count = 1;

        while (current != NULL && count < position) {
            current = current->next;
            count++;
        }

        if (current == NULL) {
            cout << "Invalid position." << endl;
            return;
        }

        if (current == head) {
            deleteFromBeginning();
        } else if (current == tail) {
            deleteFromEnd();
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            cout << "Node deleted from position " << position << "." << endl;
        }
    }

    // Function to display the elements of the list
    void display() {
        if (head == NULL) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;

        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    int choice, value, position;

    while (true) {
        cout << "\n---------- MENU ----------" << endl;
        cout << "1. Insert at the beginning" << endl;
        cout << "2. Insert at the end" << endl;
        cout << "3. Insert after a position" << endl;
        cout << "4. Delete from the beginning" << endl;
        cout << "5. Delete from the end" << endl;
        cout << "6. Delete at a position" << endl;
        cout << "7. Display the list" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAtBeginning(value);
                break;
            case 2:
                cout << "Enter the value to insert: ";
                cin >> value;
                list.insertAtEnd(value);
                break;
            case 3:
                cout << "Enter the value to insert: ";
                cin >> value;
                cout << "Enter the position: ";
                cin >> position;
                list.insertAfterPosition(value, position);
                break;
            case 4:
                list.deleteFromBeginning();
                break;
            case 5:
                list.deleteFromEnd();
                break;
            case 6:
                cout << "Enter the position: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            case 7:
                list.display();
                break;
            case 8:
                cout << "Exiting the program." << endl;
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

