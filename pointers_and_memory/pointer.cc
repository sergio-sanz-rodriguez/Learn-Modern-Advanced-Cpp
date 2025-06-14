#include <iostream>

using namespace std;

int main() {
	int i{1};                                 // i is a stack variable
	int *p1 = &i;                             // p1 is a pointer to int. Its value is the address of i
	cout << "p1 = " << p1 << endl;            // Displays the address of i
	cout << "*p1 = " << *p1 << endl;          // Displays the value of i
	
	int *p2 = new int;                        // p2 points to memory allocated from the heap
	int *p3 = new int{36};                    // p3 points to int with initial value 36 (C++11)
	//int *p3 = new int(36);                    // older versions of C++
    cout << "*p2 = " << *p2 << endl;
    cout << "*p3 = " << *p3 << endl;
}