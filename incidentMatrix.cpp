#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Abby Cochrane
///////////////////////////////////////////////////////////////////////////////////////////
//  incidenceMatrix requires a 2D vector input and number of nodes
//  it returns the incidence matrix representing inputs and outputs
//  with respect to nodes and elements in the circuit
///////////////////////////////////////////////////////////////////////////////////////////


vector<vector<double>> incidenceMatrix(vector<vector<double>> elements, int nodes) {

    vector<vector<double>> incidenceMT; //will store the full incidence matrix
    vector<double> colM; //will store column of incidence matrix

    for (int i = 0; i < elements.size(); i++) {

        colM = {}; //starts with empty column

        //creating transpose of incidence first because its easier

        //iterates through all nodes, j=1 skipping over node 0 for reduced matrix
        for (int j = 1; j < nodes; j++) {

            //if the node is a source for element i add a 1 in it's place
            if (elements[i][1] == j) {
                colM.push_back(1);
            }

            //if the node is a destination for element i add a -1 in it's place
            else if (elements[i][2] == j) {
                colM.push_back(-1);
            }

            //if the node is not attached to the element push a 0
            else {
                colM.push_back(0);
            }
        }

        incidenceMT.push_back(colM);

    }

    //transposing it to be the right orientation
    return Transpose(incidenceMT);

}
