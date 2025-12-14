// family.h
#ifndef FAMILY_H
#define FAMILY_H

#include <string>
#include <vector>

using namespace std;

class Family {
private:
    vector<string> children;    
public:
    void add(const string& child);
    void print() const;
    int size() const;
};

#endif //FAMILY_H