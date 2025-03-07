#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "functions.h"
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////
//  Transpose requires a 2D vector input and switches
//  all row and column elements, returning the transposed matrix
///////////////////////////////////////////////////////////////////////////////////////////


vector<vector<int>> Transpose(vector<vector<int>> matrix){
    vector<vector<int>> MT;
    vector<int> newRow; 
    for(int i =0 ; i< matrix[0].size(); i++){
        newRow = {}; 
        for(int j =0; j<matrix.size(); j++){
            newRow.push_back(matrix[j][i]); 
        }
        MT.push_back(newRow); 
    }
    return MT;
}
