/*
100   400
020   050
003   006 */

#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

// Structure to represent a sparse matrix element
struct SparseElement 
{
    int row;
    int col;
    int value;
};

// Function to read a sparse matrix from the user
void readSparseMatrix(int matrix[][MAX_COLS], int& rows, int& cols) 
{
    cout << "Enter the number of rows: ";
    cin >> rows;

    cout << "Enter the number of columns: ";
    cin >> cols;

    cout << "Enter the matrix elements: " << endl;
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            cin >> matrix[i][j];
        }
    }
}

// Function to convert a matrix to sparse representation
void convertToSparse(const int matrix[][MAX_COLS], int rows, int cols, SparseElement sparseArray[], int& numSparseElements) 
{
    numSparseElements = 0;

    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            if (matrix[i][j] != 0) 
			{
                sparseArray[numSparseElements].row = i;
                sparseArray[numSparseElements].col = j;
                sparseArray[numSparseElements].value = matrix[i][j];
                numSparseElements++;
            }
        }
    }
}

// Function to display a sparse matrix
void displaySparseMatrix(const SparseElement sparseArray[], int numSparseElements) 
{
    cout << "Sparse Matrix: " << endl;
    for (int i = 0; i < numSparseElements; i++) 
	{
        cout << sparseArray[i].row << "\t" << sparseArray[i].col << "\t" << sparseArray[i].value << endl;
    }
}

// Function to perform addition of two sparse matrices
void addSparseMatrices(const SparseElement sparseArray1[], int numSparseElements1, const SparseElement sparseArray2[], int numSparseElements2, SparseElement resultSparseArray[], int& numResultSparseElements) 
{
    int index1 = 0;
    int index2 = 0;
    numResultSparseElements = 0;

    while (index1 < numSparseElements1 && index2 < numSparseElements2) 
	{
        if (sparseArray1[index1].row < sparseArray2[index2].row || (sparseArray1[index1].row == sparseArray2[index2].row && sparseArray1[index1].col < sparseArray2[index2].col)) 
		{
            resultSparseArray[numResultSparseElements] = sparseArray1[index1];
            index1++;
        } 
		else if (sparseArray1[index1].row > sparseArray2[index2].row || (sparseArray1[index1].row == sparseArray2[index2].row && sparseArray1[index1].col > sparseArray2[index2].col)) 
		{
            resultSparseArray[numResultSparseElements] = sparseArray2[index2];
            index2++;
        } 
		else 
		{
            resultSparseArray[numResultSparseElements] = sparseArray1[index1];
            resultSparseArray[numResultSparseElements].value += sparseArray2[index2].value;
            index1++;
            index2++;
        }

        numResultSparseElements++;
    }

    // Copy any remaining elements from the first sparse matrix
    while (index1 < numSparseElements1) 
	{
        resultSparseArray[numResultSparseElements] = sparseArray1[index1];
        index1++;
        numResultSparseElements++;
    }

    // Copy any remaining elements from the second sparse matrix
    while (index2 < numSparseElements2) 
	{
        resultSparseArray[numResultSparseElements] = sparseArray2[index2];
        index2++;
        numResultSparseElements++;
    }
}

// Function to perform multiplication of two sparse matrices
void multiplySparseMatrices(const SparseElement sparseArray1[], int numSparseElements1, const SparseElement sparseArray2[], int numSparseElements2, SparseElement resultSparseArray[], int& numResultSparseElements, int rows1, int cols1, int cols2) {
    if (cols1 != numSparseElements2) 
	{
        cout << "Invalid matrix dimensions. Multiplication not possible." << endl;
        numResultSparseElements = 0;
        return;
    }

    numResultSparseElements = 0;

    for (int i = 0; i < numSparseElements1; i++) 
	{
        for (int j = 0; j < numSparseElements2; j++) 
		{
            if (sparseArray1[i].col == sparseArray2[j].row) 
			{
                resultSparseArray[numResultSparseElements].row = sparseArray1[i].row;
                resultSparseArray[numResultSparseElements].col = sparseArray2[j].col;
                resultSparseArray[numResultSparseElements].value += sparseArray1[i].value * sparseArray2[j].value;
                numResultSparseElements++;
            }
        }
    }
}

// Function to perform transpose of a sparse matrix
void transposeSparseMatrix(const SparseElement sparseArray[], int numSparseElements, SparseElement transposedSparseArray[], int& numTransposedSparseElements, int rows, int cols) {
    numTransposedSparseElements = 0;

    for (int j = 0; j < cols; j++) 
	{
        for (int i = 0; i < numSparseElements; i++) 
		{
            if (sparseArray[i].col == j) 
			{
                transposedSparseArray[numTransposedSparseElements].row = sparseArray[i].col;
                transposedSparseArray[numTransposedSparseElements].col = sparseArray[i].row;
                transposedSparseArray[numTransposedSparseElements].value = sparseArray[i].value;
                numTransposedSparseElements++;
            }
        }
    }
}

int main() 
{
    int matrix1[MAX_ROWS][MAX_COLS];
    int matrix2[MAX_ROWS][MAX_COLS];
    int rows1, cols1, rows2, cols2;

    // Read the first matrix from the user
    cout << "Enter details for the first matrix:" << endl;
    readSparseMatrix(matrix1, rows1, cols1);

    // Read the second matrix from the user
    cout << "Enter details for the second matrix:" << endl;
    readSparseMatrix(matrix2, rows2, cols2);

    SparseElement sparseArray1[MAX_ROWS * MAX_COLS];
    SparseElement sparseArray2[MAX_ROWS * MAX_COLS];
    SparseElement resultSparseArray[MAX_ROWS * MAX_COLS];
    SparseElement transposedSparseArray[MAX_ROWS * MAX_COLS];
    int numSparseElements1, numSparseElements2, numResultSparseElements, numTransposedSparseElements;

    // Convert the first matrix to sparse representation
    convertToSparse(matrix1, rows1, cols1, sparseArray1, numSparseElements1);

    // Convert the second matrix to sparse representation
    convertToSparse(matrix2, rows2, cols2, sparseArray2, numSparseElements2);

    cout << "\n--- Sparse Matrix Operations ---" << endl;

    // Addition of two sparse matrices
    addSparseMatrices(sparseArray1, numSparseElements1, sparseArray2, numSparseElements2, resultSparseArray, numResultSparseElements);
    cout << "\nAddition of two sparse matrices:" << endl;
    displaySparseMatrix(resultSparseArray, numResultSparseElements);

    // Multiplication of two sparse matrices
    multiplySparseMatrices(sparseArray1, numSparseElements1, sparseArray2, numSparseElements2, resultSparseArray, numResultSparseElements, rows1, cols1, cols2);
    cout << "\nMultiplication of two sparse matrices:" << endl;
    displaySparseMatrix(resultSparseArray, numResultSparseElements);

    // Transpose of a sparse matrix
    transposeSparseMatrix(sparseArray1, numSparseElements1, transposedSparseArray, numTransposedSparseElements, rows1, cols1);
    cout << "\nTranspose of the first sparse matrix:" << endl;
    displaySparseMatrix(transposedSparseArray, numTransposedSparseElements);

    return 0;
}

