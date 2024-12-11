#include <iostream>
#include <string>
using namespace std;

// Function to calculate the number of people involved in at least one sport
int calculateAtLeastOne(int A, int B, int C, int AB, int BC, int AC, int ABC) {
    return A + B + C - AB - BC - AC + ABC;
}

// Function to calculate the number of people involved in exactly one sport
int calculateExactlyOne(int A, int B, int C, int AB, int BC, int AC, int ABC) {
    int onlyA = A - AB - AC + ABC;
    int onlyB = B - AB - BC + ABC;
    int onlyC = C - AC - BC + ABC;
    return onlyA + onlyB + onlyC;
}

// Function to calculate the number of people involved in all three sports
int calculateAllThree(int ABC) {
    return ABC;
}

int main() {
    string sportA, sportB, sportC;
    int A, B, C;       // Number of people in each sport
    int AB, BC, AC;    // Number of people in two-sport combinations
    int ABC;           // Number of people in all three sports

    // Input sports names
    cout << "Enter the name of Sport A: ";
    cin >> sportA;
    cout << "Enter the name of Sport B: ";
    cin >> sportB;
    cout << "Enter the name of Sport C: ";
    cin >> sportC;

    // Input participants
    cout << "Enter the number of people playing only " << sportA << ", " << sportB << ", and " << sportC << " respectively: ";
    cin >> A >> B >> C;

    cout << "Enter the number of people playing both " << sportA << " & " << sportB << ", " 
         << sportB << " & " << sportC << ", and " << sportA << " & " << sportC << " respectively: ";
    cin >> AB >> BC >> AC;

    cout << "Enter the number of people playing all three sports (" << sportA << ", " << sportB << ", " << sportC << "): ";
    cin >> ABC;

    // Calculations
    int atLeastOne = calculateAtLeastOne(A, B, C, AB, BC, AC, ABC);
    int exactlyOne = calculateExactlyOne(A, B, C, AB, BC, AC, ABC);
    int allThree = calculateAllThree(ABC);

    // Output results
    cout << "\nSurvey Results:" << endl;
    cout << "Number of people playing at least one sport: " << atLeastOne << endl;
    cout << "Number of people playing exactly one sport: " << exactlyOne << endl;
    cout << "Number of people playing all three sports (" << sportA << ", " << sportB << ", " << sportC << "): " << allThree << endl;

    return 0;
}

