#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string s = "word";

    // This does not compile.
    //string p1 = s + s[s.size() - 1] == 's' ? "" : "s" ;

    // This does compile.
    string p1 = s + ( (s[s.size() - 1] == 's') ? "" : "s" );

    cout << p1 << endl;
}
