// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string& name) {
    cout << "\nEnter elements for Matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}


void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = input[i][j];
        }
    }
}


void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}


void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int choice;
    cout << "=== MATRIX OPERATIONS ===" << endl;
    cout << "1. Transpose a Matrix (Part A)" << endl;
    cout << "2. Add Two Matrices (Part B)" << endl;
    cout << "3. Multiply Two Matrices (Part C)" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // --- PART A ---
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int matrix[MAX_SIZE][MAX_SIZE];
        int transpose[MAX_SIZE][MAX_SIZE];

        readMatrix(matrix, rows, cols, "A");

        transposeMatrix(matrix, transpose, rows, cols);

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(transpose, cols, rows);

    } else if (choice == 2) {
        // --- PART B ---
        int rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rows, cols, "A");
        readMatrix(B, rows, cols, "B");

        addMatrices(A, B, sum, rows, cols);

        cout << "\nMatrix A + Matrix B:" << endl;
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // --- PART C ---
        int rowsA, colsA, rowsB, colsB;
        cout << "Enter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        
        if (colsA != rowsB) {
            cout << "Error: Columns of A (" << colsA << ") must equal rows of B (" << rowsB << ")." << endl;
            return 1;
        }

        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

        readMatrix(A, rowsA, colsA, "A");
        readMatrix(B, rowsB, colsB, "B");

        multiplyMatrices(A, B, product, rowsA, colsA, colsB);

        cout << "\nMatrix A x Matrix B:" << endl;
        printMatrix(product, rowsA, colsB);

    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
