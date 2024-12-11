#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void append(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display the doubly linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to merge two lists at alternate positions
Node* mergeAlternate(Node* list1, Node* list2) {
    Node* head1 = list1;
    Node* head2 = list2;

    while (head1 != NULL && head2 != NULL) {
        Node* next1 = head1->next;
        Node* next2 = head2->next;

        head1->next = head2;
        head2->prev = head1;

        if (next1 != NULL) {
            head2->next = next1;
            next1->prev = head2;
        }

        head1 = next1;
        head2 = next2;
    }

    return list1;
}

// Function to sort a doubly linked list
void sortList(Node*& head) {
    if (head == NULL) return;

    for (Node* i = head; i->next != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// Main function
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int n1, n2, value;

    // Input first list
    cout << "Enter the number of elements in the first list: ";
    cin >> n1;
    cout << "Enter the elements of the first list:" << endl;
    for (int i = 0; i < n1; ++i) {
        cin >> value;
        append(list1, value);
    }

    // Input second list
    cout << "Enter the number of elements in the second list: ";
    cin >> n2;
    cout << "Enter the elements of the second list:" << endl;
    for (int i = 0; i < n2; ++i) {
        cin >> value;
        append(list2, value);
    }

    // Merge the lists at alternate positions
    Node* mergedList = mergeAlternate(list1, list2);

    // Display the merged list
    cout << "Merged List:" << endl;
    display(mergedList);

    // Sort the merged list
    sortList(mergedList);

    // Display the sorted list
    cout << "Sorted Merged List:" << endl;
    display(mergedList);

    return 0;
}

