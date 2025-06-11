#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream ofile{"log.txt"};
	
	if (!ofile) {
		cout << "Could not open file\n";
		return -1;
	}
	
	for (int i = 0; i < 1'000'000; ++i) {
		cout << i << "\n" << flush; // equivalent cout << i << endl; endl is equivalent to new line followed by flush
		ofile << i << "\n" << flush; // equivalent cout << i << endl;
		
		if (i == 66666)
        {                        
			throw std::exception();
        }
	}
	
	ofile.close();
} 