#include <iostream>
#include <iomanip> // For formatting output
#include <cstring>
using namespace std;

class Node {
public:
    char item[50];    // Item name
    int quantity;     // Quantity of the item
    float cost;       // Cost of the item
    Node* next;       // Pointer to the next node
    Node* prev;       // Pointer to the previous node
};

class InputRestrictedDeque {
public:
    Node* front;
    Node* rear;

    InputRestrictedDeque() {
        front = rear = NULL;
    }

    void addItemToCart();  // EnqueueRear
    void removeItemFromFront(); // DequeueFront
    void displayCart();
};

class OutputRestrictedDeque {
public:
    Node* front;
    Node* rear;

    OutputRestrictedDeque() {
        front = rear = NULL;
    }

    void addItemToCartRear(); // EnqueueRear
    void addItemToCartFront(); // EnqueueFront
    void removeItemFromFront(); // DequeueFront
    void displayCart();
};

void InputRestrictedDeque::addItemToCart() {
    Node* temp = new Node;
    cout << "Enter the item name: ";
    cin.ignore();
    cin.getline(temp->item, 50);
    cout << "Enter the quantity: ";
    cin >> temp->quantity;
    cout << "Enter the cost per item: ";
    cin >> temp->cost;

    temp->next = NULL;
    temp->prev = NULL;

    if (!rear) {
        rear = front = temp;
    } else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    cout << "Item added to the cart successfully.\n";
}

void InputRestrictedDeque::removeItemFromFront() {
    if (!front) {
        cout << "The cart is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Removing item: " << temp->item << " (Quantity: " << temp->quantity << ", Cost: " << temp->cost << ")\n";
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    delete temp;
}

void InputRestrictedDeque::displayCart() {
    if (!front) {
        cout << "The cart is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "\nShopping Cart (Input Restricted):\n";
    cout << setw(20) << "Item Name" << setw(15) << "Quantity" << setw(15) << "Cost" << setw(15) << "Total\n";
    cout << string(65, '-') << endl;

    while (temp) {
        cout << setw(20) << temp->item << setw(15) << temp->quantity << setw(15) << temp->cost 
             << setw(15) << temp->quantity * temp->cost << endl;
        temp = temp->next;
    }
}

void OutputRestrictedDeque::addItemToCartRear() {
    Node* temp = new Node;
    cout << "Enter the item name: ";
    cin.ignore();
    cin.getline(temp->item, 50);
    cout << "Enter the quantity: ";
    cin >> temp->quantity;
    cout << "Enter the cost per item: ";
    cin >> temp->cost;

    temp->next = NULL;
    temp->prev = NULL;

    if (!rear) {
        rear = front = temp;
    } else {
        rear->next = temp;
        temp->prev = rear;
        rear = temp;
    }
    cout << "Item added to the cart successfully.\n";
}

void OutputRestrictedDeque::addItemToCartFront() {
    Node* temp = new Node;
    cout << "Enter the item name: ";
    cin.ignore();
    cin.getline(temp->item, 50);
    cout << "Enter the quantity: ";
    cin >> temp->quantity;
    cout << "Enter the cost per item: ";
    cin >> temp->cost;

    temp->next = NULL;
    temp->prev = NULL;

    if (!front) {
        front = rear = temp;
    } else {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
    cout << "Item added to the cart successfully.\n";
}

void OutputRestrictedDeque::removeItemFromFront() {
    if (!front) {
        cout << "The cart is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Removing item: " << temp->item << " (Quantity: " << temp->quantity << ", Cost: " << temp->cost << ")\n";
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }
    delete temp;
}

void OutputRestrictedDeque::displayCart() {
    if (!front) {
        cout << "The cart is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "\nShopping Cart (Output Restricted):\n";
    cout << setw(20) << "Item Name" << setw(15) << "Quantity" << setw(15) << "Cost" << setw(15) << "Total\n";
    cout << string(65, '-') << endl;

    while (temp) {
        cout << setw(20) << temp->item << setw(15) << temp->quantity << setw(15) << temp->cost 
             << setw(15) << temp->quantity * temp->cost << endl;
        temp = temp->next;
    }
}

int main() {
    InputRestrictedDeque inputDeque;
    OutputRestrictedDeque outputDeque;
    int choice;

    while (true) {
        cout << "\nShopping Mall Operations:\n";
        cout << "1. Add Item to Cart (Input Restricted - Rear)\n";
        cout << "2. Remove Item from Cart (Input Restricted - Front)\n";
        cout << "3. View Cart (Input Restricted)\n";
        cout << "4. Add Item to Cart (Output Restricted - Rear)\n";
        cout << "5. Add Item to Cart (Output Restricted - Front)\n";
        cout << "6. Remove Item from Cart (Output Restricted - Front)\n";
        cout << "7. View Cart (Output Restricted)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            inputDeque.addItemToCart();
            break;
        case 2:
            inputDeque.removeItemFromFront();
            break;
        case 3:
            inputDeque.displayCart();
            break;
        case 4:
            outputDeque.addItemToCartRear();
            break;
        case 5:
            outputDeque.addItemToCartFront();
            break;
        case 6:
            outputDeque.removeItemFromFront();
            break;
        case 7:
            outputDeque.displayCart();
            break;
        case 8:
            cout << "Exiting the program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}

