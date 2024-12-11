#include <iostream>
#include <cstring>
using namespace std;

const int MAX_FRIENDS = 100;

// Structure to store friend information
struct Friend {
    char name[50];
    long mobileNumber; // Changed to 'long' for C++98 compatibility
};

// Function to perform Sentinel search
int sentinelSearch(Friend friends[], int n, char key[]) {
    strcpy(friends[n].name, key); // Set Sentinel value

    int i = 0;
    while (strcmp(friends[i].name, key) != 0) {
        i++;
    }

    if (i < n) {
        return i; // Friend found
    } else {
        return -1; // Friend not found
    }
}

// Function to insert a friend into the phone book
void insertFriend(Friend friends[], int& n, char name[], long mobileNumber) {
    if (n == MAX_FRIENDS) {
        cout << "Phone book is full. Cannot insert more friends." << endl;
        return;
    }

    // Find the correct position to insert the friend in sorted order
    int i = n - 1;
    while (i >= 0 && strcmp(friends[i].name, name) > 0) {
        friends[i + 1] = friends[i];
        i--;
    }

    // Insert the friend
    strcpy(friends[i + 1].name, name);
    friends[i + 1].mobileNumber = mobileNumber;

    // Increment the number of friends
    n++;

    cout << "Friend inserted successfully." << endl;
}

// Function to display the phone book
void displayPhoneBook(Friend friends[], int n) {
    cout << "Phone Book:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Name: " << friends[i].name
             << ", Mobile Number: " << friends[i].mobileNumber << endl;
    }
}

int main() {
    Friend friends[MAX_FRIENDS];
    int numFriends = 0;

    // Insert initial friends into the phone book (assuming sorted order)
    insertFriend(friends, numFriends, "Alice", 1234567890);
    insertFriend(friends, numFriends, "Bob", 987654321);
    insertFriend(friends, numFriends, "Charlie", 555555555);

    char searchName[50];
    cout << "Enter the name to search in the phone book: ";
    cin >> searchName;

    int foundIndex = sentinelSearch(friends, numFriends, searchName);

    if (foundIndex != -1) {
        cout << "Friend found! Name: " << friends[foundIndex].name
             << ", Mobile Number: " << friends[foundIndex].mobileNumber << endl;
    } else {
        cout << "Friend not found in the phone book." << endl;

        // Ask if the user wants to insert the friend
        char response;
        cout << "Do you want to insert this friend? (y/n): ";
        cin >> response;

        if (response == 'y' || response == 'Y') {
            long mobileNumber; // Changed to 'long'
            cout << "Enter the mobile number: ";
            cin >> mobileNumber;

            insertFriend(friends, numFriends, searchName, mobileNumber);
        }
    }

    // Display the updated phone book
    displayPhoneBook(friends, numFriends);

    return 0;
}

