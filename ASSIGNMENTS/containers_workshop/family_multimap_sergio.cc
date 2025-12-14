#include <string>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    multimap<string,string> family_multimap;
    //unordered_multimap<string,string> family_multimap;
    set<string> uniqueKeys;

    family_multimap.insert(make_pair("Sanz", "Santiago"));
    family_multimap.insert(make_pair("Sanz", "Sergio"));
    family_multimap.insert(make_pair("Sanz", "Cristina"));
    family_multimap.insert(make_pair("Heidbuechel", "Nina")); 
    family_multimap.insert(make_pair("Heidbuechel", "Ulla"));

    for (auto it : family_multimap) {
        uniqueKeys.insert(it.first);
    }

    for (auto family_name : uniqueKeys) {
        auto num_children = family_multimap.count(family_name);
        auto range = family_multimap.equal_range(family_name);
        cout << "Family " << family_name << " has " << num_children << " children: " << endl;
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->second << endl;
        }   
    }
}
