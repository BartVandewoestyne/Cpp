#include "Widget.h"
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

const int SOME_MAGIC_NUMBER = 3;

template<typename T>
struct DeleteObject : public unary_function<const T*, void> {
// Item 40 describes why this inheritance is here.

    void operator()(const T* ptr) const
    {
        delete ptr;
    }

};

void doSomething()
{
    vector<Widget*> vwp;
    for (int i = 0; i < SOME_MAGIC_NUMBER; ++i)
    {
        vwp.push_back(new Widget);
    }

    // ... use vwp

    for_each(vwp.begin(), vwp.end(), DeleteObject<Widget>());
}

int main()
{
    doSomething();
}
