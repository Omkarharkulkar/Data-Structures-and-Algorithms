#include <iostream>
#include <string>
#include <bitset>  // For binary representation

using namespace std;

// Function to check if the string has even parity
bool isEvenParity(const string& word) 
{
    int parity = 0;
    cout << "Calculating parity for each character in the word:\n";
    for (string::size_type i = 0; i < word.length(); ++i) 
	{
        int ascii = static_cast<int>(word[i]);
        cout << "Character: '" << word[i] << "' (ASCII: " << ascii << ") => Binary: " << bitset<8>(ascii) << endl;
        
        while (ascii != 0) 
		{
            if (ascii & 1) 
			{
                parity++;  // Increment parity count for each '1' bit
            }
            ascii >>= 1;  // Right-shift to move to the next bit
        }
    }
    // Output the running total parity and check if it's even or odd
    cout << "Total 1s encountered: " << parity << endl;
    return (parity % 2) == 0;  // If parity is even (count of 1s is even)
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    bool isEven = isEvenParity(word);  // Call isEvenParity once
    
    if (isEven) 
	{
        cout << "Even parity\n";
    } 
	else 
	{
        cout << "Odd parity\n";
    }

    return 0;
}

