#include <iostream>

using std::cout;
using std::endl;

int main()
{
    std::cout << "bool               => " << sizeof(bool)
              << " bytes" << std::endl;
    std::cout << "char               => " << sizeof(char)
              << " bytes" << std::endl;
    std::cout << "unsigned char      => " << sizeof(unsigned char)
              << " bytes" << std::endl;
    std::cout << "short              => " << sizeof(short)
              << " bytes" << std::endl;
    std::cout << "unsigned short     => " << sizeof(unsigned short)
              << " bytes" << std::endl;
    std::cout << "int                => " << sizeof(int)
              << " bytes" << std::endl;
    std::cout << "unsigned int       => " << sizeof(unsigned int)
              << " bytes" << std::endl;
    std::cout << "long               => " << sizeof(long)
              << " bytes" << std::endl;
    std::cout << "unsigned long      => " << sizeof(unsigned long)
              << " bytes" << std::endl;
    std::cout << "long long          => " << sizeof(long long)
              << " bytes" << std::endl;
    std::cout << "unsigned long long => " << sizeof(unsigned long long)
              << " bytes" << std::endl;
    std::cout << "float              => " << sizeof(float)
              << " bytes" << std::endl;
    std::cout << "double             => " << sizeof(double)
              << " bytes" << std::endl;
    std::cout << "long double        => " << sizeof(long double)
              << " bytes" << std::endl;
}
