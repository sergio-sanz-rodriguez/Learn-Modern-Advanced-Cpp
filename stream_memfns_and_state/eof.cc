#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream ifile;
	ifile.open("input.txt");
	
	int x{0};
	
	// Wrong
	while (!ifile.eof()) {
		ifile >> x; // read from file
		cout << x << ", "; // write to cout
	}
	
	// Correct
	while (ifile >> x)
		cout << x << ", ";
	cout << endl;
}