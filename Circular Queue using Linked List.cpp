#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() {
        rear = NULL;
    }

    bool isEmpty() {
        return (rear == NULL);
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            newNode->next = newNode;
            rear = newNode;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Element " << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }

        Node* front = rear->next;
        cout << "Element " << front->data << " dequeued.\n";

        if (front == rear) {
            rear = NULL;
        } else {
            rear->next = front->next;
        }

        delete front;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Elements in the queue: ";
        Node* current = rear->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != rear->next);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;

    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue element\n";
        cout << "2. Dequeue element\n";
        cout << "3. Display the queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to be enqueued: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exiting the program.\n";
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

