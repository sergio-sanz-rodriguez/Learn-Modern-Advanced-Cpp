#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

int factorial(unsigned long long n) {
    if (n < 2) {
        return 1;
    }
    // Check for overflow BEFORE recursion
    if (n > numeric_limits<unsigned long long>::max() / factorial(n - 1)) {
        throw overflow_error("Factorial overflow");
    }

    return n * factorial(n - 1);
}

int main() {
	unsigned long long number;
    cin >> number;
    try {
        unsigned long long result = factorial(number);
        cout << result << endl;
    }
    catch (const overflow_error& e) {
        cout << "Overflow!" << endl;
    }
    return 0;
}