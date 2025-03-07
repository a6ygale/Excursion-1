#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std; 

///////////////////////////////////////////////////////////////////////////////////////////
//  printVector2D requires a 2D vector input and prints all
//  elements in terminal to check outputs of various functions
///////////////////////////////////////////////////////////////////////////////////////////


void printVector2D(vector<vector<double>> e){
    for (int x=0; x<e.size(); x++){
        for(int y=0; y<e[0].size(); y++){
            if(y==0){
                cout<<"["<<e[x][y];
            }
            else{
                cout<<","<<e[x][y]; 
            } 
        }
        cout<<"]"<<endl;
    }
}
