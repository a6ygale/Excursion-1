#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; 
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


vector<vector<int>> readNet(string filename); 
int countNodes(vector<vector<int>> elements); 
vector<vector<int>> incidentMatrix(vector<vector<int>> elements, int nodes); 
vector<vector<int>> Transpose(vector<vector<int>> matrix); 


#endif