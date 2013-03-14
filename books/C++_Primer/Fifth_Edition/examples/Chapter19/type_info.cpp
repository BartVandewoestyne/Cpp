/**
 * References:
 *
 *   [1] 'C++ Primer, 5th edition', page 831.
 */

#include <iostream>
#include <string>
#include <typeinfo>
using std::cout;
using std::endl;

int main()
{
    int arr[10];
    // TODO: Derived d;
    // TODO: Base *p = &d;
    cout << typeid(42).name() << ", "
         << typeid(arr).name() << ", "
         // TODO: << typeid(Sales_data).name() << ", "
         << typeid(std::string).name() << ", " << endl;
         // << typeid(p).name() << ", "
         // << typeid(*p).name() << endl;
}
