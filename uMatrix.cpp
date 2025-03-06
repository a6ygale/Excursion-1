//creates u 1D column matrix indicating voltage supply values or 0 for resistor element


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

vector<int> uM; 

vector<int> uMatrix(vector<vector<int>> Melements){
    uM = {}; //create empty vector
    for (int i=0; i<Melements.size(); i++){
        //if the element is a voltage source add value
        if (Melements[i][0]==0){
            uM.push_back(Melements[i][3]); 
        }
        //if not push a zero
        else{
            uM.push_back(0); 
        }
    }
    return uM; 
}