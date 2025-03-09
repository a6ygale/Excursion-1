#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; 
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


vector<vector<double>> readNet(string filename); 
int countNodes(vector<vector<double>> elements);
vector<vector<double>> Transpose(vector<vector<double>> matrix);
vector<vector<double>> identityMatrix(vector<vector<double>> elements);
vector<vector<double>> incidenceMatrix(vector<vector<double>> elements, int nodes); 
void printVector2D(vector<vector<double>> e);
vector<double> uMatrix(vector<vector<double>> Melements);
vector<vector<double>> NMatrix(vector<vector<double>> elements);
vector<vector<double>> systemMatrix(vector<vector<double>> A, vector<vector<double>> N);
vector<vector<double>> invertMatrix(vector<vector<double>> matrix);
vector<double> multiplyMatrixVector(vector<vector<double>> matrix, vector<double> u);
void toFile(vector<double> W);

#endif