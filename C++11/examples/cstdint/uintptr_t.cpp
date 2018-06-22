/*
 * References:
 *
 *   [dimba20091204] What is uintptr_t data type
 *     https://stackoverflow.com/questions/1845482/what-is-uintptr-t-data-type
 *
 *   [pierrebdr20080930] Converting a pointer into an integer
 *     https://stackoverflow.com/questions/153065/converting-a-pointer-into-an-integer
 */

#include <cstdint>
#include <iostream>

int main()
{
    void *p;
    auto i = reinterpret_cast<std::uintptr_t>(p);

    std::cout << "i = " << i << std::endl;
}
