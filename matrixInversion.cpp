#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "functions.h"
using namespace std;

/*
created by maxbanach 3/9/2025
modified by maxbanach 3/9/2025
function to invert a square matrix, second function to multiply a matrix by a vector
*/

// Function to perform Gaussian elimination and return the inverse of a matrix
vector<vector<double>> invertMatrix(vector<vector<double>> matrix) {
    int n = matrix.size();

    // Make identity matrix of size n
    vector<vector<double>> id = identityMatrix(matrix); // id used as i utilized for for loops in this function

    // Generate augmented matrix [ T | I ]
    vector<vector<double>> augMat(n, vector<double>(2 * n));

    // Fill the augmented matrix [ T | I ]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            augMat[i][j] = matrix[i][j];
            augMat[i][j + n] = id[i][j]; // Identity matrix on the right
        }
    }

    // Perform Gaussian elimination with partial pivoting
    for (int i = 0; i < n; i++) {
        // Find the pivot element
        double maxVal = fabs(augMat[i][i]); // absolute value
        int maxRow = i; // stores max row as we progress through matrix of size n

        // Find the row with the largest element in the column to utilize
        for (int k = i + 1; k < n; k++) {
            if (fabs(augMat[k][i]) > maxVal) {
                maxVal = fabs(augMat[k][i]);
                maxRow = k;
            }
        }

        // error handling - if the pivot element = 0, the matrix is un-invertible
        if (maxVal == 0) {
            cout << "Unable to invert matrix" << endl;
            return {};
        }

        // swap rows to properly orient pivot element
        if (maxRow != i) {
            swap(augMat[i], augMat[maxRow]);
        }

        // pivot - make the diagonal element 1
        double pivot = augMat[i][i];

        for (int j = 0; j < 2 * n; j++) {
            augMat[i][j] /= pivot; // divide augmented matrix by pivot (largest val)
        }

        // remove all other elements in the column
        for (int j = 0; j < n; j++) {
            
            if (i != j) {
                double fac = augMat[j][i];
                for (int k = 0; k < 2 * n; k++) {
                    augMat[j][k] -= fac * augMat[i][k];
                }
            }

        }
    }

    // Extract the inverse matrix from the augmented matrix
    vector<vector<double>> inverse(n, vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            inverse[i][j] = augMat[i][j + n];  // Right side of the augmented matrix
        }
    }

    return inverse;
}

// Function to multiply matrix (Tinv) by vector (u)
vector<double> multiplyMatrixVector(vector<vector<double>> matrix, vector<double> u) {
    
    int n = matrix.size();
    vector<double> result(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i] += matrix[i][j] * u[j];
        }
    }

    return result;
}
