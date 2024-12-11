#include <iostream>

// Function to calculate the total count using the principle of inclusion and exclusion
int calculateTotalCount(int n, int sets[]) {
    int total = 0;
    int sign = -1;

    // Iterate over all possible subsets
    for (int i = 1; i < (1 << n); ++i) {
        int subsetCount = 0;
        int subsetProduct = 1;

        // Calculate count and product of each subset
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ++subsetCount;
                subsetProduct *= sets[j];
            }
        }

        // Add or subtract the count based on inclusion or exclusion
        total += sign * (subsetProduct / subsetCount);
        sign *= -1;
    }

    return total;
}

int main() {
    int n;
    std::cout << "Enter the number of sets: ";
    std::cin >> n;

    int sets[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter the count for Set " << i + 1 << ": ";
        std::cin >> sets[i];
    }

    int totalCount = calculateTotalCount(n, sets);

    std::cout << "The total count is: " << totalCount << std::endl;

    return 0;
}

