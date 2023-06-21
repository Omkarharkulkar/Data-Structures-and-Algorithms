#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

class Deque 
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Deque() 
	{
        front = -1;
        rear = -1;
    }

    bool isEmpty() 
	{
        return (front == -1 && rear == -1);
    }

    bool isFull() 
	{
        return ((front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1)));
    }

    void insertFront(int value) 
	{
        if (isFull()) 
		{
            cout << "Deque is full. Cannot insert element at the front.\n";
            return;
        }

        if (isEmpty()) 
		{
            front = rear = 0;
        } 
		else if (front == 0) 
		{
            front = MAX_SIZE - 1;
        } 
		else 
		{
            front--;
        }

        arr[front] = value;
        cout << "Element " << value << " inserted at the front.\n";
    }

    void insertRear(int value) 
	{
        if (isFull()) 
		{
            cout << "Deque is full. Cannot insert element at the rear.\n";
            return;
        }

        if (isEmpty()) 
		{
            front = rear = 0;
        } 
		else if (rear == MAX_SIZE - 1) 
		{
            rear = 0;
        } 
		else 
		{
            rear++;
        }

        arr[rear] = value;
        cout << "Element " << value << " inserted at the rear.\n";
    }

    void deleteFront() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty. Cannot delete element from the front.\n";
            return;
        }

        cout << "Element " << arr[front] << " deleted from the front.\n";

        if (front == rear) 
		{
            front = rear = -1;
        } 
		else if (front == MAX_SIZE - 1) 
		{
            front = 0;
        } 
		else 
		{
            front++;
        }
    }

    void deleteRear() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty. Cannot delete element from the rear.\n";
            return;
        }

        cout << "Element " << arr[rear] << " deleted from the rear.\n";

        if (front == rear) 
		{
            front = rear = -1;
        } 
		else if (rear == 0) 
		{
            rear = MAX_SIZE - 1;
        } 
		else 
		{
            rear--;
        }
    }

    void display() 
	{
        if (isEmpty()) 
		{
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Elements in the deque: ";
        int i = front;
        while (true) 
		{
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

int main() 
{
    Deque deque;

    int choice, value;

    while (true) 
	{
        cout << "\nMenu:\n";
        cout << "1. Insert element at the front\n";
        cout << "2. Insert element at the rear\n";
        cout << "3. Delete element from the front\n";
        cout << "4. Delete element from the rear\n";
        cout << "5. Display the deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "Enter the value to be inserted at the front: ";
                cin >> value;
                deque.insertFront(value);
                break;
            case 2:
                cout << "Enter the value to be inserted at the rear: ";
                cin >> value;
                deque.insertRear(value);
                break;
            case 3:
                deque.deleteFront();
                break;
            case 4:
                deque.deleteRear();
                break;
            case 5:
                deque.display();
                break;
            case 6:
                cout << "Exiting the program.\n";
                exit(0);
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}

