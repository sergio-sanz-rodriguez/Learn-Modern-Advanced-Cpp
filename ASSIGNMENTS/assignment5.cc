#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& vec) 
{
    for (auto elem : vec)
    {
        cout << elem << ", ";
    }
    cout << endl << endl;
}

int main() {
	vector<int> numbers = { 1, 3, 2, 4, 5, 4, 7, 1, 3 };

    cout << "Vector before sort()\n";
    print(numbers);

    sort(begin(numbers), end(numbers), [](int lhs, int rhs) { return (lhs > rhs); } );

    cout << "Vector after sort()\n";
    print(numbers);

}