#include <iostream>

std::string global_str;  // initialized to empty string
int global_int;          // "variables defined outside any function body are
                         //  initialized to zero"

int main()
{
    int local_int;          // uninitialized, so undefined value
    std::string local_str;  // initialized to empty string

    std::cout << "global_str: " << global_str << std::endl;
    std::cout << "global_int: " << global_int << std::endl;
    std::cout << "local_int: " << local_int << std::endl;
    std::cout << "local_str: " << local_str << std::endl;
}
