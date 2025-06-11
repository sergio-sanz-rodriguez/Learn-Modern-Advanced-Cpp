#include <iostream>

using namespace std;

int main() {
	cout << "Enter some text:" << endl;
	
	char c;
	while (cin.get(c))              // Read a character until we get end-of-input
		cout.put(c);                   // Display the character

    //const size_t BUFFER_SIZE = 1024;
    //char buffer[BUFFER_SIZE];

    //while (cin.read(buffer, BUFFER_SIZE) || cin.gcount() > 0) {
    //    // cin.read(...) reads up to BUFFER_SIZE characters
    //    // cin.gcount() returns the number of characters actually read
    //    cout.write(buffer, cin.gcount());
    //    //cout.flush();
    //}

    //return 0;
}