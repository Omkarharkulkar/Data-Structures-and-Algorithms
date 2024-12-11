#include <iostream>

// Function to swap two characters
void swap(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

// Function to generate permutations of a string
void generatePermutations(char str[], int start, int end) {
    if (start == end) {
        std::cout << str << std::endl;
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(str[start], str[i]);
        generatePermutations(str, start + 1, end);
        swap(str[start], str[i]); // Backtrack
    }
}

// Function to generate combinations of a string
void generateCombinations(char str[], int start, int end, int r, char result[], int index) {
    if (index == r) {
        result[index] = '\0';
        std::cout << result << std::endl;
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++) {
        result[index] = str[i];
        generateCombinations(str, i + 1, end, r, result, index + 1);
    }
}

int main() {
    const int maxSize = 100; // Maximum size of the string
    char str[maxSize];

    // Input for the string
    std::cout << "Enter a string: ";
    std::cin >> str;

    // Calculate string length
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    // Check for empty string
    if (length == 0) {
        std::cout << "Empty string provided." << std::endl;
        return 1;
    }

    // Permutations
    std::cout << "Permutations:" << std::endl;
    generatePermutations(str, 0, length - 1);

    // Combinations
    std::cout << "Combinations:" << std::endl;
    for (int r = 1; r <= length; r++) {
        char result[maxSize];
        generateCombinations(str, 0, length - 1, r, result, 0);
    }

    return 0;
}

