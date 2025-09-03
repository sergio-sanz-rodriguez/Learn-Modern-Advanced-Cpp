#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main() {

    string input;
    //vector<string> strs;
    //list<string> strs;    
    deque<string> strs;
    //auto pl = strs.begin();
    
    std::cout << "Enter strings (press Enter on empty line to finish):\n";

    while(true)
    {
        getline(cin, input);
        if (input.empty()) break;        
        //strs.push_back(input);                        
        strs.push_front(input);        
        //pl = strs.insert(pl, input);
              
    }
    
    cout << "You have entered: \n";
    for (auto &elem : strs)
    {
        cout << elem << ", ";
    }
    cout << endl;

    return 0;
}