#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    string word;

    while (cin >> word)        // read until end-of-file
    {
        cout << word << endl;  // write each word followed by a new line
    }

    return 0;
}
