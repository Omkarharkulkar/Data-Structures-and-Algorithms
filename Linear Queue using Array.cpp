#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element.\n";
            return;
        }

        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        cout << "Element " << value << " enqueued.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element.\n";
            return;
        }

        cout << "Element " << arr[front] << " dequeued.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Elements in the queue: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

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

