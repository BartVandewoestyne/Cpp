#include <iostream>

int main()
{
    // (a) WRONG
    //std::cin >> int input_value;

    // (a) CORRECTED
    int input_value;
    std::cin >> input_value;


    // (b) WRONG: narrowing conversion
    // See (d) for correct version.
    //int i = { 3.14 };


    // (c) WRONG
    //double salary = wage = 9999.99;

    // (c) CORRECTED
    double salary = 9999.99, wage = 9999.99;


    // (d) CORRECT
    int i = 3.14;
}
