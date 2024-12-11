#include <iostream>
#include <cstdlib>
using namespace std;

// Process structure
struct Process {
    int processId;
    int arrivalTime;
    int burstTime;
    int turnaroundTime;
    int waitingTime;
};

// Node structure for a linked list
struct Node {
    Process data;
    Node* next;
};

// Class for the queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Destructor to free allocated memory
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Function to enqueue a process
    void enqueue(Process process) {
        Node* newNode = new Node;
        newNode->data = process;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue a process
    Process dequeue() {
        if (isEmpty()) {
            cerr << "Queue is empty. Cannot dequeue." << endl;
            exit(EXIT_FAILURE);
        }

        Process data = front->data;
        Node* temp = front;

        if (front == rear) {
            front = rear = NULL;
        } else {
            front = front->next;
        }

        delete temp;
        return data;
    }

    // Function to remove a specific node
    void removeNode(Node* target) {
        if (isEmpty() || target == NULL) return;

        if (target == front) {
            dequeue();
            return;
        }

        Node* prev = front;
        while (prev->next != target && prev->next != NULL) {
            prev = prev->next;
        }

        if (prev->next == target) {
            prev->next = target->next;
            if (target == rear) {
                rear = prev;
            }
            delete target;
        }
    }

    // Function to find the node with the minimum burst time (used in SJF)
    Node* findMinBurstNode(int currentTime) {
        Node* temp = front;
        Node* minNode = NULL;

        while (temp != NULL) {
            if (temp->data.arrivalTime <= currentTime) {
                if (minNode == NULL || temp->data.burstTime < minNode->data.burstTime) {
                    minNode = temp;
                }
            }
            temp = temp->next;
        }

        return minNode;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == NULL;
    }
};

// Function to perform FCFS scheduling
void FCFS(Queue& processQueue) {
    int currentTime = 0;

    while (!processQueue.isEmpty()) {
        Process currentProcess = processQueue.dequeue();

        if (currentTime < currentProcess.arrivalTime) {
            currentTime = currentProcess.arrivalTime;
        }

        currentProcess.waitingTime = currentTime - currentProcess.arrivalTime;
        currentProcess.turnaroundTime = currentProcess.waitingTime + currentProcess.burstTime;

        currentTime += currentProcess.burstTime;

        cout << "Process " << currentProcess.processId << ": ";
        cout << "Turnaround Time = " << currentProcess.turnaroundTime << ", ";
        cout << "Waiting Time = " << currentProcess.waitingTime << endl;
    }
}

// Function to perform SJF scheduling
void SJF(Queue& processQueue) {
    int currentTime = 0;

    while (!processQueue.isEmpty()) {
        Node* minBurstNode = processQueue.findMinBurstNode(currentTime);

        if (minBurstNode == NULL) {
            currentTime++;
        } else {
            Process minBurstProcess = minBurstNode->data;
            processQueue.removeNode(minBurstNode);

            minBurstProcess.waitingTime = currentTime - minBurstProcess.arrivalTime;
            minBurstProcess.turnaroundTime = minBurstProcess.waitingTime + minBurstProcess.burstTime;

            currentTime += minBurstProcess.burstTime;

            cout << "Process " << minBurstProcess.processId << ": ";
            cout << "Turnaround Time = " << minBurstProcess.turnaroundTime << ", ";
            cout << "Waiting Time = " << minBurstProcess.waitingTime << endl;
        }
    }
}

int main() {
    Queue processQueue;
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Process process;
        process.processId = i + 1;

        cout << "Enter arrival time for Process " << process.processId << ": ";
        cin >> process.arrivalTime;

        cout << "Enter burst time for Process " << process.processId << ": ";
        cin >> process.burstTime;

        processQueue.enqueue(process);
    }

    cout << "FCFS Scheduling:" << endl;
    FCFS(processQueue);

    cout << endl;

    // Re-create queue for SJF scheduling
    for (int i = 0; i < n; i++) {
        Process process;
        process.processId = i + 1;

        cout << "Enter arrival time for Process " << process.processId << ": ";
        cin >> process.arrivalTime;

        cout << "Enter burst time for Process " << process.processId << ": ";
        cin >> process.burstTime;

        processQueue.enqueue(process);
    }

    cout << "SJF Scheduling:" << endl;
    SJF(processQueue);

    return 0;
}

