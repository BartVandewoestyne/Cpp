#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s("some string");

    cout << s << endl;

    int i = 0;
    while (i < s.size())
    {
        s[i] = 'X';
        ++i;
    }

    cout << s << endl;

    return 0;
}
