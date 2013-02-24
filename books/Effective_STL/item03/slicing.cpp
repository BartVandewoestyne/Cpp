#include <vector>
#include "Widget.h"
#include "SpecialWidget.h"

int main()
{
    vector<Widget> vw;

    SpecialWidget sw;

    vw.push_back(sw);  // sw is copied as a base class
                       // object into vw.  Its specialness
                       // is lost during copying.
}
