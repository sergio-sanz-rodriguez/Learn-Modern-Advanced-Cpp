#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> names ={"Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally"};

	cout << "Vector before sort()\n";
	for (auto name : names)
		cout << name << ", ";
	cout << endl << endl;

	sort(begin(names), end(names), less<string>()); //cbegin, cend cannot be implemented because it would not allow to modify the vector values, when you order, the elements are modified.

	cout << "Vector after sort() with std::less\n";
	for (auto name : names)
		cout << name << ", ";
	cout << endl;
}