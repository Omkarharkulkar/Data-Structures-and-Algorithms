#include <iostream>
#include <cstring>
using namespace std;

// Constants
const int STACK_SIZE = 5;
const string ROYAL_FLUSH_CARDS[5] = {"10", "J", "Q", "K", "A"};

// Stack ADT using an array
struct Stack {
    string cards[STACK_SIZE];
    int top;

    // Initialize the stack
    void init() {
        top = -1;
    }

    // Push a card onto the stack
    bool push(string card) {
        if (top >= STACK_SIZE - 1) {
            cout << "Stack overflow! Too many cards." << endl;
            return false;
        }
        cards[++top] = card;
        return true;
    }

    // Pop a card from the stack
    string pop() {
        if (top < 0) {
            cout << "Stack underflow! No cards to pop." << endl;
            return "";
        }
        return cards[top--];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Get the top card of the stack
    string peek() {
        if (top >= 0)
            return cards[top];
        return "";
    }
};

// Function to check if a card exists in the hand (recursive)
bool containsCard(string hand[], string suit[], int size, string card, string requiredSuit) {
    if (size == 0) return false; // Base case: empty hand
    if (hand[size - 1] == card && suit[size - 1] == requiredSuit) return true; // Card found
    return containsCard(hand, suit, size - 1, card, requiredSuit); // Recursive call
}

// Function to check if the hand is a Royal Flush
bool isRoyalFlush(string hand[], string suit[], int size, string requiredSuit, Stack &stack) {
    if (stack.isEmpty()) return true; // Base case: All cards in the Royal Flush are found
    string card = stack.pop(); // Get the top card to check
    if (!containsCard(hand, suit, size, card, requiredSuit)) {
        return false; // Card not found in the required suit
    }
    return isRoyalFlush(hand, suit, size, requiredSuit, stack); // Recursive check for remaining cards
}

int main() {
    int numCards;
    string requiredSuit;

    // Input number of cards in the hand
    cout << "Enter the number of cards in your hand: ";
    cin >> numCards;

    // Input cards and their suits
    string *hand = new string[numCards];
    string *suit = new string[numCards];

    cout << "Enter the cards and their suits (e.g., 10 Hearts):" << endl;
    for (int i = 0; i < numCards; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i] >> suit[i];
    }

    // Input the required suit for the Royal Flush
    cout << "Enter the suit you want to check for the Royal Flush: ";
    cin >> requiredSuit;

    // Initialize the stack with Royal Flush cards
    Stack stack;
    stack.init();
    for (int i = 0; i < 5; i++) {
        stack.push(ROYAL_FLUSH_CARDS[i]);
    }

    // Check for Royal Flush
    bool result = isRoyalFlush(hand, suit, numCards, requiredSuit, stack);

    // Output results
    cout << "\nResult: ";
    if (result) {
        cout << "Congratulations! You have a Royal Flush in " << requiredSuit << "." << endl;
    } else {
        cout << "No Royal Flush found in " << requiredSuit << "." << endl;
    }

    // Clean up
    delete[] hand;
    delete[] suit;

    return 0;
}

