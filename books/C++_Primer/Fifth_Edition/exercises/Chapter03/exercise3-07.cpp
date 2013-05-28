#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s("some string");

    cout << s << endl;

    for (char &c : s) // interpretation 1
    //for (char c : s)  // interpretation 2
    {
        c = 'X';
    }

    cout << s << endl;

    return 0;
}
