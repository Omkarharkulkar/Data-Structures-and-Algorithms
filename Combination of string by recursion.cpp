#include <iostream>
#include <string.h>

using namespace std;

char temp[10];
int count = 0; // Global variable to count the combinations

// Function to generate all combinations
void combination(char *str, int r, int index) {
    for (int i = 0; i < strlen(str); i++) {
        temp[index] = str[i];
        if (index == r - 1) {
            temp[r] = '\0'; // Null-terminate the string
            cout << "\t" << temp;
            count++; // Increment the combination count
        } else {
            combination(str, r, index + 1);
        }
    }
}

int main() {
    char str[45];
    cout << "Enter the String: ";
    cin >> str;

    cout << "\nAll possible combinations are:\n";
    for (int r = 1; r <= strlen(str); r++) {
        combination(str, r, 0);
    }

    cout << "\n\nTotal number of combinations: " << count << endl;
    return 0;
}

