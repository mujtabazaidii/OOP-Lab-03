#include<iostream>
using namespace std;
void Election(char** canidates, const int* Votes, double* percentage, const int& size) {
	int win = 0;
	int c = 0;
	cout << endl << endl << "  Canidate \t\t\t Votes Received \t\t\t % Total Votes" << endl;
	for (int i = 0; i < size; i++) {
		cout <<"  " << canidates[i] << "\t\t\t\t" << Votes[i] << "\t\t\t\t\t" << percentage[i] << endl;
	}
	for (int i = 0; i < size; i++) {
		if (Votes[i] > win) {
			win = Votes[i];
			c = i;
		}
	}
	cout << endl << "The Winner of the election is : [" << canidates[c] <<"]" << endl;
}
int main() {
	int size;
	double sum = 0;
	cout << "Enter Number of Canidates: ";
	cin >> size;
	cout << endl;
	char** s = new char* [size];
    for (int i = 0; i < size; i++) {
		s[i] = new char[20];
	}
	int* votes = new int[size];
	double* percent = new double[size];

	for (int i = 0; i < size; i++) {
		cout << i + 1 << ". Enter Name and Votes: ";
		cin >> s[i] >> votes[i];
		cout << endl;
		sum += votes[i];
	}
	for (int i = 0; i < size; i++){
		percent[i] = (votes[i] * 100) / sum;
	}
	cout << endl;
	Election(s, votes, percent, size);


	return 0;
}