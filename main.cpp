#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <fstream>
#include "functions.h"
#include "SparseMatrix.h"

using namespace std;

// see readme file for information on how to run this program!
int main() {

    vector<vector<double>> matrix = readNet("netlist.txt");
    printVector2D(matrix);
    cout << endl;

    int nodes = countNodes(matrix);
    cout << nodes << endl;
    cout << endl;

    vector<vector<double>> A = incidenceMatrix(matrix, nodes); // A = reduced incidence matrix
    printVector2D(A);
    cout << endl;

    vector<vector<double>> N = NMatrix(matrix);
    printVector2D(N);
    cout << endl;

    // RHS of combined matrix, u
    vector<double> us = uMatrix(matrix);
    for (int i = 0; i < us.size(); i++) {
        cout << us[i] << endl;
    }
    cout << endl;

    // we need two blocks of zeroes on the RHS above us, the first the size (# of rows) of A (as the LHS first row contains A) . . .
    // and the second block the same size as us, -At, M, and N (should all be the # of nodes)
    vector<double> zeroBlock(vector<double>(A.size()+us.size(), 0));
    // printVector2D(zeroBlock);
    
    // RHS of combined matrix, u
    vector<double> u = us; // mirror us for u first (bottom-most block)
	u.insert(u.begin(), zeroBlock.begin(), zeroBlock.end()); // add the zero block to the top of u
    
    /* test print of u
    for (int i = 0; i < u.size(); i++) {
        cout << u[i] << endl;
    }
    */

    // vector<vector<double>> identityM = identityMatrix(N);
    // printVector2D(identityM);

    // LHS of combined matrix, T
    vector<vector<double>> T = systemMatrix(A, N);
    // printVector2D(T);

    vector<vector<double>> Tinv = invertMatrix(T);
    // printVector2D(Tinv);

	vector<double> w = multiplyMatrixVector(Tinv, u);
    
    // test print output vector w prior to writing to file
    /*
    for (int i = 0; i < w.size(); i++) {
        cout << w[i] << endl;
    }

    return 0;
    */

    toFile(w);

}