#include <iostream>
#include <limits>

using namespace std;

int main() {
	int x{0};
    const size_t max_num = numeric_limits<streamsize>::max();
    cout << "max number: " << max_num << endl;
	cout << "Please enter a number: ";
	cin >> x;

	bool success{false};
	while (!success) {
		if (cin.good()) {
			cout << "You entered the number " << x << "\n";
			success = true;
		}	
		else if (cin.fail()) {   
			cout << "Please try again and enter a number\n";
			cin.clear();
			//cin.ignore(20, '\n');                // Remove next 20 characters or everything up to next newline
			cin.ignore(max_num, '\n'); // 9223372036854775807
			cin >> x;
		}
	}
}