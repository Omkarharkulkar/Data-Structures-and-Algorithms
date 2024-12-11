// Implement a program for addition and multiplication of two matrices using concepts of 2-D arrays.

#include <iostream>
#include <cstdlib>
using namespace std;

// Function to input elements of a matrix
void inputMatrix(int matrix[][100], int rows, int cols) {
    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i + 1 << ", " << j + 1 << "): ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][100], int rows, int cols) {
    cout << "Matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
void addMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[][100], int matrix2[][100], int result[][100], int rows1, int cols1, int rows2, int cols2) {
    if (cols1 != rows2) {
        cerr << "Error: Matrix multiplication not possible. Number of columns in the first matrix should be equal to the number of rows in the second matrix." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    // Input dimensions of the first matrix
    cout << "Enter dimensions of the first matrix:" << endl;
    cout << "Number of rows: ";
    cin >> rows1;
    cout << "Number of columns: ";
    cin >> cols1;

    // Input elements of the first matrix
    int matrix1[100][100];
    inputMatrix(matrix1, rows1, cols1);

    // Input dimensions of the second matrix
    cout << "Enter dimensions of the second matrix:" << endl;
    cout << "Number of rows: ";
    cin >> rows2;
    cout << "Number of columns: ";
    cin >> cols2;

    // Input elements of the second matrix
    int matrix2[100][100];
    inputMatrix(matrix2, rows2, cols2);

    // Check if matrices can be added
    if (rows1 == rows2 && cols1 == cols2) {
        int sumMatrix[100][100];
        addMatrices(matrix1, matrix2, sumMatrix, rows1, cols1);
        cout << "Result of Matrix Addition:" << endl;
        displayMatrix(sumMatrix, rows1, cols1);
    } else {
        cout << "Matrices cannot be added. Dimensions are not the same." << endl;
    }

    // Check if matrices can be multiplied
    if (cols1 == rows2) {
        int productMatrix[100][100];
        multiplyMatrices(matrix1, matrix2, productMatrix, rows1, cols1, rows2, cols2);
        cout << "Result of Matrix Multiplication:" << endl;
        displayMatrix(productMatrix, rows1, cols2);
    } else {
        cout << "Matrices cannot be multiplied. Number of columns in the first matrix is not equal to the number of rows in the second matrix." << endl;
    }

    return 0;
}

