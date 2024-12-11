#include <iostream>
#include <cstring> // For string manipulation
using namespace std;

struct Node {
    char diseaseName[100];  // Disease name
    char symptoms[200];     // Symptoms
    int severity;           // Severity (1 to 10)
    int occurrence;         // Occurrence/frequency of the disease
    Node* link;             // Link to the next node
};

// Function prototypes
Node* create(Node* start);
Node* insert(Node* start, const char* diseaseName, const char* symptoms, int severity, int occurrence);
void display(Node* start);
Node* disease_add(Node* p1, Node* p2);
Node* disease_mult(Node* p1, Node* p2);

int main() {
    Node* diseaseList1 = NULL;
    Node* diseaseList2 = NULL;

    cout << "Enter disease information for list 1:\n";
    diseaseList1 = create(diseaseList1);

    cout << "Enter disease information for list 2:\n";
    diseaseList2 = create(diseaseList2);

    cout << "Disease List 1:\n";
    display(diseaseList1);

    cout << "Disease List 2:\n";
    display(diseaseList2);

    // Disease addition (merging based on severity)
    Node* mergedList = disease_add(diseaseList1, diseaseList2);
    cout << "\nMerged Disease List (based on severity):\n";
    display(mergedList);

    // Disease multiplication (cross information based on occurrence)
    Node* multipliedList = disease_mult(diseaseList1, diseaseList2);
    cout << "\nMultiplied Disease List (based on occurrences):\n";
    display(multipliedList);

    return 0;
}

// Function to create a list of diseases
Node* create(Node* start) {
    int n, severity, occurrence;
    char diseaseName[100], symptoms[200];

    cout << "Enter the number of diseases: ";
    cin >> n;
    cin.ignore(); // To ignore the newline after number input

    for (int i = 0; i < n; i++) {
        cout << "Enter disease name for disease " << i + 1 << ": ";
        cin.getline(diseaseName, 100);

        cout << "Enter symptoms for disease " << i + 1 << ": ";
        cin.getline(symptoms, 200);

        cout << "Enter severity (1-10) for disease " << i + 1 << ": ";
        cin >> severity;

        cout << "Enter occurrence (times per year) for disease " << i + 1 << ": ";
        cin >> occurrence;
        cin.ignore(); // To ignore the newline after occurrence input

        start = insert(start, diseaseName, symptoms, severity, occurrence);
    }

    return start;
}

// Function to insert a disease entry in a sorted circular list (by severity)
Node* insert(Node* start, const char* diseaseName, const char* symptoms, int severity, int occurrence) {
    Node* tmp = new Node();
    Node* ptr;

    strcpy(tmp->diseaseName, diseaseName);
    strcpy(tmp->symptoms, symptoms);
    tmp->severity = severity;
    tmp->occurrence = occurrence;

    if (start == NULL) {
        tmp->link = tmp; // Point to itself, making it circular
        start = tmp;
    } else if (severity > start->severity) {
        // Insert before the start node
        ptr = start;
        while (ptr->link != start) {
            ptr = ptr->link;
        }
        tmp->link = start;
        ptr->link = tmp;
        start = tmp; // Update start to the new node
    } else {
        ptr = start;
        while (ptr->link != start && ptr->link->severity >= severity) {
            ptr = ptr->link;
        }
        tmp->link = ptr->link;
        ptr->link = tmp;
    }

    return start;
}

// Function to display the disease list
void display(Node* start) {
    if (start == NULL) {
        cout << "No disease information available.\n";
        return;
    }

    Node* ptr = start;
    do {
        cout << "Disease: " << ptr->diseaseName << "\n";
        cout << "Symptoms: " << ptr->symptoms << "\n";
        cout << "Severity: " << ptr->severity << "\n";
        cout << "Occurrence (times per year): " << ptr->occurrence << "\n";
        cout << "---------------------------\n";
        ptr = ptr->link;
    } while (ptr != start);
}

// Function to add two disease lists based on severity
Node* disease_add(Node* p1, Node* p2) {
    Node* start3 = NULL;

    Node* head1 = p1;
    Node* head2 = p2;

    do {
        start3 = insert(start3, p1->diseaseName, p1->symptoms, p1->severity, p1->occurrence);
        p1 = p1->link;
    } while (p1 != head1);

    do {
        start3 = insert(start3, p2->diseaseName, p2->symptoms, p2->severity, p2->occurrence);
        p2 = p2->link;
    } while (p2 != head2);

    return start3;
}

// Function to multiply two disease lists based on occurrences
Node* disease_mult(Node* p1, Node* p2) {
    Node* start3 = NULL;

    Node* head1 = p1;
    Node* head2 = p2;

    do {
        Node* temp = p2;
        do {
            char combinedName[200];
            char combinedSymptoms[400];

            strcpy(combinedName, p1->diseaseName);
            strcat(combinedName, " & ");
            strcat(combinedName, temp->diseaseName);

            strcpy(combinedSymptoms, p1->symptoms);
            strcat(combinedSymptoms, " & ");
            strcat(combinedSymptoms, temp->symptoms);

            int newOccurrence = p1->occurrence * temp->occurrence;

            start3 = insert(start3, combinedName, combinedSymptoms, p1->severity, newOccurrence);

            temp = temp->link;
        } while (temp != head2);

        p1 = p1->link;
    } while (p1 != head1);

    return start3;
}

