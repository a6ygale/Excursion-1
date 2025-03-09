#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip> // For setting decimal precision

using namespace std;

/*
created by maxbanach 3/9/2025
modified by maxbanach 3/9/2025
function to output vector to file
*/

void toFile(vector<double> W) {
    ofstream outFile("output.txt");

    // edge case error handler
    if (!outFile) {
        cout << "Unable to open write file error" << endl;
        return;
    }

    // set to 3 decimal precision per assignment guideline
    outFile << fixed << setprecision(3);

    // output to outFile with one space inbetween
    for (int i = 0; i < W.size(); i++) {
        outFile << W[i];
        if (i < W.size() - 1) {
            outFile << " "; // space as required
        }
    }

    outFile << endl;
    outFile.close(); // make sure to close

    cout << "Output printed to output.txt." << endl;
}
