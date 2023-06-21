#include <iostream>
#include <deque>
using namespace std;

void addCustomerToFront(deque<string>& queue) {
    string customer;
    cout << "Enter the name of the customer to add at the front: ";
    cin >> customer;
    queue.push_front(customer);
    cout << "Customer \"" << customer << "\" added to the front of the queue." << endl;
}

void addCustomerToBack(deque<string>& queue) {
    string customer;
    cout << "Enter the name of the customer to add at the back: ";
    cin >> customer;
    queue.push_back(customer);
    cout << "Customer \"" << customer << "\" added to the back of the queue." << endl;
}

void serveCustomerFromFront(deque<string>& queue) {
    if (!queue.empty()) {
        string customer = queue.front();
        queue.pop_front();
        cout << "Serving customer \"" << customer << "\" from the front of the queue." << endl;
    } else {
        cout << "No customers in the queue." << endl;
    }
}

void serveCustomerFromBack(deque<string>& queue) {
    if (!queue.empty()) {
        string customer = queue.back();
        queue.pop_back();
        cout << "Serving customer \"" << customer << "\" from the back of the queue." << endl;
    } else {
        cout << "No customers in the queue." << endl;
    }
}

void displayQueue(const deque<string>& queue) {
    cout << "Customers in the queue: ";
    for (deque<string>::const_iterator it = queue.begin(); it != queue.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    deque<string> customerQueue;

    int choice;
    while (true) {
        cout << "\n---- Shopping Mall Queue Management ----" << endl;
        cout << "1. Add customer at the front" << endl;
        cout << "2. Add customer at the back" << endl;
        cout << "3. Serve customer from the front" << endl;
        cout << "4. Serve customer from the back" << endl;
        cout << "5. Display the queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCustomerToFront(customerQueue);
                break;
            case 2:
                addCustomerToBack(customerQueue);
                break;
            case 3:
                serveCustomerFromFront(customerQueue);
                break;
            case 4:
                serveCustomerFromBack(customerQueue);
                break;
            case 5:
                displayQueue(customerQueue);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

