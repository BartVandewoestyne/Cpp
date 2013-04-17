#include <iostream>

int main()
{
    // (a) is illegal, the 'int' type is at the wrong place.
    //std::cin >> int input_value;
    
    // (b) gives the warning:
    //   narrowing conversion of ‘3.1400000000000001e+0’ from ‘double’
    //   to ‘int’ inside { }
    // TODO: according to the standard, this should result in an error???
    int i = { 3.14 };
    
    // (c) Both salary and wage will have the value 9999.99 when executing these
    // two lines.  It is code that compiles, but confusing...  Maybe the
    // intention was to write
    double salary, wage = 9999.99;
    //double wage = 1.0;
    //double salary, wage = 9999.99;
    std::cout << salary << std::endl;
    std::cout << wage << std::endl;
    
    // (d) is fine.
    int i2 = 3.14;
}
