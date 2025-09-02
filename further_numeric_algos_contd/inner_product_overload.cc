#include <iostream>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<double> expected{ 0.1, 0.2, 0.3, 0.4, 0.5 };
	vector<double> actual{ 0.09, 0.22, 0.27, 0.41, 0.52 };

	auto max_diff = inner_product(
								begin(expected), end(expected), begin(actual), 0.0,
                               [](auto a, auto b){ return max(a,b); },          // Reduce operation
							   [](auto l, auto r) { return fabs(r-l); });       // Transform operation 

	cout << "Max difference is: " << max_diff << endl;

    auto SAE = inner_product(
								begin(expected), end(expected), begin(actual), 0.0,
                               [](auto a, auto b){ return (a+b); },          // Reduce operation
							   [](auto l, auto r) { return fabs(r-l); });       // Transform operation 
    
    cout << "Sum of absolut error: " << SAE << endl;

    auto MAE = inner_product(
								begin(expected), end(expected), begin(actual), 0.0,
                               [](auto a, auto b){ return a+b; },          // Reduce operation  or just std::plus<>()
							   [](auto l, auto r) { return fabs(r-l); })       // Transform operation 
                            / expected.size();
    
    cout << "Mean absolut error: " << MAE << endl;
}