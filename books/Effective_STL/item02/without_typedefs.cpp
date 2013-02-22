#include <algorithm>
#include <vector>
using std::vector;
using std::find;

class Widget {};

int main()
{
    vector<Widget> vw;
    Widget bestWidget;
    
    // Give bestWidget a value.
    
    // Find a Widget with the same value as bestWidget.
    vector<Widget>::iterator i =
        find(vw.begin(), vw.end(), bestWidget);
}
