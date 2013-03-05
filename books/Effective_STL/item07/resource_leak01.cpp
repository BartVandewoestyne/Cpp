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

    // Widgets are leaked here!
    // TODO: check with valgrind.
}

int main()
{
    doSomething();
}
