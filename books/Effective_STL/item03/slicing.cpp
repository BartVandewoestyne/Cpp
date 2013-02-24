#include <iostream>
#include <vector>
#include "Widget.h"
#include "SpecialWidget.h"
using std::cout;
using std::vector;

int main()
{
    std::cout << "Creating empty vector of Widgets." << std::endl;
    vector<Widget> vw;

    std::cout << "Creating a SpecialWidget." << std::endl;
    SpecialWidget sw;

    std::cout << "Pushing back the SpecialWidget onto the vector" << std::endl;
    vw.push_back(sw);  // sw is copied as a base class
                       // object into vw.  Its specialness
                       // is lost during copying.
}
