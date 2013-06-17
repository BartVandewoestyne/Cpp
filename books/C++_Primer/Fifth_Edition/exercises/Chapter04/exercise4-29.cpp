#include <iostream>

using std::cout;
using std::endl;

int main()
{
    int x[10];
    int *p = x;

    cout << "sizeof( x) = " << sizeof( x) << " bytes" << endl;  // size of the array
    cout << "sizeof(*x) = " << sizeof(*x) << " bytes" << endl;  // size of an int
    cout << "sizeof( p) = " << sizeof( p) << " bytes" << endl;  // size of a pointer to int
    cout << "sizeof(*p) = " << sizeof(*p) << " bytes" << endl;  // size of an int

    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
}
