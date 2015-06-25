/**
 * A test program to display the integer ranges for different signed integer types.
 */

#include <limits>
#include <iostream>
#include <typeinfo>

template<typename T>
void check_range(const std::string& typeName)
{
    const T imin = std::numeric_limits<T>::min();
    const T imax = std::numeric_limits<T>::max();

    //std::cout << typeid(T).name() << std::endl;  // non-portable code
    std::cout << typeName << ":" << std::endl;
    std::cout << "  smallest integer = " << imin << std::endl;
    std::cout << "  largest integer = " << imax << std::endl;
}

int main()
{
    std::cout << "Signed integer ranges:" << std::endl;
    check_range<char>("char");
    check_range<short>("short");
    check_range<int>("int");
    check_range<long>("long");
    check_range<long long>("long long");

    std::cout << "Unsigned integer ranges:" << std::endl;
    check_range<unsigned char>("unsigned char");
    check_range<unsigned short>("unsigned short");
    check_range<unsigned int>("unsigned int");
    check_range<unsigned long>("unsigned long");
    check_range<unsigned long long>("unsigned long long");
}
