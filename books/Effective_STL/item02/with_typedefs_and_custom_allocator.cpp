#include <iostream>
#include <algorithm>
#include <vector>
#include "Widget.h"
using std::vector;
using std::find;

template<typename T>
class SpecialAllocator{};

typedef vector<Widget, SpecialAllocator<Widget> > WidgetContainer;
typedef WidgetContainer::iterator WCIterator;

int main()
{
    WidgetContainer cw;
    Widget bestWidget;

    // Add some Widgets to the vector of Widgets.
    cw.push_back(Widget(1));
    cw.push_back(Widget(2));
    cw.push_back(Widget(3));
    
    // Give bestWidget a value.
    bestWidget.setId(2);
    
    // Find a Widget with the same value as bestWidget.
    WCIterator i = find(cw.begin(), cw.end(), bestWidget);

    std::cout << *i << std::endl;
}
