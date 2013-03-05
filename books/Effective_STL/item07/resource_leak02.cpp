#include "Widget.h"
#include <vector>
using namespace std;

const int SOME_MAGIC_NUMBER = 3;

void doSomething()
{
    vector<Widget*> vwp;
    for (int i = 0; i < SOME_MAGIC_NUMBER; ++i)
    {
        vwp.push_back(new Widget);
    }

    // ... use vwp

    // This code is not exception safe: if an exception is thrown between the
    // time vwp is filled with pointers and the time you get around to deleting
    // them, you've leaked resources again.

    for (vector<Widget*>::iterator i = vwp.begin();
         i != vwp.end();
         ++i)
    {
        delete *i;
    }
}

int main()
{
    doSomething();
}
