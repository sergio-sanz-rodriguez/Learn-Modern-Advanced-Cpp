#include <iostream>
#include <string>

using namespace std;

void exclaim(string& str )
{
    for ( char&c : str)
    {
        if (ispunct(c))
        {
            c = '!';
        }
    }
    cout << str << endl;
}

int main() {
	string str{"To be, or not to be, that is the question:"};
    exclaim(str);
    
}
