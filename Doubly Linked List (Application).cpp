#include <iostream>
#include <string>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    string name; // Student name
    int aptitudeScore; // Aptitude test score
    int codingScore;   // Coding test score
    Node* prev;
    Node* next;
};

// Doubly linked list class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() : head(NULL) {}

    // Function to insert a node in sorted order based on total marks
    void insertSorted(const string& name, int aptitudeScore, int codingScore) {
        int totalScore = aptitudeScore + codingScore;

        Node* newNode = new Node();
        newNode->name = name;
        newNode->aptitudeScore = aptitudeScore;
        newNode->codingScore = codingScore;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            return;
        }

        if (totalScore < (head->aptitudeScore + head->codingScore)) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next && (current->next->aptitudeScore + current->next->codingScore) < totalScore) {
            current = current->next;
        }

        newNode->next = current->next;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    // Function to merge two sorted lists
    void mergeSorted(DoublyLinkedList& otherList) {
        Node* current = otherList.head;
        while (current) {
            insertSorted(current->name, current->aptitudeScore, current->codingScore);
            current = current->next;
        }
    }

    // Function to display the list
    void display() {
        cout << "Name\tAptitude\tCoding\tTotal\n";
        Node* current = head;
        while (current) {
            int totalScore = current->aptitudeScore + current->codingScore;
            cout << current->name << "\t" << current->aptitudeScore << "\t\t" 
                 << current->codingScore << "\t" << totalScore << endl;
            current = current->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    cout << "*******************************************************\n";
    cout << "******** WELCOME TO THE RECRUITMENT CELL **************\n";
    cout << "*******************************************************\n";

    DoublyLinkedList list1, list2;

    int n, m;
    string name;
    int aptitudeScore, codingScore;

    // Input for list1
    cout << "Enter the number of students in List 1: ";
    cin >> n;
    cout << "Enter details for " << n << " students (Name Aptitude_Score Coding_Score):\n";
    for (int i = 0; i < n; i++) {
        cin >> name >> aptitudeScore >> codingScore;
        list1.insertSorted(name, aptitudeScore, codingScore);
    }

    // Input for list2
    cout << "Enter the number of students in List 2: ";
    cin >> m;
    cout << "Enter details for " << m << " students (Name Aptitude_Score Coding_Score):\n";
    for (int i = 0; i < m; i++) {
        cin >> name >> aptitudeScore >> codingScore;
        list2.insertSorted(name, aptitudeScore, codingScore);
    }

    // Display sorted lists
    cout << "\nSorted List 1:\n";
    list1.display();

    cout << "Sorted List 2:\n";
    list2.display();

    // Merge the lists
    list1.mergeSorted(list2);

    // Display the merged list
    cout << "Merged and Sorted List:\n";
    list1.display();

    return 0;
}

