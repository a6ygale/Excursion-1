#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "functions.h"
using namespace std;

vector<vector<int>> incidentMT;
vector<int> colM;  

vector<vector<int>> incidentMatrix(vector<vector<int>> elements, int nodes){
    for(int i=0;i<elements.size(); i++){
        colM = {}; 
        for(int j=0;j<nodes; j++){
            if (elements[i][1]==j){
                colM.push_back(1); 
            }
            else if (elements[i][2]==j){
                colM.push_back(-1); 
            }
            else {
                colM.push_back(0); 
            }
        }
        incidentMT.push_back(colM); 
    }
        // //testing
        // for (int x=0; x<3; x++){
        //     for(int y=0; y<3; y++){
        //         cout<<incidentMT[x][y]<<endl; 
        //     }
        // }
        return Transpose(incidentMT); 


}

