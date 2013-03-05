/**
 * This code is type-safe, but still not exception-safe.
 */

#include "Widget.h"
#include "SpecialString.h"
#include <algorithm>
#include <deque>
using namespace std;

struct DeleteObject { // templatization and base class removed here

    // templatization added here
    template<typename T>
    void operator()(const T* ptr) const
    {
        delete ptr;
    }

};

void doSomething()
{
    deque<SpecialString*> dssp;

    // ...

    // Not exception safe: if an exception is thrown after the Special-Strings
    // are newed but before invocation of the call to for_each, it's
    // Leakapalooza.

    // ah! well-defined behavior!
    for_each(dssp.begin(), dssp.end(), DeleteObject());
}

int main()
{
    doSomething();
}
