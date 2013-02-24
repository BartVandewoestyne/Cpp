#include "Widget.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main()
{
    const int maxNumWidgets = 5;

    std::cout << "Creating array of " << maxNumWidgets << " Widgets."
              << std::endl;
    Widget w[maxNumWidgets];     // create an array of maxNumWidgets
                                 // Widgets, default-constructing each one

    std::cout << "Creating empty vector of Widgets." << std::endl;
    vector<Widget> vw1;          // create a vector with zero Widget
                                 // objects that will expand as needed.

    std::cout << "Creating empty vector of Widgets and reserving space."
              << std::endl;
    vector<Widget> vw2;
    vw2.reserve(maxNumWidgets);  // see Item 14 for details on reserve
}
