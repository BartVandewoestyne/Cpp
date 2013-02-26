#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "Widget.h"
using std::vector;


void print(std::vector<Widget> v)
{
    copy(v.begin(), v.end(), std::ostream_iterator<Widget>(std::cout, " "));

    std::cout << std::endl;
}


int main()
{
    vector<Widget> v1, v2;

    v2.push_back( Widget(1) );
    v2.push_back( Widget(2) );
    v2.push_back( Widget(3) );
    v2.push_back( Widget(4) );
    v2.push_back( Widget(5) );

    // Make v1's contents be the same as the second half of v2's.
    v1.assign( v2.begin()+v2.size()/2, v2.end() );

    print(v1);

    // Without using a range member function (with explicit loop).
    v1.clear();
    for (vector<Widget>::const_iterator ci = v2.begin() + v2.size()/2;
         ci != v2.end();
         ++ci)
    {
        v1.push_back(*ci);
    }

    print(v1);

    // Employ an algorithm.
    v1.clear();
    copy( v2.begin() + v2.size()/2, v2.end(), back_inserter(v1) );

    print(v1);
}
