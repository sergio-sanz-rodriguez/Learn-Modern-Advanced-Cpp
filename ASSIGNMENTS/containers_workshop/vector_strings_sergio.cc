#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>
#include <deque>

using namespace std;


template <typename Container>
void print(const Container& container)
{
    cout << "You wrote: ";
    for (auto el : container)
    {
        cout << el << " ";
    }
    cout << endl;
}

int main() {
    
    vector<string> vec;
    list<string> lst;
    deque<string> dq;
    string s;

    cout << "Enter some words: ";

    getline(cin, s);    
    istringstream line{ s };
    istream_iterator<string> isti(line);  // input iterator that reads words (strings) from line
    istream_iterator<string> eof;
    
    //copy(isti, eof, back_inserter(vec));
    //print(vec);

    //copy(isti, eof, back_inserter(lst));
    //print(lst);

    //copy(isti, eof, back_inserter(dq));
    //print(dq);

    copy(isti, eof, front_inserter(dq));
    print(dq);


    
    return 0;
}