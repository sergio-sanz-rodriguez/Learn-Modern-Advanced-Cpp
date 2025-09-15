#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

int main() {
	unordered_map<string, int> scores;       // Create unordered_map object
	scores.insert( {"Graham", 78} );         // Add some elements to it
	scores.insert( {"Grace", 66} );
	scores.insert( {"Graham", 66} );         // Add duplicate elements
	scores.insert( {"Graham", 72} );
	scores.insert( {"Hareesh", 77} );

	for (auto it: scores) 
		cout << it.first << " has a score of " << it.second << endl;
    
    cout << endl;
    unordered_multimap<string, int> mscores;       // Create unordered_map object
	mscores.insert( {"Graham", 78} );         // Add some elements to it
	mscores.insert( {"Grace", 66} );
	mscores.insert( {"Graham", 66} );         // Add duplicate elements
	mscores.insert( {"Graham", 72} );
	mscores.insert( {"Hareesh", 77} );

	for (auto it: mscores) 
		cout << it.first << " has a score of " << it.second << endl;

    cout << endl;
    multimap<string, int> mmscores;       // Create unordered_map object
	mmscores.insert( {"Graham", 78} );         // Add some elements to it
	mmscores.insert( {"Grace", 66} );
	mmscores.insert( {"Graham", 66} );         // Add duplicate elements
	mmscores.insert( {"Graham", 72} );
	mmscores.insert( {"Hareesh", 77} );

	for (auto it: mmscores) 
		cout << it.first << " has a score of " << it.second << endl;
}