#include <iostream>
using namespace std;

bool EquiRltn(const int matrix[][3], int size) {
    // Check reflexivity (diagonal elements should be 1)
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] != 1) {
            return false;  // If any diagonal element is not 1, it's not reflexive
        }
    }

    // Check symmetry (matrix[i][j] == matrix[j][i])
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;  // If matrix is not symmetric
            }
        }
    }

    // Check transitivity (if matrix[i][j] == 1 and matrix[j][k] == 1, then matrix[i][k] should be 1)
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                if (matrix[i][j] == 1 && matrix[j][k] == 1 && matrix[i][k] != 1) {
                    return false;  // Violation of transitivity
                }
            }
        }
    }
    
    return true;  // All checks passed
}

int main() {
    int data[][3] = {
        {1, 0, 0},
        {0, 1, 1},
        {0, 1, 1}
    };
    int size = sizeof(data) / sizeof(data[0]);

    if (EquiRltn(data, size)) {
        cout << "THE MATRIX SATISFIES THE EQUIVALENCE RELATION\n";
    } else {
        cout << "THE MATRIX DOES NOT SATISFY THE EQUIVALENCE RELATION.\n";
    }

    return 0;
}

