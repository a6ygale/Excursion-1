#include <iostream>
#include <vector>
using namespace std; 


///////////////////////////////////////////////////////////////////////////////////////////
//  multiplyMatrices requires 2 2D vectors
//  it returns the multiplied 2D matrix value, or returns a -1 if incompatible sizes
///////////////////////////////////////////////////////////////////////////////////////////

vector<vector<double>> multiplyMatrices(vector<vector<double>>& mat_1,vector<vector<int>>& mat_2){
    //this will be the new matrix 
    //outputted by the funct
    vector<vector<double>> newMatrix; 

    //this is a var for individual rows
    //formed for new matrix that will
    //be pushed as subvectors
    vector<double> subMatrix; 
    
    //this var is used for summation of elements
    //for each row of 1st mat mult by each col of 2nd
    int sum; 

    
    //if sizes of matrices are invalid, return -1
    if (mat_1[0].size() !=mat_2.size()){
        newMatrix = {{-1}}; 
        return newMatrix; 
    }


    //for every row in 1st array
    for (int r = 0;  r < mat_1.size(); r++){

        //for every column in second array
        for (int i = 0; i< mat_2[0].size() ; i++){

            sum = 0; //set sum of mat 1 row mult to zero

            //for every element in each row of mat 1
            //multiply by corresponding row in mat 2
            //and sum the total of that row
            for(int c=0; c < mat_1[r].size(); c++){
                sum+= mat_1[r][c]*mat_2[c][i]; 
            }

            //once the entire row is multiplied and added together,
            //push it to the submatrix, which will be a new row
            //in final matrix
            subMatrix.push_back(sum) ; 
        }
        //once all columns of 2nd row have been multiplied by a row
        //in 1st mat, push it as a row in new matrix
        newMatrix.push_back(subMatrix); 

        //clear the submatrix variable to be reused in next row
        subMatrix.clear(); 
    }

    //once all elements have been multiplied, return full matrix
    return newMatrix; 

}