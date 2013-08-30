#include <cassert>
#include <iostream>
#include <string>
using std::cin;
using std::string;

int main()
{
    string sought("FooBar");

    // What does the loop doe?
    // -> as long as gouth is not found, we keep on reading strings.
    // Is is a good use of assert?
    // -> TODO... i can't tell.
    string s;
    while (cin >> s && s != sought) { }  // empty body
    assert(cin);
}
