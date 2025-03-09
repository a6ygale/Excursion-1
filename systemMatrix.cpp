#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

/*
created by maxbanach 3/9/2025
modified by maxbanach 3/9/2025
function to create the BIG matrix that incorporates our KVL, KCL, and ohm's law (see project documentation/presentation to understand how this is structured)
*/
vector<vector<double>> systemMatrix(vector<vector<double>> A, vector<vector<double>> N) {
    
    // edge case
    if (A.empty() || N.empty()) {  // Check if matrices are empty
        cout << "Error: A or N matrix is empty!" << endl;
        return {};  // Return empty matrix to prevent crashes
    }
    
    vector<vector<double>> AT = Transpose(A);
    int numElements = N.size();
    int numNodes = A[0].size();
    int numRows = A.size();

    // debugging size comparison test
    /*
    if (AT.size() < numElements || AT[0].size() < numNodes) {
        cout << "Error: Transposed A (AT) has incorrect dimensions!" << endl;
        cout << AT.size() << endl;
        cout << numElements << endl;
        cout << AT[0].size() << endl;
        cout << numNodes << endl;
        return {};
    }
    */

	// Create submatrices to facilitate assembly of system matrix
    vector<vector<double>> zeroBlock0(numNodes, vector<double>(AT[0].size(), 0)); // the upper-left block 
    vector<vector<double>> zeroBlock1(numNodes, vector<double>(numNodes, 0));
    vector<vector<double>> zeroBlock2(numElements, vector<double>(numNodes, 0));
    vector<vector<double>> identityM = identityMatrix(N);

    // Assemble system matrix to build return output off of
    vector<vector<double>> T;
    
    // test check sizes for loop debugging below
    // cout << numElements << endl;
    // cout << numNodes << endl;
    // cout << numRows << endl;

    // First row of form [0 0 A]
    for (int i = 0; i < numRows; i++) {
        vector<double> row;
        row.insert(row.end(), zeroBlock0[i].begin(), zeroBlock0[i].end());  // 0 block
        row.insert(row.end(), zeroBlock1[i].begin(), zeroBlock1[i].end());  // 0 block
        row.insert(row.end(), A[i].begin(), A[i].end());                    // A block
        T.push_back(row);

        // test print the row vector
        /*
        cout << "Row " << i << ": ";
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
        */

    }
 
    vector<vector<double>> negativeAT(numElements, vector<double>(numRows, 0)); // initialize negative AT w/ same size

    // test to see if creation of negativeAT is throwing error
    // printVector2D(AT);

    // Calculate and assign -AT by negating the transposed matrix AT
    for (int i = 0; i < numElements; i++) {
        for (int j = 0; j < numRows; j++) {
            negativeAT[i][j] = -AT[i][j];
        }
    }

    // test if negativeAT was created properly prior to assigning to system matrix
    // printVector2D(negativeAT);

    // Second row of form [-AT I 0]
    for (int i = 0; i < numElements; i++) {
        vector<double> row;

        // Insert the -AT block (pre-calculated negative transpose of A to not have to debug triple-nested loop)
        row.insert(row.end(), negativeAT[i].begin(), negativeAT[i].end());
        row.insert(row.end(), identityM[i].begin(), identityM[i].end());  // Identity block
        row.insert(row.end(), zeroBlock2[i].begin(), zeroBlock2[i].end()); // Zero block
        T.push_back(row);

        // Print the row vector test
        /*
        cout << "Row " << i + numRows << ": ";
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
        */

    }

    // Third row of form [0 M N]
    for (int i = 0; i < numElements; i++) {
        vector<double> row(AT[0].size(), 0);  // Zero block
        row.insert(row.end(), identityM[i].begin(), identityM[i].end());  // M = I
        row.insert(row.end(), N[i].begin(), N[i].end());  // N matrix
        T.push_back(row);

        // Print the row vector test
        /*
        cout << "Row " << i + numRows + numElements << ": ";
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
        */

    }
    
    return T;
}
