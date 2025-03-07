#include <iostream>
#include <vector>
using namespace std;

class SparseMatrix {
private:
	vector<vector<int>> values; // nested vector of integers
	int width;
	int height;

public:
	SparseMatrix();
	SparseMatrix(vector<vector<int>> not_sparse_matrix);
	void printSparseMatrix();
};

SparseMatrix::SparseMatrix() { // constructor
	this->values = vector<vector<int>>();
	this->width = 0;
	this->height = 0;
}

SparseMatrix::SparseMatrix(vector<vector<int>> not_sparse_matrix) {
	this->values = vector<vector<int>>();
	this->height = not_sparse_matrix.size();
	this->width = not_sparse_matrix[0].size();

	for (int r = 0; r < height; r++) {
		for (int c = 0; c < width; c++) {
			if (not_sparse_matrix[r][c] != 0) {
				vector<int> temp = { r, c, not_sparse_matrix[r][c] };
				this->values.push_back(temp);
			}
		}
	}
}

void SparseMatrix::printSparseMatrix() {
	for (int r = 0; r < this->values.size(); r++) {
		for (int c = 0; c < this->values[0].size(); c++) {
			cout << this->values[r][c] << " ";
		}
		cout << endl;
	}
}

// working test function showing output:
// 0 2 1
// 2 0 2
// showing element 1 is in the original row 0, column 2 (top right)
// and showing element 2 is in row 2, column 0 (bottom left)

/*
int main() {
	vector<vector<int>> testMatrix =
	{ {0, 0, 1},
		{0, 0, 0},
		{2, 0, 0} };

	SparseMatrix s = SparseMatrix(testMatrix);
	s.printSparseMatrix();
	return 0;
}
*/
