#include <iostream>

using namespace std;

class Test {
	int i;
	public:
	explicit Test(int i) : i(i) {}
};

int main() {
	Test test = 4; // error
    Test test(4); // must explicitly create an object
    Test test = Test{4};
}