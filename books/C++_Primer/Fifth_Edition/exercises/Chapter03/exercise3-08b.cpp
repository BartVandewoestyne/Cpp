#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

int main()
{
    string s("some string");

    cout << s << endl;

    for (string::size_type i = 0; i < s.size(); ++i)
    {
        s[i] = 'X';
    }

    cout << s << endl;

    return 0;
}
