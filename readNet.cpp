#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std; 


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
