#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	vector<int> vec {3, 1, 4, 1, 5, 9};
	
	cout << "Vector: ";
	for (auto v : vec)
		cout << v << ", ";
	cout << endl;

	auto sum = accumulate(cbegin(vec), cend(vec), 0,
		[] (int sum, int n) {  return (n % 2 == 1) ? sum + n : sum; }
	);
	
	cout << "Sum of odd elements: " << sum << endl;

    // Lambda with arguments in ()
    //auto multiply = [](int a, int b) { return a * b; };

    //std::cout << "3 * 4 = " << multiply(3, 4) << std::endl;

    // Using lambda with one parameter
    //int k{100};
    //for_each(vec.begin(), vec.end(), [&k](int n) {cout << n * 2 + ++k << " "; });
    //std::cout << std::endl;


}