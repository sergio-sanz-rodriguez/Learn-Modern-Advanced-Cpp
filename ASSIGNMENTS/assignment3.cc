#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;

int main() {
	ifstream infile("../languages.txt");
    
    if(!infile) {
        cout << "Could not open languages.txt" << endl;
        return -1;
    }

    string line;
    while (getline(infile, line)) {
        istringstream is(line);
        vector<string> words;
        string word;
        while (is >> word) {
            words.push_back(word);
        }

        if (!words.empty()) {
            for (size_t i = 0; i < words.size(); ++i) {
            cout << words[i];
            if (i != words.size() - 1)
                cout << ", ";
            } 
            
            //bool first_word = true;
            //for (const auto& word : words) {
            //    if (!first_word) cout << ", ";
            //    cout << word;
            //    first_word = false;
            //}
        }
        cout << endl;
    }   
}
