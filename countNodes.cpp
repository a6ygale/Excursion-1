#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Abby Cochrane
///////////////////////////////////////////////////////////////////////////////////////////
//  countNodes requires a 2D vector input and counts all mentions
//  of a node from the netlist, returning the integer number of 
//  nodes in the circuit of interest
///////////////////////////////////////////////////////////////////////////////////////////

int countNodes(vector<vector<double>> elements) {


    
    //start off with zero node only included in vect of nodes
    //mentioned within netlist
    vector<double> uniqueNodes = { 0 };

    for (int i = 0; i < elements.size(); i++) {//for every column in matrix

        int a = 0; //incrementing over existing nodes in uniqueNodes vector
        bool unique_1 = 1;
        bool unique_2 = 1;

        //checking if there's mention of the node before or if its new
        while (a < uniqueNodes.size()) {
            if (elements[i][1] == uniqueNodes[a]) {
                unique_1 = 0;
            }
            if (elements[i][2] == uniqueNodes[a]) {
                unique_2 = 0;
            }
            a++;
        }

        //if we havent found mention of the node, add it to uniqueNode
        if (unique_1 == 0) {
            uniqueNodes.push_back(elements[i][1]);
        }

        if (unique_2 == 0) {
            uniqueNodes.push_back(elements[i][2]);
        }
    }
    return uniqueNodes.size();
    
}
