#include <iostream>

// Function to move a disk from source peg to destination peg
void moveDisk(int disk, char source, char destination) {
    std::cout << "Move disk " << disk << " from " << source << " to " << destination << std::endl;
}

// Function to solve Tower of Hanoi problem for 'n' disks
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(1, source, destination);
        return;
    }

    // Move (n-1) disks from source to auxiliary peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination peg
    moveDisk(n, source, destination);

    // Move (n-1) disks from auxiliary to destination peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;

    std::cout << "Enter the number of disks: ";
    std::cin >> numDisks;

    if (numDisks < 1) {
        std::cout << "Number of disks should be greater than or equal to 1." << std::endl;
        return 1;
    }

    std::cout << "Tower of Hanoi solution for " << numDisks << " disks:" << std::endl;

    towerOfHanoi(numDisks, 'A', 'B', 'C');

    return 0;
}

