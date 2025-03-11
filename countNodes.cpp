#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Abby Cochrane
///////////////////////////////////////////////////////////////////////////////////////////
//  countNodes requires a 2D vector input and finds the highest
//  node from the netlist, returning the integer number of 
//  nodes in the circuit of interest
///////////////////////////////////////////////////////////////////////////////////////////

int countNodes(vector<vector<double>> elements) {
    int n = 0; 
    for (int i=0; i<elements.size(); i++){
        //checking for highest value
         if(elements[i][1]>n){
             n=elements[i][1]; 
         }
         if(elements[i][2]>n){
             n=elements[i][2]; 
         }
    }
    return n+1; 

}
