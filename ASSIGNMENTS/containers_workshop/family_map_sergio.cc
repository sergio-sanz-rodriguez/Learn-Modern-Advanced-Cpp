#include "family_sergio.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string,Family> family_map;

    Family Sanz;
    Sanz.add("Santiago");
    Sanz.add("Sergio");
    Sanz.add("Cristina");

    Family Heidbuechel;
    Heidbuechel.add("Nina");
    Heidbuechel.add("Ulla");

    family_map.insert({"Sanz", Sanz});
    family_map.insert({"Heidbuechel", Heidbuechel});

    for (auto elem : family_map) {
        string family_name = elem.first;
        Family family_children = elem.second;
        cout << "Family " << family_name << " has " << family_children.size() << " children:" << endl;
        family_children.print();
        cout << endl;
    } 
}
