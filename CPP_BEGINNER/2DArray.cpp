#include <iostream>
using namespace std;

const int MAX = 100;

void inputMatrix(int M[][MAX], int row, int col) {
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> M[i][j];
}

void displayMatrix(int M[][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << M[i][j] << " ";
        cout << endl;
    }
}

void sumOfMatrix(int A[][MAX], int B[][MAX], int row, int col) {
    int sum[MAX][MAX];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            sum[i][j] = A[i][j] + B[i][j];

    cout << "\nMatrix Addition:\n";
    displayMatrix(sum, row, col);
}

void diffOfMatrix(int A[][MAX], int B[][MAX], int row, int col) {
    int diff[MAX][MAX];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            diff[i][j] = A[i][j] - B[i][j];

    cout << "\nMatrix Subtraction:\n";
    displayMatrix(diff, row, col);
}

void transposeMatrix(int M[][MAX], int row, int col) {
    int transpose[MAX][MAX];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            transpose[j][i] = M[i][j];

    cout << "\nTranspose:\n";
    displayMatrix(transpose, col, row);
}

void diagonalSum(int M[][MAX], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += M[i][i];

    cout << "\nDiagonal Sum = " << sum << endl;
}

void multiplyMatrix(int A[][MAX], int B[][MAX], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        cout << "\nMatrix multiplication not possible! (cols of A ? rows of B)\n";
        return;
    }

    int result[MAX][MAX] = {0};

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatrix Multiplication:\n";
    displayMatrix(result, row1, col2);
}

int main() {
    int rows, cols;

    cout << "Enter rows and columns for matrices: ";
    cin >> rows >> cols;

    int A[MAX][MAX], B[MAX][MAX];

    cout << "\nInput Matrix A:\n";
    inputMatrix(A, rows, cols);

    cout << "\nInput Matrix B:\n";
    inputMatrix(B, rows, cols);

    cout << "\nMatrix A:\n";
    displayMatrix(A, rows, cols);

    cout << "\nMatrix B:\n";
    displayMatrix(B, rows, cols);

    sumOfMatrix(A, B, rows, cols);
    diffOfMatrix(A, B, rows, cols);
    transposeMatrix(A, rows, cols);

    if (rows == cols)
        diagonalSum(A, rows);
    else
        cout << "\nDiagonal sum only works for square matrices!\n";

    multiplyMatrix(A, B, rows, cols, rows, cols);

    return 0;
}

