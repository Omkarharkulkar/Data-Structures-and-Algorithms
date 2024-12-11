#include <iostream>
using namespace std;

// Node structure for the circular linked list
struct Node {
    string passengerName;
    int seatNumber;
    Node* next;
};

// Class for the circular linked list representing a train
class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() : head(NULL) {}

    // Function to add a passenger to the train
    void addPassenger(const string& name, int seat) {
        Node* newNode = new Node;
        newNode->passengerName = name;
        newNode->seatNumber = seat;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }

        cout << "Reservation successful. Passenger " << name << " added to seat " << seat << "." << endl;
    }

    // Function to cancel a reservation
    void cancelReservation(int seat) {
        if (head == NULL) {
            cout << "No reservations to cancel." << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        do {
            if (current->seatNumber == seat) {
                if (prev == NULL) {
                    if (current->next == head) {
                        delete current;
                        head = NULL;
                    } else {
                        Node* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        head = head->next;
                        delete current;
                    }
                    cout << "Reservation canceled for seat " << seat << "." << endl;
                    return;
                } else {
                    prev->next = current->next;
                    delete current;
                    cout << "Reservation canceled for seat " << seat << "." << endl;
                    return;
                }
            }

            prev = current;
            current = current->next;

        } while (current != head);

        cout << "No reservation found for seat " << seat << "." << endl;
    }

    // Function to display the passenger list
    void displayPassengerList() {
        if (head == NULL) {
            cout << "No reservations yet." << endl;
            return;
        }

        cout << "Passenger List:" << endl;
        Node* current = head;

        do {
            cout << "Seat " << current->seatNumber << ": " << current->passengerName << endl;
            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList train;

    int n;  // Number of passengers to add

    // Input number of passengers
    cout << "Enter the number of passengers: ";
    cin >> n;

    // Add passengers to the train
    for (int i = 0; i < n; ++i) {
        string name;
        int seat;

        cout << "Enter passenger " << i + 1 << "'s name: ";
        cin >> name;
        cout << "Enter seat number for " << name << ": ";
        cin >> seat;

        train.addPassenger(name, seat);
    }

    // Display passenger list
    train.displayPassengerList();

    // Cancel a reservation
    int seatToCancel;
    cout << "Enter the seat number to cancel the reservation: ";
    cin >> seatToCancel;
    train.cancelReservation(seatToCancel);

    // Display updated passenger list
    train.displayPassengerList();

    return 0;
}

