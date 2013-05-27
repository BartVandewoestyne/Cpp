#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string s1, s2;

    cout << "Enter two strings: " << endl;
    cin >> s1;
    cin >> s2;

    if (s1 == s2)
    {
        cout << "Strings are equal (case-sensitive dictionary order)." << endl;
    }
    else
    {
        if (s1 > s2)
        {
            cout << "First string (" << s1 << ") is larger (case-sensitive dictionary order)." << endl;
        }
        else
        {
            cout << "Second string (" << s2 << ") is larger (case-sensitive dictionary order)." << endl;
        }
    }

    return 0;
}
