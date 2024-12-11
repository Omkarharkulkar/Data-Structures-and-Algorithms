#include <iostream>
#include <string>
using namespace std;

// Class to represent a Book
class Book {
public:
    string isbn;           // ISBN of the book
    string title;          // Title of the book
    string author;         // Author of the book
    string publisher;      // Publisher of the book
    int year;              // Year of publication
    int quantity;          // Number of copies available

    // Function to read Book details
    void read() {
        cout << "Enter ISBN (unique identifier): ";
        cin >> isbn;
        cin.ignore();  // To clear the newline character from the buffer

        cout << "Enter title of the book: ";
        getline(cin, title);

        cout << "Enter author of the book: ";
        getline(cin, author);

        cout << "Enter publisher of the book: ";
        getline(cin, publisher);

        cout << "Enter year of publication: ";
        cin >> year;

        cout << "Enter quantity of the book: ";
        cin >> quantity;
        cin.ignore();  // To clear any remaining newline characters
    }

    // Function to display Book details
    void display() const {
        cout << "ISBN: " << isbn << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Year of Publication: " << year << endl;
        cout << "Quantity Available: " << quantity << endl;
    }

    // Function to update Book details
    void update() {
        int choice;
        cout << "Enter 1 to update title, 2 to update author, "
             << "3 to update publisher, 4 to update year, "
             << "5 to update quantity: ";
        cin >> choice;
        cin.ignore();  // To clear the newline character

        switch (choice) {
            case 1:
                cout << "Enter updated title: ";
                getline(cin, title);
                break;
            case 2:
                cout << "Enter updated author: ";
                getline(cin, author);
                break;
            case 3:
                cout << "Enter updated publisher: ";
                getline(cin, publisher);
                break;
            case 4:
                cout << "Enter updated year of publication: ";
                cin >> year;
                break;
            case 5:
                cout << "Enter updated quantity: ";
                cin >> quantity;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    // Function to compare books based on Title (for sorting)
    bool compareTitle(const Book& other) const {
        return title < other.title;
    }

    // Function to compare books based on Author (for sorting)
    bool compareAuthor(const Book& other) const {
        return author < other.author;
    }
};

// Class to represent a Library Member
class Member {
public:
    string memberId;       // Member's unique ID
    string name;           // Member's name
    string address;        // Member's address
    string phoneNumber;    // Member's phone number
    string email;          // Member's email address

    // Function to read Member details
    void read() {
        cout << "Enter member ID: ";
        cin >> memberId;
        cin.ignore();  // To clear the newline character

        cout << "Enter member's name: ";
        getline(cin, name);

        cout << "Enter member's address: ";
        getline(cin, address);

        cout << "Enter member's phone number: ";
        getline(cin, phoneNumber);

        cout << "Enter member's email address: ";
        getline(cin, email);
    }

    // Function to display Member details
    void display() const {
        cout << "Member ID: " << memberId << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

// Main function for Library Management System
int main() {
    const int MAX_BOOKS = 20;       // Maximum number of books the library can hold
    const int MAX_MEMBERS = 20;     // Maximum number of members
    Book books[MAX_BOOKS];          // Array to hold books
    Member members[MAX_MEMBERS];    // Array to hold library members
    int bookCount = 0;              // Number of books in the library
    int memberCount = 0;            // Number of members registered
    int choice;

    cout << "<##### Welcome to the Library Management System #####>\n" << endl;

    do {
        cout << "1. Add new Book\n"
             << "2. Display Books\n"
             << "3. Update Book Details\n"
             << "4. Delete Book\n"
             << "5. Sort Books\n"
             << "6. Add Library Member\n"
             << "7. Display Members\n"
             << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // Add new Book
                if (bookCount < MAX_BOOKS) {
                    cout << "Enter details for Book " << (bookCount + 1) << ":\n";
                    books[bookCount].read();
                    bookCount++;
                } else {
                    cout << "Library is full. Cannot add more books.\n";
                }
                break;
            }

            case 2: { // Display Books
                if (bookCount == 0) {
                    cout << "No books available in the library.\n";
                } else {
                    for (int i = 0; i < bookCount; i++) {
                        cout << "\nBook " << (i + 1) << ":\n";
                        books[i].display();
                        cout << "-------------------------------\n";
                    }
                }
                break;
            }

            case 3: { // Update Book Details
                string isbn;
                cout << "Enter the ISBN of the book to update: ";
                cin >> isbn;
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].isbn == isbn) {
                        cout << "Updating details for Book with ISBN: " << isbn << endl;
                        books[i].update();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Book with ISBN " << isbn << " not found.\n";
                }
                break;
            }

            case 4: { // Delete Book
                string isbn;
                cout << "Enter the ISBN of the book to delete: ";
                cin >> isbn;
                bool found = false;
                for (int i = 0; i < bookCount; i++) {
                    if (books[i].isbn == isbn) {
                        for (int j = i; j < bookCount - 1; j++) {
                            books[j] = books[j + 1];
                        }
                        bookCount--;
                        found = true;
                        cout << "Book with ISBN " << isbn << " deleted.\n";
                        break;
                    }
                }
                if (!found) {
                    cout << "Book with ISBN " << isbn << " not found.\n";
                }
                break;
            }

            case 5: { // Sort Books
                int sortChoice;
                cout << "Enter 1 to sort by Title, 2 to sort by Author: ";
                cin >> sortChoice;
                if (sortChoice == 1) {
                    for (int i = 0; i < bookCount - 1; i++) {
                        for (int j = 0; j < bookCount - i - 1; j++) {
                            if (books[j].compareTitle(books[j + 1])) {
                                Book temp = books[j];
                                books[j] = books[j + 1];
                                books[j + 1] = temp;
                            }
                        }
                    }
                    cout << "Books sorted by Title.\n";
                } else if (sortChoice == 2) {
                    for (int i = 0; i < bookCount - 1; i++) {
                        for (int j = 0; j < bookCount - i - 1; j++) {
                            if (books[j].compareAuthor(books[j + 1])) {
                                Book temp = books[j];
                                books[j] = books[j + 1];
                                books[j + 1] = temp;
                            }
                        }
                    }
                    cout << "Books sorted by Author.\n";
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }

            case 6: { // Add Library Member
                if (memberCount < MAX_MEMBERS) {
                    cout << "Enter details for Member " << (memberCount + 1) << ":\n";
                    members[memberCount].read();
                    memberCount++;
                } else {
                    cout << "Library membership is full.\n";
                }
                break;
            }

            case 7: { // Display Members
                if (memberCount == 0) {
                    cout << "No members in the library.\n";
                } else {
                    for (int i = 0; i < memberCount; i++) {
                        cout << "\nMember " << (i + 1) << ":\n";
                        members[i].display();
                        cout << "-------------------------------\n";
                    }
                }
                break;
            }

            case 8: { // Exit
                cout << "Exiting the Library Management System.\n";
                break;
            }

            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 8);

    return 0;
}

