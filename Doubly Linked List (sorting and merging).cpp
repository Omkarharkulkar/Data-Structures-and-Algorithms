#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Function to merge two sorted lists
Node* mergeLists(Node* head1, Node* head2) {
    Node* mergedHead = NULL;
    Node* tail = NULL;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (mergedHead == NULL) {
                mergedHead = tail = head1;
            } else {
                tail->next = head1;
                head1->prev = tail;
                tail = tail->next;
            }
            head1 = head1->next;
        } else {
            if (mergedHead == NULL) {
                mergedHead = tail = head2;
            } else {
                tail->next = head2;
                head2->prev = tail;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }

    // Attach remaining nodes of head1, if any
    if (head1 != NULL) {
        tail->next = head1;
        head1->prev = tail;
    }

    // Attach remaining nodes of head2, if any
    if (head2 != NULL) {
        tail->next = head2;
        head2->prev = tail;
    }

    return mergedHead;
}

// Function to print the doubly linked list
void printList(Node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "List: ";
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to sort a doubly linked list using bubble sort
void bubbleSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    bool swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    int size1, size2;

    cout << "Enter the number of elements in the first list: ";
    cin >> size1;

    cout << "Enter the elements of the first list: ";
    for (int i = 0; i < size1; i++) {
        int marks;
        cin >> marks;
        insertAtBeginning(&list1, marks);
    }

    cout << "Enter the number of elements in the second list: ";
    cin >> size2;

    cout << "Enter the elements of the second list: ";
    for (int i = 0; i < size2; i++) {
        int marks;
        cin >> marks;
        insertAtBeginning(&list2, marks);
    }

    // Sort the individual lists
    bubbleSort(list1);
    bubbleSort(list2);

    cout << "Sorted List 1: ";
    printList(list1);

    cout << "Sorted List 2: ";
    printList(list2);

    // Merge the sorted lists
    Node* mergedList = mergeLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

