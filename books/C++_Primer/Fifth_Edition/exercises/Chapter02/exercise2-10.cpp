#include <iostream>

// empty string
std::string global_str;

// Variables of built-in type defined outside any function will be initialize
// to zero.
int global_int;

int main()
{
    // Variables of built-in type defined inside a function are uninitialized.
    int local_int;

    // empty string
    std::string local_str;

    std::cout << "global_str = " << global_str << std::endl;
    std::cout << "global_int = " << global_int << std::endl;
    std::cout << "local_int = " << local_int << std::endl;
    std::cout << "local_str = " << local_str << std::endl;
}
