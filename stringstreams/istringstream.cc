#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


// Helper: check if a string is a word (all letters)
bool is_word(const string& s) {
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return !s.empty();
}

int main() {
	ifstream infile("../data.txt");

	if (!infile) {
		cout << "Could not open data.txt" << endl;
		return -1;
	}
	string line;
	vector<int> numbers;
    vector<string> words;

	while (getline(infile, line)) {
		// Validation etc
		istringstream is(line);
		int num;
		while (is >> num) {
			numbers.push_back(num);
		}

        istringstream isw(line);
        string token;
        while (isw >> token) {
            if (is_word(token))
            words.push_back(token);
        }
	}

	double sum{0.0};
	for (auto n: numbers) {
		cout << n << endl;
		sum += n;
	}

	cout << "Average is " << sum/numbers.size() << endl;

    if (!words.empty()) {
        cout << "There are also words: ";
        for (size_t i = 0; i < words.size(); ++i) {
            cout << words[i];
            if (i != words.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
}