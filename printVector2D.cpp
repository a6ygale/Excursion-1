#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std; 

//takes in 2D matrix and prints to check outputs
void printVector2D(vector<vector<int>> e){
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