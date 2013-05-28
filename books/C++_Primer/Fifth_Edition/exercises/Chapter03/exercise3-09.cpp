#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s;              // default initialization; s is the empty string
    cout << s[0] << endl;  // subscripting an empty string is undefined
                           // (see note on bottom of page 93)

    return 0;
}
