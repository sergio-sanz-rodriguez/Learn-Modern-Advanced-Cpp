#include <iostream>
#include <string>

using namespace std;
using namespace std::literals;

class String {
	string s;
public:
	// Constructors
	String(const string& s) : s(s) {}
	String(): String("null") {}

	// Copy constructor
	String(const String& arg) : s(arg.s) {}
	
	void print() { cout << s << endl; }
};

int main() {
	String w { "world"s };   // Call constructor
    String w2;
	String bang { w };       // Call copy constructor
	String bang2 = w;        // Call copy constructor
	
	cout << "w = "; w.print();
    cout << "w2 = "; w2.print();
	cout << "bang = "; bang.print();
	cout << "bang2 = "; bang2.print();
    cout << &w << endl;
    cout << &w2 << endl;
    cout << &bang << endl;
    cout << &bang2 << endl;
}