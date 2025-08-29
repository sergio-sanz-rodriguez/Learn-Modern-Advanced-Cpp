#include <iostream>

using namespace std;

int main() {
	int z = 1;                                                     // Scope's local variable y
	auto add_z_plus1 = [y = z+1](int x){ return x + y; };          // Lambda body's local variable y1
	
	cout << "Calling add_z_plus1(2) gives " << add_z_plus1(2) << endl;
	cout << "Calling add_z_plus1(5) gives " << add_z_plus1(5) << endl;

    // My proposal?
    auto add_z_plus1_2 = [z](int x) {auto y = z + 1; return x + y; };

    cout << "Calling add_z_plus1_2(2) gives " << add_z_plus1_2(2) << endl;
	cout << "Calling add_z_plus1_2(5) gives " << add_z_plus1_2(5) << endl;

}