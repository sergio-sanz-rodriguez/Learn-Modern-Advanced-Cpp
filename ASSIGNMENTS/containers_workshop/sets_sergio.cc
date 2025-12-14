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
#include <set>

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
    
    set<string> st;
    string s;

    cout << "Enter some words: ";

    getline(cin, s);    
    istringstream line{ s };
    istream_iterator<string> isti(line);  // input iterator that reads words (strings) from line
    istream_iterator<string> eof;
    
    copy(isti, eof, inserter(st, st.begin()));
    print(st);

    cout << "The entered string has " << st.size() << " distinct words." << endl;
    
    return 0;
}