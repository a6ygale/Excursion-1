#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Abby Cochrane
///////////////////////////////////////////////////////////////////////////////////////////
//  uMatrix requires a 2D vector input 
//  it returns a 1D array with voltage magnitudes of corresponding elements
//  or a 0 in the case that the element is not a voltage supply
///////////////////////////////////////////////////////////////////////////////////////////

vector<double> uMatrix(vector<vector<double>> Melements) {
    vector<double> uM = {}; //creates an empty vector to store u values

    for (int i = 0; i < Melements.size(); i++) {
        //if the element is a voltage source add value
        if (Melements[i][0] == 0) {
            uM.push_back(Melements[i][3]);
        }
        //if not push a zero
        else {
            uM.push_back(0);
        }
    }
    return uM;
}