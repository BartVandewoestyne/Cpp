// TODO: check typo on page 28: chanced -> changed

#include "Widget.h"
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

bool widgetAPCompare(const auto_ptr<Widget>& lhs,
                     const auto_ptr<Widget>& rhs)
{
    return *lhs < *rhs;  // for this example, assume that
                         // operator< exists for Widgets
}

int main()
{
    auto_ptr<Widget> pw1(new Widget(1));
    auto_ptr<Widget> pw2(new Widget(2));
    auto_ptr<Widget> pw3(new Widget(3));
    auto_ptr<Widget> pw4(new Widget(4));
    auto_ptr<Widget> pw5(new Widget(5));

    vector<auto_ptr<Widget> > widgets;  // create a vector and then fill it
                                        // with auto_ptrs to Widgets;
                                        // remember that this should
                                        // not compile!
    widgets.push_back(pw1);
    widgets.push_back(pw2);
    widgets.push_back(pw3);
    widgets.push_back(pw4);
    widgets.push_back(pw5);

    sort(widgets.begin(), widgets.end(),  // sort the vector
         widgetAPCompare);
}
