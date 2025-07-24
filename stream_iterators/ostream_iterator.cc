#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

int main() {
	// Write the numbers 0, ..., 9 to the display followed by a newline
	ostream_iterator<int> oi(cout, "\n");              // Create the output stream iterator

	for (int i = 0; i < 10; ++i) {
		*oi = i;                                       // Prints the number followed by "\n"
		++oi;                                          // Move to next element in sequence
	}

    // My approach
    
    ostringstream os;
    ostream_iterator<int> oi2(os, "\n");

    *oi2 = 100;
    cout << os.str() << endl;

}