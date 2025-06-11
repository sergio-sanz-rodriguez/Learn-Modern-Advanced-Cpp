#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

template <typename T>
string To_String(const T& t) {
	ostringstream os;
	os << t;
	return os.str();
}

template <typename T>
string To_String_2(const T& t, int p) {
	ostringstream os;
	os << setprecision(p) << t;
	return os.str();
}

int main() {
	string hello { "Hello, " };

    //ostringstream os;
    //os << fixed << setprecision(6) << 3.14159;
    //string pi = os.str();

	string pi { To_String_2(3.14159265359, 10) };
	hello += pi;
	cout << hello << endl;
}