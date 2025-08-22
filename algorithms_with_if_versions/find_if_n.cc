#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Functor

class ge_n {
  private:
    const int n;
  public:
    ge_n(const int n) : n(n) {}

    bool operator () (const string& str) const {
        return str.size() > n;
    }
};

int main() {
	vector<string> names = { "Dilbert", "PHB", "Dogbert", "Asok", "Ted", "Alice", "Wally" };
	
	// Find the first element with more than 5 characters
	// Pass a functor object as predicate
    int num = 3;
	auto res = find_if(cbegin(names), cend(names), ge_n(num));

	// Display it
	if (res != cend(names))
		cout << "The first word with > " << num << " characters is \"" << *res << "\"\n";
}