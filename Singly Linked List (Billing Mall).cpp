#include <iostream>
#include <string>
#include <iomanip> // For formatted output
using namespace std;

class Item {
public:
    int id;
    string name;
    double price;
    int quantity;
    Item* next;

    Item(int id, string name, double price, int quantity) {
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
        this->next = NULL;
    }
};

class MallBilling {
private:
    Item* head;

public:
    MallBilling() {
        head = NULL;
    }

    void addItem();
    void updateItem();
    void searchItem();
    void deleteItem();
    void sortItems();
    void displayBill();
    void listItems();
    Item* createItem(int id, string name, double price, int quantity);
};

Item* MallBilling::createItem(int id, string name, double price, int quantity) {
    return new Item(id, name, price, quantity);
}

void MallBilling::addItem() {
    int id, quantity;
    string name;
    double price;

    cout << "Enter Item ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Item Name: ";
    getline(cin, name);
    cout << "Enter Item Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;

    Item* newItem = createItem(id, name, price, quantity);

    if (head == NULL) {
        head = newItem;
    } else {
        Item* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
    cout << "Item added successfully.\n";
}

void MallBilling::updateItem() {
    int id, found = 0;
    cout << "Enter Item ID to update: ";
    cin >> id;

    Item* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            cout << "Enter new Item Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new Price: ";
            cin >> temp->price;
            cout << "Enter new Quantity: ";
            cin >> temp->quantity;
            cout << "Item details updated successfully.\n";
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Item ID not found.\n";
    }
}

void MallBilling::searchItem() {
    int id, found = 0;
    cout << "Enter Item ID to search: ";
    cin >> id;

    Item* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            cout << "\nItem Found:\n";
            cout << "ID: " << temp->id << ", Name: " << temp->name
                 << ", Price: " << temp->price << ", Quantity: " << temp->quantity << endl;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Item ID not found.\n";
    }
}

void MallBilling::deleteItem() {
    int id;
    cout << "Enter Item ID to delete: ";
    cin >> id;

    if (head == NULL) {
        cout << "No items to delete.\n";
        return;
    }

    if (head->id == id) {
        Item* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Item deleted successfully.\n";
        return;
    }

    Item* temp = head;
    Item* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item ID not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Item deleted successfully.\n";
}

void MallBilling::sortItems() {
    if (head == NULL || head->next == NULL) {
        cout << "List is too short to sort.\n";
        return;
    }

    Item* i;
    Item* j;
    int tempId, tempQuantity;
    string tempName;
    double tempPrice;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->price > j->price) { // Sort by price
                tempId = i->id;
                tempName = i->name;
                tempPrice = i->price;
                tempQuantity = i->quantity;

                i->id = j->id;
                i->name = j->name;
                i->price = j->price;
                i->quantity = j->quantity;

                j->id = tempId;
                j->name = tempName;
                j->price = tempPrice;
                j->quantity = tempQuantity;
            }
        }
    }
    cout << "Items sorted by price.\n";
}

void MallBilling::listItems() {
    if (head == NULL) {
        cout << "No items in the list.\n";
        return;
    }

    Item* temp = head;
    cout << "\nItem List:\n";
    cout << "ID\tName\t\tPrice\tQuantity\n";
    while (temp != NULL) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->price << "\t" << temp->quantity << endl;
        temp = temp->next;
    }
}

void MallBilling::displayBill() {
    if (head == NULL) {
        cout << "No items to display. Bill is empty.\n";
        return;
    }

    Item* temp = head;
    double total = 0;
    cout << "\n--- Final Bill ---\n";
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price"
         << setw(10) << "Quantity" << setw(15) << "Total Price" << endl;

    while (temp != NULL) {
        double itemTotal = temp->price * temp->quantity;
        total += itemTotal;
        cout << left << setw(10) << temp->id << setw(20) << temp->name << setw(10)
             << temp->price << setw(10) << temp->quantity << setw(15) << itemTotal << endl;
        temp = temp->next;
    }
    cout << "\nGrand Total: " << total << "\n";
}

int main() {
    MallBilling system;
    int choice;

    while (true) {
        cout << "\n--- Mall Billing System ---\n";
        cout << "1. Add Item\n";
        cout << "2. Update Item\n";
        cout << "3. Search Item\n";
        cout << "4. Delete Item\n";
        cout << "5. Sort Items by Price\n";
        cout << "6. List Items\n";
        cout << "7. Display Bill\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.addItem();
                break;
            case 2:
                system.updateItem();
                break;
            case 3:
                system.searchItem();
                break;
            case 4:
                system.deleteItem();
                break;
            case 5:
                system.sortItems();
                break;
            case 6:
                system.listItems();
                break;
            case 7:
                system.displayBill();
                break;
            case 8:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

