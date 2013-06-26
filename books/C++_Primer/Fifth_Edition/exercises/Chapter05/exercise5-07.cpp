#include <iostream>

using std::cout;
using std::endl;

int get_value()
{
    return 1;
}

int main()
{
    // (a)
    {
        int ival1 = 1;
        int ival2 = 2;
        if (ival1 != ival2)
            ival1 = ival2;  // -> missing semicolon
        else ival1 = ival2 = 0;
    }

    // (b)
    {
        int ival = 0;
        int minval = 0;
        int occurs = 0;
        if (ival < minval) {
            minval = ival;
            occurs = 1;
        } // -> braces probably not correct
    }

    // (c)
    {
        int ival = 0;  // ival must be declared outside if-test.
        if (ival = get_value())
            cout << "ival = " << ival << endl;
        if (!ival)
            cout << "ival = 0\n";
    }

    // (d)
    {
        int ival = 0;
        if (ival == 0) // '=' must probably be '=='
            ival = get_value();
    }
}
