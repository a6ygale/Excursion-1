#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"
#include "SparseMatrix.h"
using namespace std; 


int main(){
    
    vector<vector<double>> matrix = readNet("netlist2.txt"); 
    printVector2D(matrix); 
    
    int u = countNodes( matrix ); 
    cout<<u<<endl;

    vector<vector<double>> incidence = incidenceMatrix(matrix,u); 
    printVector2D(incidence);

    vector<vector<double>> N = NMatrix(matrix); 
    printVector2D(N);

    vector<double> uM = uMatrix(matrix); 
      for(int i=0; i<uM.size(); i++){
         cout<<uM[i]<<endl; 
    }


    return 0; 


}