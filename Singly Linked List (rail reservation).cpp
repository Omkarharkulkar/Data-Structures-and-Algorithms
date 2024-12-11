#include <iostream>
#include <string>
using namespace std;

class Passenger {
public:
    int id;
    string name;
    string destination;
    Passenger* next;

    Passenger(int id, string name, string destination) {
        this->id = id;
        this->name = name;
        this->destination = destination;
        this->next = NULL; // Changed from nullptr to NULL
    }
};

class RailwayReservation {
private:
    Passenger* head;

public:
    RailwayReservation() {
        head = NULL; // Changed from nullptr to NULL
    }

    void insertPassenger();
    void updatePassenger();
    void searchPassenger();
    void deletePassenger();
    void sortPassengers();
    void listPassengers();
    Passenger* createPassenger(int id, string name, string destination);
};

Passenger* RailwayReservation::createPassenger(int id, string name, string destination) {
    return new Passenger(id, name, destination);
}

void RailwayReservation::insertPassenger() {
    int id;
    string name, destination;
    cout << "Enter Passenger ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Passenger Name: ";
    getline(cin, name);
    cout << "Enter Destination: ";
    getline(cin, destination);

    Passenger* newPassenger = createPassenger(id, name, destination);

    if (head == NULL) {
        head = newPassenger;
    } else {
        Passenger* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newPassenger;
    }
    cout << "Passenger added successfully.\n";
}

void RailwayReservation::updatePassenger() {
    int id, found = 0;
    cout << "Enter Passenger ID to update: ";
    cin >> id;

    Passenger* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            cout << "Enter new Passenger Name: ";
            cin.ignore();
            getline(cin, temp->name);
            cout << "Enter new Destination: ";
            getline(cin, temp->destination);
            cout << "Passenger details updated successfully.\n";
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Passenger ID not found.\n";
    }
}

void RailwayReservation::searchPassenger() {
    int id, found = 0;
    cout << "Enter Passenger ID to search: ";
    cin >> id;

    Passenger* temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            found = 1;
            cout << "Passenger Found:\n";
            cout << "ID: " << temp->id << ", Name: " << temp->name << ", Destination: " << temp->destination << endl;
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Passenger ID not found.\n";
    }
}

void RailwayReservation::deletePassenger() {
    int id;
    cout << "Enter Passenger ID to delete: ";
    cin >> id;

    if (head == NULL) {
        cout << "No passengers to delete.\n";
        return;
    }

    if (head->id == id) {
        Passenger* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Passenger deleted successfully.\n";
        return;
    }

    Passenger* temp = head;
    Passenger* prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Passenger ID not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Passenger deleted successfully.\n";
}

void RailwayReservation::sortPassengers() {
    if (head == NULL || head->next == NULL) {
        cout << "List is too short to sort.\n";
        return;
    }

    Passenger* i;
    Passenger* j;
    int tempId;
    string tempName, tempDestination;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->id > j->id) {
                tempId = i->id;
                tempName = i->name;
                tempDestination = i->destination;

                i->id = j->id;
                i->name = j->name;
                i->destination = j->destination;

                j->id = tempId;
                j->name = tempName;
                j->destination = tempDestination;
            }
        }
    }
    cout << "Passengers sorted by ID.\n";
}

void RailwayReservation::listPassengers() {
    if (head == NULL) {
        cout << "No passengers in the list.\n";
        return;
    }

    Passenger* temp = head;
    cout << "\nPassenger List:\n";
    cout << "ID\tName\t\tDestination\n";
    while (temp != NULL) {
        cout << temp->id << "\t" << temp->name << "\t" << temp->destination << endl;
        temp = temp->next;
    }
}

int main() {
    RailwayReservation system;
    int choice;

    while (true) {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Add Passenger\n";
        cout << "2. Update Passenger\n";
        cout << "3. Search Passenger\n";
        cout << "4. Delete Passenger\n";
        cout << "5. Sort Passengers\n";
        cout << "6. List Passengers\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.insertPassenger();
                break;
            case 2:
                system.updatePassenger();
                break;
            case 3:
                system.searchPassenger();
                break;
            case 4:
                system.deletePassenger();
                break;
            case 5:
                system.sortPassengers();
                break;
            case 6:
                system.listPassengers();
                break;
            case 7:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

