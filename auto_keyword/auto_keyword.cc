#include <iostream>
#include <string>

using namespace std;

int main() {
	auto i{42};                       // Type of i is deduced as int
	auto str1 = "Hello";              // Type of str1 is deduced as const char*
	auto str2 = "Hello"s;             // Type of str2 is deduced as std::string

	cout << "i * 2 = " << i * 2 << endl;
	auto it = str2.begin();
	cout << "First element of str2: " << *it << endl;

    const int& x{6};
    auto y = x; //this is a copy of x, as compile guesses that x is int. Const and reference are ignored!
    const auto& z = x;
    ++y;
    
    cout << y << endl;
    cout << x << endl;
    cout << z << endl;


} 