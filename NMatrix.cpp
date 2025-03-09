#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;

// Abby Cochrane

///////////////////////////////////////////////////////////////////////////////////////////
//  NMatrix requires a 2D vector input 
//  it returns the identity matrix of resistance values 
//  along it's diagonal and inputs a 0 for a voltage source
///////////////////////////////////////////////////////////////////////////////////////////

vector<vector<double>> NMatrix(vector<vector<double>> elements)
{
    int size = elements.size(); //size is equal to number of elements

    vector<vector<double>> NM;//this will store our final N matrix
    vector<double> rowM; //this will store our individual rows of N matrix


    for (int i = 0; i < size; i++)
    {
        rowM = {}; //empty vector
        for (int j = 0; j < size; j++)
        {
            if (i == j && elements[i][0] == 1)
            {
                rowM.push_back(0 - elements[i][3]); //if on diagonal, value is 1
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