#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//#include "functions.h"
using namespace std;

vector<vector<int>> MT;
vector<int> newRow; 

vector<vector<int>> Transpose(vector<vector<int>> matrix){
    for(int i =0 ; i< matrix[0].size(); i++){
        newRow = {}; 
        for(int j =0; j<matrix.size(); j++){
            newRow.push_back(matrix[j][i]); 
        }
        MT.push_back(newRow); 

    }
    //  //testing
    // for (int x=0; x<3; x++){
    //     for(int y=0; y<3; y++){
    //         cout<<MT[x][y]<<endl; 
    //     }
    // } 
    return MT;
}