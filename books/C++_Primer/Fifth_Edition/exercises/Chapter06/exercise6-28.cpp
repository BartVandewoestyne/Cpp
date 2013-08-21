#include <initializer_list>
#include <iostream>
#include <string>
using namespace std;

struct ErrCode {
  string msg() { return string("SomeError"); }
};

void error_msg(ErrCode e, initializer_list<string> il)
{
    cout << e.msg() << ": ";
    for (const auto &elem : il)  // The type of elem is string.
        cout << elem << " ";
    cout << endl;
}

int main()
{
    ErrCode e;
    error_msg(e, {"Test", "Foobar"});
}
