#include "Widget.h"
#include <algorithm>
#include <functional>
#include <deque>
using namespace std;

class SpecialString : public string {};

template<typename T>
struct DeleteObject : public unary_function<const T*, void> {
// Item 40 describes why this inheritance is here.

    void operator()(const T* ptr) const { // TODO: check errate list book!!!
        delete ptr;
    }

};

void doSomething()
{
    deque<SpecialString*> dssp;

    // ...

    // undefined behavior!  Deletion of a derived object via a base class
    // pointer where there is no virtual destructor.
    for_each(dssp.begin(), dssp.end(), DeleteObject<string>());
}

int main()
{
    doSomething();
}
