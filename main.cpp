#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "functions.h"
using namespace std; 

//2d matrix holding values [V/R] [S] [D] [Val]
//with every column as new element
vector<vector<int>> elements; 
vector<int> column; 
string value; 


//creates matrix from text file
vector<vector<int>> readNet(string filename){
    ifstream file(filename);
    string line; //holds a line in txt file as string
    
    while (getline(file, line)) {
        int j=0; //iterates through characters in string
        column = {};//clears array that we will load data into
        for(int k=0; k<4;k++){//expecting 4 values per line
            value = ""; //clears string that we will use to collect individual values
            while(line[j]!=' '&& line[j]!=NULL){//parses sting and adds data to column vector
                value = value +line[j];
                j++;  
                
            }
            j+=1;//once we hit blank space skip over

            //putting characters into int values and adding them to
            //sub vector for column

            //V=0
            if (value[0] == 'V'){
                column.push_back(0);
            }

            //R=1
            if (value[0] == 'R'){
                column.push_back(1);
            }

            //if its already a digit go ahead and add it
            if(isdigit(value[0])){
                column.push_back(std::stoi(string(value)));
            }
        }

        //once the column is full in correct datatype, add it as column in new matrix
        elements.push_back(column);//add all parsed values from txt into column of matrix

     }
    file.close();

    // //testing
    // for (int x=0; x<3; x++){
    //     for(int y=0; y<4; y++){
    //         cout<<elements[x][y]<<endl; 
    //     }
    // }
    // return elements; 
}

//once be have number of nodes, branches will be nodes-1 
vector<int> uniqueNodes = {0};

//adds every unique mention of a node to vector and returns size
int countNodes(vector<vector<int>> elements){
    for(int i=0; i< elements.size(); i++){//for every column in matrix
        
        int a=0 ; //incrementing over existing nodes in uniqueNodes vector
        bool unique_1 = 1;
        bool unique_2 = 1; 

        //checking if there's mention of the node before or if its new
        while(a<uniqueNodes.size()){
            if (elements[i][1]==uniqueNodes[a]){
                unique_1 = 0; 
            }
            if (elements[i][2]==uniqueNodes[a]){
                unique_2 = 0; 
            }
            a++; 
        }

        //if we havent found mention of the node, add it to uniqueNode
        if (unique_1 == 0){
            uniqueNodes.push_back(elements[i][1]);
        }

        if (unique_2 == 0 ){
            uniqueNodes.push_back(elements[i][2]);
        }

    }

    return uniqueNodes.size(); 


}
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

vector<vector<int>> multiplyMatrices(vector<vector<int>>& mat_1,vector<vector<int>>& mat_2){
    //this will be the new matrix 
    //outputted by the funct
    vector<vector<int>> newMatrix; 

    //this is a var for individual rows
    //formed for new matrix that will
    //be pushed as subvectors
    vector<int> subMatrix; 
    
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






////////////////////////////////////
//////////////////////////////////////
////////////////////////////////////
///////////////////////////////////






int main(){
    
    vector<vector<int>> matrix = readNet("netlist.txt"); 
    int u = countNodes( matrix ); 
    //cout<<u<<endl;
    vector<vector<int>> inc = incidentMatrix(matrix,u); 
    //testing
    for (int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            cout<<inc[x][y]<<endl; 
        }
    }
    

    return 0; 


}