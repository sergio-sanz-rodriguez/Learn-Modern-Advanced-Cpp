#include <iostream>
#include <map>
#include <vector>

using namespace std;

extern "C" {
	#include "array.h"
}

using namespace std;

int main() {
	map<int,int> mymap{{0, 1}, {1, 3}, {2, 4}, {3, 1}, {4, 9}, {5, 7}};
	
	cout << "Map elements: ";
	for (auto m : mymap)
		cout << m.second << ", ";
	cout << endl;
	
	cout << "Calling array_print(): ";
    vector<int> values;
    for (auto el : mymap) {
        values.push_back(el.second);
    }    
	array_print(values.data(), values.size());

    return 0;
} 