#include <iostream>
#include <string>
using namespace std;

class Customer {
    // Defining a class to represent each customer
public:
    int mb;            // Mobile number
    string name;       // Name of the customer
    string address;    // Address of the customer
    string email;      // Email of the customer

    // Function to read customer details
    void read() {
        cout << "Enter customer mobile number: ";
        cin >> mb;
        cin.ignore();  // To clear the newline left in buffer after reading an integer
        cout << "Enter customer name: ";
        getline(cin, name);  // To allow spaces in name
        cout << "Enter customer address: ";
        getline(cin, address);
        cout << "Enter customer email: ";
        getline(cin, email);
    }

    // Function to display customer details
    void display() const {
        cout << "Customer Name: " << name << endl;
        cout << "Mobile no.: " << mb << endl;
        cout << "Address: " << address << endl;
        cout << "Email: " << email << endl;
    }

    // Function to update customer details
    void update() {
        int ch;
        cout << "Enter 1 to change the customer name, 2 to change mobile number, "
             << "3 to change address, or 4 to change email: ";
        cin >> ch;
        cin.ignore();  // To clear newline from input buffer

        switch (ch) {
            case 1:
                cout << "Enter updated customer name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter updated mobile no.: ";
                cin >> mb;
                cin.ignore();  // To clear newline
                break;
            case 3:
                cout << "Enter updated address: ";
                getline(cin, address);
                break;
            case 4:
                cout << "Enter updated email: ";
                getline(cin, email);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    // Function to search for a customer by mobile number
    bool search(int rn) const {
        return mb == rn;
    }

    // Comparison function for sorting based on mobile number
    bool compare(const Customer& s) const {
        return mb > s.mb;
    }
};

int main() {
    Customer s[20];  // Array to hold up to 20 customers
    int ch, i, n = 0;  // Menu choice, loop counter, and customer count

    cout << "<##### Welcome to the customer database #####>\n" << endl;

    do {
        cout << "1. Read the data\n"
             << "2. Display the data\n"
             << "3. Insert the data\n"
             << "4. Delete the data\n"
             << "5. Update the data\n"
             << "6. Bubble sort the data\n"
             << "7. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                // Read customer data
                cout << "Enter the number of customers: ";
                cin >> n;
                cin.ignore();  // To ignore the newline character from previous input
                for (i = 0; i < n; i++) {
                    cout << "Enter details for customer " << (i + 1) << ":\n";
                    s[i].read();
                }
                break;
            }

            case 2: {
                // Display customer data
                if (n == 0) {
                    cout << "No customer data available.\n";
                } else {
                    for (i = 0; i < n; i++) {
                        s[i].display();
                        cout << "----------------------------\n";
                    }
                }
                break;
            }

            case 3: {
                // Insert customer data at a specific position
                int pos;
                cout << "Enter the position at which to insert: ";
                cin >> pos;
                if (pos >= 1 && pos <= n + 1) {
                    for (i = n - 1; i >= pos - 1; i--) {
                        s[i + 1] = s[i];
                    }
                    n++;
                    cout << "Enter details of new customer:\n";
                    s[pos - 1].read();
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            }

            case 4: {
                // Delete customer data from a specific position
                int pos1;
                cout << "Enter position to delete: ";
                cin >> pos1;
                if (n <= 0) {
                    cout << "No data to delete.\n";
                } else if (pos1 >= 1 && pos1 <= n) {
                    for (i = pos1 - 1; i < n - 1; i++) {
                        s[i] = s[i + 1];
                    }
                    n--;
                    cout << "Customer details at position " << pos1 << " deleted.\n";
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            }

            case 5: {
                // Update customer data
                int rn, flag = 0;
                cout << "Enter the mobile number to update: ";
                cin >> rn;
                for (i = 0; i < n; i++) {
                    if (s[i].search(rn)) {
                        cout << "Record found.\n";
                        s[i].update();
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    cout << "Record not found.\n";
                }
                break;
            }

            case 6: {
                // Sort the customer data by mobile number using Bubble Sort
                Customer temp;
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (s[j].compare(s[j + 1])) {
                            temp = s[j];
                            s[j] = s[j + 1];
                            s[j + 1] = temp;
                        }
                    }
                }
                cout << "Data sorted by mobile number.\n";
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 7);

    return 0;
}
