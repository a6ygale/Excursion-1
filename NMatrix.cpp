#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "functions.h"
using namespace std;


vector<vector<int>> NM;
vector<int> coM;
vector<vector<int>> NMatrix(vector<vector<int>> elements)
{
    int size=elements.size(); //size is equal to number of elements


    for (int i=0; i<size; i++)
    {
        coM = {}; //empty vector
        for (int j=0; j<size; j++)
        {
            if (i==j && elements[i][0]==1)
            {
                coM.push_back(0-elements[i][3]); //if on diagonal, value is 1
            }
            else
            {
                coM.push_back(0);//everything else 0
            }
        }
        NM.push_back(coM); // push column to matrix
    }
    return NM;
}