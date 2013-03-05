#include "Widget.h"
#include "SpecialString.h"
#include <vector>
#include <boost/shared_ptr.hpp>
using namespace std;

const int SOME_MAGIC_NUMBER = 3;

void doSomething()
{
    typedef boost::shared_ptr<Widget> SPW;  // SPW = "shared_ptr to Widget"

    vector<SPW> vwp;
    for (int i = 0; i < SOME_MAGIC_NUMBER; ++i)
    {
        vwp.push_back(SPW(new Widget));  // create a SPW from a Widget*,
                                         // then do a push_back on it
    }

    // ... use vwp

} // no Widgets are leaked here, not even if an exception is thrown in the
  // code above.

int main()
{
    doSomething();
}
