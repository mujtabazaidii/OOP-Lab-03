#include<iostream>
using namespace std;
int** AllocateMemory(int& rows, int& cols) {
	int** p = new int* [rows];
	for (int i = 0; i < rows; i++) {
		p[i] = new int[cols];
	}
	return p;
}
int** InputMatrix(int** matrix, const int& rows, const int& cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
		cout << endl;
	}
	return matrix;
}
int** DisplayMatrix(int** matrix, const int& rows, const int& cols) {
	cout << endl << "Given Matrix is: " << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return matrix;
}
void DeallocateMemory(int** matrix, const int& r, const int& c) {
	for (int i = 0; i < r; i++) {
		delete matrix[i];
	}
	delete[]matrix;
}
void MaxOfColumn(int** p, int& r, int& c) {
	cout << "Maximum of each Coloumns : " << endl;
	for (int i = 0; i < c; i++) {
		int max = p[0][i];
		for (int j = 1; j < r; j++) {
			if (p[j][i] > max) {
				max = p[j][i];
			}
		}
		cout << max << "  ";
	}
}
void GetDiagonal(int** s, int& r, int& c) {
	cout << endl << "Diagonal Entries are : " << endl;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i == j) {
				cout << s[i][j] << " ";
			}
		}
	}
}
void IsMatrixUpperTriangular(int** e, int& r, int& c) {
	cout << endl;
	int t = 0;
	for (int i = 1; i < r; i++) {
		for (int j = 0; j < i; j++) {
			if (e[i][j] == 0) {
				t = 1;
			}
			else {
				t = 0;
			}
		}
	}
	if (t == 1) {
		cout << "Given Matrix is Upper Triangular.";
	}
	else {
		cout << "Given Matrix is NOT Upper Triangular.";
	}
}
int main() {
	int r, c;
	cout << "Enter rows: ";
	cin >> r;
	cout << endl;
	cout << "Enter Coloumns: ";
	cin >> c;
	int size = r * c;
	cout << endl;
	int** s = AllocateMemory(r, c);
	cout << endl;
	int** t = InputMatrix(s, r, c);
	cout << endl;
	int** u = DisplayMatrix(t, r, c); 
	cout << endl;
	MaxOfColumn(u, r, c);
	cout << endl;
	GetDiagonal(u, r, c);
	cout << endl;
	IsMatrixUpperTriangular(u, r, c);
	cout << endl;
	DeallocateMemory(u, r, c);
	cout << endl; cout << endl; cout << endl;
	return 0;
}