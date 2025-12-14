// family_sergio.cpp
#include "family_sergio.h"
#include <string>
#include <iostream>

using namespace std;

void Family::add(const string& child) {
    children.push_back(child);
}

void Family::print() const {
    for ( size_t i = 0; i < children.size(); ++ i) {
        cout << "Child #" << i << ": " << children[i] << endl;
    }
}

int Family::size() const {
    return children.size();
}
