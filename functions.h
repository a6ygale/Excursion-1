#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std; 
#ifndef FUNCTIONS_H
#define FUNCTIONS_H


///////////////////////////////////////////////////////////////////////////////////////////
//  readNet requires a string filename in text format,
//  returning all information contained as 
//  row = element of circuit
//  row[0] = 0 or one (V/R respectively)
//  row[1] = source node
//  row[2] = destination node
//  row[3] = value of element voltage or resistance
///////////////////////////////////////////////////////////////////////////////////////////

vector<vector<double>> readNet(string filename){

    //2d matrix holding values [V/R] [S] [D] [Val]
    //with every column as new element
    vector<vector<double>> elements; 
    vector<double> column; 
    string value; 

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
                column.push_back(std::stod(string(value)));
            }
        }

        //once the column is full in correct datatype, add it as column in new matrix
        elements.push_back(column);//add all parsed values from txt into column of matrix

     }
    file.close();

    return elements; 
}


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


///////////////////////////////////////////////////////////////////////////////////////////
//  Transpose requires a 2D vector input and switches
//  all row and column elements, returning the transposed matrix
///////////////////////////////////////////////////////////////////////////////////////////


vector<vector<double>> Transpose(vector<vector<double>> matrix){
    vector<vector<double>> MT;
    vector<double> newRow; 
    for(int i =0 ; i< matrix[0].size(); i++){
        newRow = {}; 
        for(int j =0; j<matrix.size(); j++){
            newRow.push_back(matrix[j][i]); 
        }
        MT.push_back(newRow); 
    }
    return MT;
}



///////////////////////////////////////////////////////////////////////////////////////////
//  countNodes requires a 2D vector input and counts all mentions
//  of a node from the netlist, returning the integer number of 
//  nodes in the circuit of interest
///////////////////////////////////////////////////////////////////////////////////////////

int countNodes(vector<vector<double>> elements){

    //start off with zero node only included in vect of nodes
    //mentioned within netlist
    vector<double> uniqueNodes = {0};

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



///////////////////////////////////////////////////////////////////////////////////////////
//  incidenceMatrix requires a 2D vector input and number of nodes
//  it returns the incidence matrix representing inputs and outputs
//  with respect to nodes and elements in the circuit
///////////////////////////////////////////////////////////////////////////////////////////


vector<vector<double>> incidenceMatrix(vector<vector<double>> elements, int nodes){

    vector<vector<double>> incidenceMT; //will store the full incidence matrix
    vector<double> colM; //will store column of incidence matrix

    for(int i=0;i<elements.size(); i++){

        colM = {}; //starts with empty column

        //creating transpose of incidence first because its easier

        //iterates through all nodes, j=1 skipping over node 0 for reduced matrix
        for(int j=1;j<nodes; j++){

            //if the node is a source for element i add a 1 in it's place
            if (elements[i][1]==j){
                colM.push_back(1); 
            }

            //if the node is a destination for element i add a -1 in it's place
            else if (elements[i][2]==j){
                colM.push_back(-1); 
            }

            //if the node is not attached to the element push a 0
            else {
                colM.push_back(0); 
            }
        }

        incidenceMT.push_back(colM); 
        
    }

    //transposing it to be the right orientation
    return Transpose(incidenceMT); 

}


///////////////////////////////////////////////////////////////////////////////////////////
//  NMatrix requires a 2D vector input 
//  it returns the identity matrix of resistance values 
//  along it's diagonal and inputs a 0 for a voltage source
///////////////////////////////////////////////////////////////////////////////////////////

vector<vector<double>> NMatrix(vector<vector<double>> elements)
{
    int size=elements.size(); //size is equal to number of elements

    vector<vector<double>> NM;//this will store our final N matrix
    vector<double> rowM; //this will store our individual rows of N matrix


    for (int i=0; i<size; i++)
    {
        rowM = {}; //empty vector
        for (int j=0; j<size; j++)
        {
            if (i==j && elements[i][0]==1)
            {
                rowM.push_back(0-elements[i][3]); //if on diagonal, value is 1
            }
            else
            {
                rowM.push_back(0);//everything else 0
            }
        }
        NM.push_back(rowM); // push column to matrix
    }
    return NM;
}

///////////////////////////////////////////////////////////////////////////////////////////
//  uMatrix requires a 2D vector input 
//  it returns a 1D array with voltage magnitudes of corresponding elements
//  or a 0 in the case that the element is not a voltage supply
///////////////////////////////////////////////////////////////////////////////////////////

vector<double> uMatrix(vector<vector<double>> Melements){
    vector<double> uM = {}; //creates an empty vector to store u values

    for (int i=0; i<Melements.size(); i++){
        //if the element is a voltage source add value
        if (Melements[i][0]==0){
            uM.push_back(Melements[i][3]); 
        }
        //if not push a zero
        else{
            uM.push_back(0); 
        }
    }
    return uM; 
}


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


///////////////////////////////////////////////////////////////////////////////////////////
//  identityMatrix requires a 2D vector input and switches
//  creates an identity matrix with elements x elements dimenisions
///////////////////////////////////////////////////////////////////////////////////////////


vector<vector<int>> identityMatrix(vector<vector<int>> elements)
{
    vector<vector<int>> identityM;
    vector<int> coM;  

    int size=elements.size(); //size is equal to number of elements

    for (int i=0; i<size; i++)
    {
        coM = {}; //empty vector
        for (int j=0; j<size; j++)
        {
            if (i==j)
            {
                coM.push_back(1); //if on diagonal, value is 1
            }
            else
            {
                coM.push_back(0);//everything else 0
            }
        }
        identityM.push_back(coM); // push column to matrix
    }
    return identityM;
}


#endif