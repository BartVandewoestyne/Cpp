// TODO: finish this, it is not working yet!
#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string word;
    string full_string;

    while (cin >> word)
    {
        full_string += word;
    }

    cout << full_string << endl;

    return 0;
}
