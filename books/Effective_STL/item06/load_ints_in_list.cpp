#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
using std::list;
using std::ifstream;
using std::istream_iterator;

int main()
{
    ifstream dataFile("ints.dat");

    // Warning!  This DOES NOT do what you think it does!
    // This DOES NOT declare a list and it DOES NOT call a constructor!
    // It declares a function, data, whose return type is list<int>.  The
    // function data takes two parameters:
    //
    //   * The first parameter is named dataFile.  It's type is
    //     istream_iterator<int>.  The parentheses around dataFile are
    //     superfluous and are ignored.
    //
    //   * The second parameter has no name.  Its type is pointer to function
    //     taking nothing and returning an istream_iterator<int>.
    //
    //list<int> data( istream_iterator<int>(dataFile),
    //                istream_iterator<int>() );

    // This DOES work (not the extra parens), but some compilers seem to fail.
    //list<int> data( (istream_iterator<int>(dataFile)),
    //                 istream_iterator<int>() );

    // This DOES work, and should work everywhere.
    istream_iterator<int> dataBegin(dataFile);
    istream_iterator<int> dataEnd;
    list<int> data(dataBegin, dataEnd);

    // Try to print the list, just to check if it's really a list or a
    // function...
    for (list<int>::const_iterator ci = data.begin();
         ci != data.end();
         ++ci)
    {
        std::cout << *ci << std::endl;
    }
}
