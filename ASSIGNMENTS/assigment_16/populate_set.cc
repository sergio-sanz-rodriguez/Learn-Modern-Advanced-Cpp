#include <iostream>
#include <set>
#include <vector>

using namespace std;

extern "C" {
	#include "array.h"
}

using namespace std;

int main() {
	set<int> myset{3, 1, 4, 1, 5, 9};
	
	cout << "Set elements: ";
	for (auto s : myset)
		cout << s << ", ";
	cout << endl;
	
	cout << "Calling array_print(): ";
    vector<int> myvec(myset.size());
    copy(begin(myset), end(myset), myvec.begin());
	array_print(myvec.data(), myvec.size());

    return 0;
}