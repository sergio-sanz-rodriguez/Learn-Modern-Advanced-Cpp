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
    cout << "You wrote: " << endl;
    for (auto el : container)
    {
        cout << el.first << " (" << el.second << " characters)" << endl;
    }
}

using wordpair = pair<string, int>;


int main() {
    
    vector<wordpair> vec;
    map<string, int> mp;

    string s;

    cout << "Enter some words: ";

    getline(cin, s);    
    istringstream line{ s };
    istream_iterator<string> isti(line);  // input iterator that reads words (strings) from line
    istream_iterator<string> eof;

    transform(isti, eof, back_inserter(vec),
              [](const string& str) -> wordpair {
                  return make_pair(str, str.length()); // build pair(word,length)
              });
    
    cout << "====Vector====" << endl;
    print(vec);
    
    istringstream line2{ s }; // reuse the original string
    istream_iterator<string> isti2(line2);
    istream_iterator<string> eof2;

    transform(isti2, eof2, inserter(mp, mp.end()),
              [](const string& str) {
                  return make_pair(str, str.length()); // build pair(word,length)
              });
    
    cout << "====Map====" << endl;
    print(mp);
    
    return 0;
}