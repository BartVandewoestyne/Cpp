/**
 * Unlike vector, the elements in an initializer_list are always const values;
 * there is no way to change the value of an element in an initializer_list.
 */

#include <initializer_list>
#include <iostream>

int main()
{
    std::initializer_list<int> il = {1, 2, 3};

    // OK; because reference to const.
    for (const auto& elem : il )
    {
        std::cout << elem << std::endl;
    }

    // Dangerous, because you could try to change elements of the initializer
    // list, but this is not allowed.
    for (auto& elem : il )
    {
        //elem = 1;  // Compiler error
        std::cout << elem << std::endl;
    }

    // OK
    for (const auto elem : il )
    {
        // elem = 1; // Compiler error
        std::cout << elem << std::endl;
    }

    // OK, but stupid.
    for (auto elem : il )
    {
        elem = 1; // no compiler error
        std::cout << elem << std::endl;
    }
}
