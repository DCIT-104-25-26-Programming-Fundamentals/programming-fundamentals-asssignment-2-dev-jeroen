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

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

// Helper function to print a matrix neatly using setw()
void printMatrix(const int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// Helper function to input elements into a matrix
void inputMatrix(int matrix[MAX][MAX], int rows, int cols, const string& name) {
    cout << "Enter elements for Matrix " << name << " (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// PART A: Transpose a Matrix
void transposeMatrix(const int src[MAX][MAX], int dest[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = src[i][j];
        }
    }
}

// PART B: Add Two Matrices
void addMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiply Two Matrices
void multiplyMatrices(const int A[MAX][MAX], const int B[MAX][MAX], int result[MAX][MAX], int rA, int cA, int cB) {
    for (int i = 0; i < rA; i++) {
        for (int j = 0; j < cB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rowsA, colsA, rowsB, colsB;

    // --- PART A: Transpose ---
    cout << "=== PART A: TRANSPOSE ===" << endl;
    cout << "Enter number of rows: ";
    cin >> rowsA;
    cout << "Enter number of columns: ";
    cin >> colsA;

    inputMatrix(A, rowsA, colsA, "A");

    cout << "\nOriginal Matrix A:" << endl;
    printMatrix(A, rowsA, colsA);

    transposeMatrix(A, result, rowsA, colsA);
    cout << "\nTransposed Matrix:" << endl;
    printMatrix(result, colsA, rowsA);

    // --- PART B: Addition ---
    cout << "\n=== PART B: ADDITION ===" << endl;
    cout << "Matrix A and Matrix B must have the same dimensions (" << rowsA << "x" << colsA << ")." << endl;
    inputMatrix(B, rowsA, colsA, "B");

    addMatrices(A, B, result, rowsA, colsA);
    cout << "\nSum of Matrix A and Matrix B:" << endl;
    printMatrix(result, rowsA, colsA);

    // --- PART C: Multiplication ---
    cout << "\n=== PART C: MULTIPLICATION ===" << endl;
    cout << "For A x B, Matrix B must have " << colsA << " rows." << endl;
    rowsB = colsA; // Columns of A must equal Rows of B
    cout << "Enter number of columns for Matrix B: ";
    cin >> colsB;

    inputMatrix(B, rowsB, colsB, "B");

    multiplyMatrices(A, B, result, rowsA, colsA, colsB);
    cout << "\nProduct of Matrix A x Matrix B:" << endl;
    printMatrix(result, rowsA, colsB);

    return 0;
}