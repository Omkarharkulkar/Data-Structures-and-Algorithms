#include <iostream>
#include <string>
using namespace std;

bool isEvenParity(const string& word) {
    int count = 0;

    for (char ch : word) {
        int asciiValue = static_cast<int>(ch);

        while (asciiValue) {
            count += (asciiValue & 1);
            asciiValue >>= 1;
        }
    }

    return (count % 2 == 0);
}

int main() {
    string word;

    cout << "Enter a word: ";
    cin >> word;

    bool isEven = isEvenParity(word);

    if (isEven) {
        cout << "The ASCII equivalence of the word has even parity." << endl;
    } else {
        cout << "The ASCII equivalence of the word has odd parity." << endl;
    }

    return 0;
}

