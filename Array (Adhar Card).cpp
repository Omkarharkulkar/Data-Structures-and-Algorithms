#include <iostream>
#include <string>
using namespace std;

class AadhaarCard {
    // Class to represent Aadhaar Card details
public:
    string aadhaarNumber;    // Aadhaar number (12-digit unique number)
    string name;             // Name of the individual
    string dob;              // Date of birth (as string, you can use a Date class for validation)
    string gender;           // Gender
    string address;          // Address
    string mobile;           // Mobile number
    string email;            // Email address (optional)

    // Function to read Aadhaar Card details
    void read() {
        cout << "Enter Aadhaar number (12 digits): ";
        cin >> aadhaarNumber;
        cin.ignore();  // Clear the newline character left in buffer

        cout << "Enter full name: ";
        getline(cin, name);

        cout << "Enter date of birth (DD/MM/YYYY): ";
        getline(cin, dob);

        cout << "Enter gender (Male/Female/Other): ";
        getline(cin, gender);

        cout << "Enter address: ";
        getline(cin, address);

        cout << "Enter mobile number: ";
        getline(cin, mobile);

        cout << "Enter email address (optional): ";
        getline(cin, email);
    }

    // Function to display Aadhaar Card details
    void display() const {
        cout << "Aadhaar Number: " << aadhaarNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Mobile No.: " << mobile << endl;
        cout << "Email: " << (email.empty() ? "Not provided" : email) << endl;
    }

    // Function to update Aadhaar Card details
    void update() {
        int ch;
        cout << "Enter 1 to change the full name, 2 to change date of birth, "
             << "3 to change gender, 4 to change address, "
             << "5 to change mobile number, or 6 to change email address: ";
        cin >> ch;
        cin.ignore();  // To clear newline from buffer

        switch (ch) {
            case 1:
                cout << "Enter updated full name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter updated date of birth (DD/MM/YYYY): ";
                getline(cin, dob);
                break;
            case 3:
                cout << "Enter updated gender (Male/Female/Other): ";
                getline(cin, gender);
                break;
            case 4:
                cout << "Enter updated address: ";
                getline(cin, address);
                break;
            case 5:
                cout << "Enter updated mobile number: ";
                getline(cin, mobile);
                break;
            case 6:
                cout << "Enter updated email address: ";
                getline(cin, email);
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    // Function to search for an Aadhaar record by Aadhaar number
    bool search(const string& aadhaarNo) const {
        return aadhaarNumber == aadhaarNo;
    }

    // Comparison function to sort records based on Aadhaar number (lexicographically)
    bool compare(const AadhaarCard& other) const {
        return aadhaarNumber > other.aadhaarNumber;
    }
};

int main() {
    AadhaarCard records[20];  // Array to hold up to 20 Aadhaar records
    int ch, i, n = 0;         // Menu choice, loop counter, and number of records

    cout << "<##### Welcome to the Aadhaar Card Management System #####>\n" << endl;

    do {
        cout << "1. Read Aadhaar details\n"
             << "2. Display Aadhaar details\n"
             << "3. Insert new Aadhaar record\n"
             << "4. Delete Aadhaar record\n"
             << "5. Update Aadhaar record\n"
             << "6. Sort Aadhaar records\n"
             << "7. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                // Read Aadhaar Card details for n individuals
                cout << "Enter the number of Aadhaar records: ";
                cin >> n;
                cin.ignore();  // To ignore the newline character left by previous input
                for (i = 0; i < n; i++) {
                    cout << "Enter details for Aadhaar record " << (i + 1) << ":\n";
                    records[i].read();
                }
                break;
            }

            case 2: {
                // Display Aadhaar Card details
                if (n == 0) {
                    cout << "No Aadhaar records available.\n";
                } else {
                    for (i = 0; i < n; i++) {
                        records[i].display();
                        cout << "----------------------------\n";
                    }
                }
                break;
            }

            case 3: {
                // Insert a new Aadhaar record at a specific position
                int pos;
                cout << "Enter the position at which to insert the record: ";
                cin >> pos;
                if (pos >= 1 && pos <= n + 1) {
                    for (i = n - 1; i >= pos - 1; i--) {
                        records[i + 1] = records[i];
                    }
                    n++;
                    cout << "Enter details for the new Aadhaar record:\n";
                    records[pos - 1].read();
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            }

            case 4: {
                // Delete an Aadhaar record at a specific position
                int pos1;
                cout << "Enter position to delete the Aadhaar record: ";
                cin >> pos1;
                if (n <= 0) {
                    cout << "No records to delete.\n";
                } else if (pos1 >= 1 && pos1 <= n) {
                    for (i = pos1 - 1; i < n - 1; i++) {
                        records[i] = records[i + 1];
                    }
                    n--;
                    cout << "Aadhaar record at position " << pos1 << " deleted.\n";
                } else {
                    cout << "Invalid position.\n";
                }
                break;
            }

            case 5: {
                // Update Aadhaar record by Aadhaar number
                string aadhaarNo;
                int flag = 0;
                cout << "Enter the Aadhaar number to update: ";
                cin >> aadhaarNo;
                for (i = 0; i < n; i++) {
                    if (records[i].search(aadhaarNo)) {
                        cout << "Record found.\n";
                        records[i].update();
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
                // Sort Aadhaar records by Aadhaar number
                AadhaarCard temp;
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (records[j].compare(records[j + 1])) {
                            temp = records[j];
                            records[j] = records[j + 1];
                            records[j + 1] = temp;
                        }
                    }
                }
                cout << "Aadhaar records sorted by Aadhaar number.\n";
                break;
            }

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (ch != 7);

    return 0;
}

