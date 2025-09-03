#include <iostream>

using namespace std;

int main() {

    int y = 1;
    auto mylambda = [y = y+1](int x) { return x + y; };
    cout << y << endl;
    cout << mylambda(5) << endl;
}