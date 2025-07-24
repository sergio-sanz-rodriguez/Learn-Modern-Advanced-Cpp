#include <iostream>

using namespace std;

class Test {
    public:
        Test() { cout << "Default constructor\n"; }
        Test(const Test& other) { cout << "Copying\n"; }  // Copy constructor with side effect
};

// Function returning a temporary object
//Calls the default constructor: "Default constructor"
//Returns a temporary object → causes a copy constructor call to return the object (Copying).
Test func() {                                                            
    return Test();
}

int main() {
	cout << "Calling func()" << endl;
    //Initializes test using the result of func() → causes another copy: Copying
	Test test = func();                 // How many times is "Copying" printed out?
	cout << "Returned from func()" << endl;
}
