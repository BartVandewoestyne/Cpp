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

    if (s1.size() == s2.size())
    {
        cout << "Strings are equal in length." << endl;
    }
    else
    {
        if (s1.size() > s2.size())
        {
            cout << "First string (" << s1 << ") is larger." << endl;
        }
        else
        {
            cout << "Second string (" << s2 << ") is larger." << endl;
        }
    }

    return 0;
}
