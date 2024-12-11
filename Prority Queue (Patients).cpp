#include <iostream>
#include <string> // Include the string header
#include <cstdlib>
using namespace std;

// Structure to represent a patient
struct Patient {
    string name;
    int priority;

    // Function to initialize a patient
    void initialize(const string& n, int p) {
        name = n;
        priority = p;
    }
};

// Class for the priority queue
class PriorityQueue {
private:
    static const int maxSize = 100;
    Patient heap[maxSize];
    int size;

    // Manual swap function
    void swapPatients(Patient& a, Patient& b) {
        Patient temp = a;
        a = b;
        b = temp;
    }

public:
    // Constructor
    PriorityQueue() {
        size = 0;
    }

    // Function to enqueue a patient
    void enqueue(const Patient& patient) {
        if (size == maxSize) {
            cerr << "Priority queue is full. Cannot enqueue." << endl;
            return;
        }

        int currentIndex = size;
        int parentIndex = (currentIndex - 1) / 2;

        // Move up the tree to find the correct position
        while (currentIndex > 0 && patient.priority < heap[parentIndex].priority) {
            heap[currentIndex] = heap[parentIndex];
            currentIndex = parentIndex;
            parentIndex = (currentIndex - 1) / 2;
        }

        // Insert the new patient
        heap[currentIndex] = patient;
        size++;
    }

    // Function to dequeue a patient (remove the patient with the highest urgency)
    Patient dequeue() {
        if (isEmpty()) {
            cerr << "Priority queue is empty. Cannot dequeue." << endl;
            exit(EXIT_FAILURE);
        }

        Patient topPatient = heap[0];

        // Move the last patient to the root
        heap[0] = heap[size - 1];
        size--;

        int currentIndex = 0;
        int leftChildIndex, rightChildIndex, minIndex;

        while (true) {
            leftChildIndex = 2 * currentIndex + 1;
            rightChildIndex = 2 * currentIndex + 2;
            minIndex = currentIndex;

            // Find the index of the smallest child (if any)
            if (leftChildIndex < size && heap[leftChildIndex].priority < heap[minIndex].priority) {
                minIndex = leftChildIndex;
            }

            if (rightChildIndex < size && heap[rightChildIndex].priority < heap[minIndex].priority) {
                minIndex = rightChildIndex;
            }

            // If the current node is smaller than its children, swap with the smaller child
            if (minIndex != currentIndex) {
                swapPatients(heap[currentIndex], heap[minIndex]);
                currentIndex = minIndex;
            } else {
                break;
            }
        }

        return topPatient;
    }

    // Function to check if the priority queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Function to display the patients in the priority queue
    void displayPatients() const {
        if (isEmpty()) {
            cout << "Priority queue is empty." << endl;
            return;
        }

        cout << "Patients in Priority Queue:" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i].name << ", Priority: " << heap[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue appointmentQueue;

    // Enqueue patients with different priorities
    Patient p1, p2, p3;
    p1.initialize("Alice", 3);
    p2.initialize("Bob", 1);
    p3.initialize("Charlie", 2);

    appointmentQueue.enqueue(p1);
    appointmentQueue.enqueue(p2);
    appointmentQueue.enqueue(p3);

    // Display the patients in the queue
    appointmentQueue.displayPatients();

    // Dequeue patients and display their details
    cout << "Dequeueing patients:" << endl;
    while (!appointmentQueue.isEmpty()) {
        Patient patient = appointmentQueue.dequeue();
        cout << "Patient: " << patient.name << ", Priority: " << patient.priority << endl;
    }

    return 0;
}

