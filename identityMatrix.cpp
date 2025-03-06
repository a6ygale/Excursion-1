/*
created by  vandalld 3/6/25
modified by vandalld 3/6/25
creates an identity matrix (M) of size (elements)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> identityM;
vector<int> coM;  

vector<vector<int>> identityMatrix(vector<vector<int>> elements)
{
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