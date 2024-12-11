#include <iostream>
using namespace std;

class SparseMatrix {
private:
    int A[20][3]; // Array to store the sparse matrix (row, column, value)
    int len;      // Length (number of non-zero elements)

public:
    // Constructor to initialize matrix dimensions and non-zero element count
    SparseMatrix(int r, int c, int l) {
        A[0][0] = r; // Rows
        A[0][1] = c; // Columns
        A[0][2] = l; // Non-zero elements
        len = 0;
    }

    // Function to read the sparse matrix elements
    void read() {
        for (int i = 1; i <= A[0][2]; i++) {
            cout << "Enter the row: ";
            cin >> A[i][0];
            cout << "Enter the column: ";
            cin >> A[i][1];
            cout << "Enter the value: ";
            cin >> A[i][2];
        }
    }

    // Function to display the sparse matrix
    void display() {
        for (int i = 0; i <= A[0][2]; i++) {
            for (int j = 0; j < 3; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Function to insert an element into the sparse matrix
    void insert(int row, int col, int value) {
        if (len < 20) {
            len++;
            A[len][0] = row;
            A[len][1] = col;
            A[len][2] = value;
        } else {
            cout << "Sparse matrix is full. Cannot insert more elements." << endl;
        }
    }

    // Function to multiply two sparse matrices
    void multiply(SparseMatrix b) {
        if (A[0][1] != b.A[0][0]) {
            cout << "Matrix multiplication not possible. Invalid dimensions." << endl;
            return;
        }

        SparseMatrix result(A[0][0], b.A[0][1], 0);
        for (int i = 1; i <= A[0][2]; i++) {
            for (int j = 1; j <= b.A[0][2]; j++) {
                if (A[i][1] == b.A[j][0]) {
                    int val = 0;
                    for (int k = 1; k <= b.A[0][1]; k++) {
                        if (A[i][1] == b.A[j][0]) {
                            val += A[i][2] * b.A[j][2];
                        }
                    }
                    result.insert(A[i][0], b.A[j][1], val);
                }
            }
        }
        result.display();
    }

    // Function to add two sparse matrices
    void addition(SparseMatrix sp2) {
        int result[20][3];
        int i = 1, j = 1, k = 1;
        int l1 = A[0][2], l2 = sp2.A[0][2];

        if (A[0][0] != sp2.A[0][0] || A[0][1] != sp2.A[0][1]) {
            cout << "Can't add two matrices" << endl;
            return;
        } else {
            result[0][0] = A[0][0];
            result[0][1] = A[0][1];
        }

        while (i <= l1 && j <= l2) {
            if (A[i][0] == sp2.A[j][0]) {
                if (A[i][1] == sp2.A[j][1]) {
                    result[k][0] = A[i][0];
                    result[k][1] = A[i][1];
                    result[k][2] = A[i][2] + sp2.A[j][2];
                    i++; j++; k++;
                } else if (A[i][1] < sp2.A[j][1]) {
                    result[k][0] = A[i][0];
                    result[k][1] = A[i][1];
                    result[k][2] = A[i][2];
                    i++; k++;
                } else {
                    result[k][0] = sp2.A[j][0];
                    result[k][1] = sp2.A[j][1];
                    result[k][2] = sp2.A[j][2];
                    j++; k++;
                }
            } else if (A[i][0] < sp2.A[j][0]) {
                result[k][0] = A[i][0];
                result[k][1] = A[i][1];
                result[k][2] = A[i][2];
                i++; k++;
            } else {
                result[k][0] = sp2.A[j][0];
                result[k][1] = sp2.A[j][1];
                result[k][2] = sp2.A[j][2];
                j++; k++;
            }
        }

        while (i <= l1) {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++; k++;
        }

        while (j <= l2) {
            result[k][0] = sp2.A[j][0];
            result[k][1] = sp2.A[j][1];
            result[k][2] = sp2.A[j][2];
            j++; k++;
        }

        result[0][2] = k - 1;
        cout << "Addition of two sparse matrices:" << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 3; j++) {
                cout << result[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // Function to calculate the fast transpose of a sparse matrix
    void fast_transpose() {
        int loc, col_no;
        int result[20][3];
        int total[A[0][1]], index[A[0][1] + 1];

        for (int i = 0; i < A[0][1]; i++) {
            total[i] = 0;
        }

        for (int i = 1; i <= A[0][2]; i++) {
            col_no = A[i][1];
            total[col_no]++;
        }

        index[0] = 1;
        for (int i = 1; i <= A[0][1]; i++) {
            index[i] = index[i - 1] + total[i - 1];
        }

        result[0][0] = A[0][1];
        result[0][1] = A[0][0];
        result[0][2] = A[0][2];

        for (int i = 1; i <= A[0][2]; i++) {
            col_no = A[i][1];
            loc = index[col_no];
            result[loc][0] = A[i][1];
            result[loc][1] = A[i][0];
            result[loc][2] = A[i][2];
            index[col_no]++;
        }

        cout << "\nFast Transpose Result:" << endl;
        for (int i = 0; i <= result[0][2]; i++) {
            for (int j = 0; j < 3; j++) {
                cout << "\t" << result[i][j];
            }
            cout << endl;
        }
    }

    // Function to transpose a sparse matrix
    void transpose() {
        int transpose[20][3], k = 1;
        for (int z = 0; z < A[0][1]; z++) {
            for (int i = 1; i <= A[0][2]; i++) {
                if (A[i][1] == z) {
                    transpose[k][0] = A[i][1];
                    transpose[k][1] = A[i][0];
                    transpose[k][2] = A[i][2];
                    k++;
                }
            }
        }

        transpose[0][0] = A[0][1];
        transpose[0][1] = A[0][0];
        transpose[0][2] = A[0][2];

        cout << "Transpose of the sparse matrix:" << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < 3; j++) {
                cout << transpose[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    int r1, l1, c1;
    cout << "Enter the number of rows, columns, and non-zero elements for the first matrix: ";
    cin >> r1 >> c1 >> l1;
    SparseMatrix sp1(r1, c1, l1);
    cout << "Enter the elements of the first sparse matrix:" << endl;
    sp1.read();
    cout << "First sparse matrix:" << endl;
    sp1.display();

    int r2, l2, c2;
    cout << "Enter the number of rows, columns, and non-zero elements for the second matrix: ";
    cin >> r2 >> c2 >> l2;
    SparseMatrix sp2(r2, c2, l2);
    cout << "Enter the elements of the second sparse matrix:" << endl;
    sp2.read();
    cout << "Second sparse matrix:" << endl;
    sp2.display();

    if (c1 != r2) {
        cout << "Matrix multiplication not possible due to incompatible dimensions." << endl;
    } else {
        cout << "Matrix Multiplication:" << endl;
        sp1.multiply(sp2);
    }

    cout << "Addition of two sparse matrices:" << endl;
    sp1.addition(sp2);

    cout << "Transpose of the first sparse matrix:" << endl;
    sp1.transpose();

    sp1.fast_transpose();
    
    return 0;
}

