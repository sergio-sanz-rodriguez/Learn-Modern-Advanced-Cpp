#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class ge_n {
  private:
    const int n;
	int& idx; //reference to an external variable
  public:
    ge_n(const int n, int& idx) : n(n), idx(idx) {}

    bool operator () (const string& str) const {
        ++idx; return str.size() > n;
    }
};

class ge_n_ {
  private:
    const int n;
	int* idx; //pointer version
  public:
    ge_n_(const int n, int* idx) : n(n), idx(idx) {}

    bool operator () (const string& str) const {
        ++(*idx); return str.size() > n;
    }
};

int main() {
	vector<string> words{ "a", "collection", "of", "words", "with", "varying", "lengths" };

	int max{5}, idx{-1};
	// Find the first element with more than 5 characters
	// [max, &idx] (const string& str) { ++idx; return str.size() > max; } 
	//auto res = find_if(cbegin(words), cend(words), ge_n(max, idx));
    auto res = find_if(cbegin(words), cend(words), ge_n_(max, &idx));

	// Display it
	if (res != cend(words)) {
		cout << R"(The first word which is more than )" << max << R"( letters long is ")";
		cout << *res << R"(")" << endl;
		cout << "Its index is " << idx << endl;
	}
}