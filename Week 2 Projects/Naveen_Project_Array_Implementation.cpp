#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    // matrix dimensions
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[50][50];  // assuming this for simplicity

    cout << "Enter the matrix elements (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    // non-zero elements count
    int nonZero = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {    
                nonZero++;
            }
        }
    }

    // sparse data array
    int rowIndex[nonZero], colIndex[nonZero], values[nonZero];
    int k = 0; // sparse index
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                rowIndex[k] = i;
                colIndex[k] = j;
                values[k] = matrix[i][j];
                k++;
            }
        }
    }

    // actual matrix
    cout << "\nOriginal Matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // sparse matrix
    cout << "\nSparse Matrix Representation:\n";

    cout << "Row:    ";
    for (int i = 0; i < nonZero; i++) {
        cout << rowIndex[i] << " ";
    }
    cout << endl;

    cout << "Column: ";
    for (int i = 0; i < nonZero; i++) {
        cout << colIndex[i] << " ";
    }
    cout << endl;

    cout << "Value:  ";
    for (int i = 0; i < nonZero; i++) {
        cout << values[i] << " ";
    }
    cout << endl;

    return 0;
}
