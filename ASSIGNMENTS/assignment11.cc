#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

// Reads one line from std::cin, splits it into words, and fills vec with (word,length)
void read_from_input(vector<pair<string, int>>& vec) {
    string s;
    getline(cin, s);                      // read an entire line from stdin into s

    istringstream line{ s };              // turn that line into a stream so we can extract words

    istream_iterator<string> isti(line);  // input iterator that reads words (strings) from line
    istream_iterator<string> eof;         // default-constructed: represents end-of-stream

    // transform each word into a (word,length) pair and append it to vec
    transform(isti, eof, back_inserter(vec),
              [](const string& str) -> pair<string, int> {
                  return make_pair(str, str.length()); // build pair(word,length)
              });
}

// Builds a string representation of the vector of pairs, like:
// [("hello", 5), ("world", 5)]
string to_string(const vector<pair<string, int>>& vec) {
    auto last = prev(cend(vec)); // iterator to the last element (so we can handle no trailing comma)

    ostringstream res;           // string stream to accumulate output
    res << "[";                  // start with opening bracket

    // transform all elements except the last into strings "(word, len), " and write to res
    transform(cbegin(vec), last,
              ostream_iterator<string>(res), // writes returned string directly into res
              [](const pair<string, int>& p) {
                  ostringstream inner_res;
                  inner_res << "(\"" << p.first << "\", " << p.second << "), ";
                  return inner_res.str(); // each call returns a string for one element
              });

    // append the last element without trailing comma and close bracket
    res << "(\"" << last->first << "\", " << last->second << ")]";

    return res.str(); // return final string
}

int main() {

    /*
    typedef pair<string, int> mypair;
    string input;
    vector<mypair> myvector;
    map<string, int> mymap;
    
    std::cout << "Enter strings (press Enter on empty line to finish):\n";

    while(true)
    {
        getline(cin, input);
        if (input.empty()) break;        
        myvector.push_back(make_pair(input, input.size()));                     
    }
    
    cout << "You have entered: \n";
    for (auto elem : myvector)
    {
        cout << elem.first << " with length " << elem.second << endl;
    }

    std::cout << "Enter strings (press Enter on empty line to finish):\n";

    while(true)
    {
        getline(cin, input);
        if (input.empty()) break;        
        mymap.insert(make_pair(input, input.size()));
    }

    cout << "You have entered: \n";
    for (const auto& [key, value] : mymap)    
    {
        cout << key << " with length " << value << endl;
    }
*/
    vector<pair<string, int>> vp;
    cout << "Enter some words: ";
    read_from_input(vp);
    cout << "You wrote: " << to_string(vp) << endl;

    
    return 0;
}