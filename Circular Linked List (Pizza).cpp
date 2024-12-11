#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int orderid;
    string pizzaname;
    int quantity;
    int price;
    Node* next;
};

class PizzaOrderManagement {
    Node* head;
    int choice;

public:
    // Constructor
    PizzaOrderManagement() {
        head = NULL;
    }

    void create();
    void display();
    void insert_last();
    void delete_order(int orderid);
    void search_order(int orderid);
};

// Create pizza orders
void PizzaOrderManagement::create() {
    do {
        Node* temp = new Node;
        cout << "Enter Order ID: ";
        cin >> temp->orderid;
        cout << "Enter Pizza Name: ";
        cin >> temp->pizzaname;
        cout << "Enter Pizza Quantity: ";
        cin >> temp->quantity;
        cout << "Enter Pizza Price: ";
        cin >> temp->price;
        temp->next = NULL;

        if (!head) {
            head = temp;
            head->next = head; // Circular link
        } else {
            Node* ptr = head;
            while (ptr->next != head) {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = head;
        }

        cout << "Do you want to insert more? (1: Yes, 0: No): ";
        cin >> choice;
    } while (choice != 0);
}

// Display all orders
void PizzaOrderManagement::display() {
    if (!head) {
        cout << "No orders found!" << endl;
        return;
    }

    Node* ptr = head;
    cout << "\nPizza Orders:\n";
    do {
        cout << "ORDER ID: " << ptr->orderid << endl;
        cout << "PIZZA NAME: " << ptr->pizzaname << endl;
        cout << "PIZZA QUANTITY: " << ptr->quantity << endl;
        cout << "PIZZA PRICE: " << ptr->price << endl;
        cout << "----------------------------------------\n";
        ptr = ptr->next;
    } while (ptr != head);
}

// Insert order at the end
void PizzaOrderManagement::insert_last() {
    Node* temp = new Node;
    cout << "Enter Order ID: ";
    cin >> temp->orderid;
    cout << "Enter Pizza Name: ";
    cin >> temp->pizzaname;
    cout << "Enter Pizza Quantity: ";
    cin >> temp->quantity;
    cout << "Enter Pizza Price: ";
    cin >> temp->price;
    temp->next = NULL;

    if (!head) {
        head = temp;
        head->next = head;
    } else {
        Node* ptr = head;
        while (ptr->next != head) {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = head;
    }
    cout << "Order added successfully!" << endl;
}

// Delete an order by order ID
void PizzaOrderManagement::delete_order(int orderid) {
    if (!head) {
        cout << "No orders to delete!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // Check if the head node is to be deleted
    if (temp->orderid == orderid) {
        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Order deleted successfully!" << endl;
        return;
    }

    // Traverse the list to find the order
    do {
        prev = temp;
        temp = temp->next;
        if (temp->orderid == orderid) {
            prev->next = temp->next;
            delete temp;
            cout << "Order deleted successfully!" << endl;
            return;
        }
    } while (temp != head);

    cout << "Order not found!" << endl;
}

// Search for an order by order ID
void PizzaOrderManagement::search_order(int orderid) {
    if (!head) {
        cout << "No orders found!" << endl;
        return;
    }

    Node* ptr = head;
    do {
        if (ptr->orderid == orderid) {
            cout << "ORDER FOUND!\n";
            cout << "ORDER ID: " << ptr->orderid << endl;
            cout << "PIZZA NAME: " << ptr->pizzaname << endl;
            cout << "PIZZA QUANTITY: " << ptr->quantity << endl;
            cout << "PIZZA PRICE: " << ptr->price << endl;
            return;
        }
        ptr = ptr->next;
    } while (ptr != head);

    cout << "Order not found!" << endl;
}

// Main function
int main() {
    PizzaOrderManagement p1;
    int choice;

    do {
        cout << "\nPIZZA ORDER MANAGEMENT\n";
        cout << "1. Create Pizza Order\n";
        cout << "2. Display Pizza Orders\n";
        cout << "3. Insert Last Pizza Order\n";
        cout << "4. Delete Pizza Order\n";
        cout << "5. Search Pizza Order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p1.create();
                break;
            case 2:
                p1.display();
                break;
            case 3:
                p1.insert_last();
                break;
            case 4: {
                int orderid;
                cout << "Enter the order ID to delete: ";
                cin >> orderid;
                p1.delete_order(orderid);
                break;
            }
            case 5: {
                int orderid;
                cout << "Enter the order ID to search: ";
                cin >> orderid;
                p1.search_order(orderid);
                break;
            }
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

