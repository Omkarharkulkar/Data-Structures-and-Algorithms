#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkRoyalFlush(const vector<int>& hand, int index, int suit) {
    if (index == 5) {
        return true;  // Base case: all 5 cards found in the same suit
    }

    // Check if the current card matches the suit and rank of a Royal Flush card
    if (hand[index] == suit && (hand[index + 1] == 10 || hand[index + 1] == 11 ||
                                hand[index + 1] == 12 || hand[index + 1] == 13 ||
                                hand[index + 1] == 14)) {
        return checkRoyalFlush(hand, index + 1, suit);  // Recursively check the next card
    }

    return false;  // No Royal Flush found
}

bool hasRoyalFlush(const vector<int>& hand) {
    // Sort the hand in ascending order
    vector<int> sortedHand = hand;
    sort(sortedHand.begin(), sortedHand.end());

    // Check for a Royal Flush in each suit
    for (int suit = 1; suit <= 4; ++suit) {
        if (checkRoyalFlush(sortedHand, 0, suit)) {
            return true;  // Royal Flush found
        }
    }

    return false;  // No Royal Flush found in any suit
}

int main() {
    vector<int> hand;
    int card;

    // Input five cards from the user
    cout << "Enter five cards (10-14) in any order: " << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Card " << (i + 1) << ": ";
        cin >> card;
        hand.push_back(card);
    }

    if (hasRoyalFlush(hand)) {
        cout << "Congratulations! You have a Royal Flush!" << endl;
    } else {
        cout << "Sorry, no Royal Flush in this hand." << endl;
    }

    return 0;
}

