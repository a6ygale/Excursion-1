#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

// Abby Cochrane
///////////////////////////////////////////////////////////////////////////////////////////
//  printVector2D requires a 2D vector input and prints all
//  elements in terminal to check outputs of various functions
///////////////////////////////////////////////////////////////////////////////////////////

/*
void printVector2D(vector<vector<double>> e) {
    for (int x = 0; x < e.size(); x++) {
        for (int y = 0; y < e[0].size(); y++) {
            if (y == 0) {
                cout << "[" << e[x][y];
            }
            else {
                cout << "," << e[x][y];
            }
        }
        cout << "]" << endl;
    }
}
*/

// updated function to be able to print more complex matrices 
void printVector2D(vector<vector<double>> e) {
    // edge case
    if (e.empty()) {  // Check if the matrix is empty
        cout << "Matrix is empty!" << endl;
        return;
    }

    for (int x = 0; x < e.size(); x++) {
        if (e[x].empty()) {  // Ensure row is not empty before accessing it
            cout << "Error: Row " << x << " is empty!" << endl;
            continue;
        }

        for (int y = 0; y < e[x].size(); y++) {  // Use e[x].size() instead of e[0].size()
            if (y == 0) {
                cout << "[" << e[x][y];
            }
            else {
                cout << ", " << e[x][y];
            }
        }
        cout << "]" << endl;
    }
}
