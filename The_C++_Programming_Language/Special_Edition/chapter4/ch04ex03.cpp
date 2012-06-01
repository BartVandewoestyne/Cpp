#include <iostream>

int main ()
{
    // Fundamental types:
    std::cout << "Fundamental types:\n";
    std::cout << "sizeof(bool)   = "
	      << sizeof(bool) << " times sizeof(char).\n";
    std::cout << "sizeof(char)   = "
	      << sizeof(char) << " times sizeof(char).\n";
    std::cout << "sizeof(int)    = "
              << sizeof(int) << " times sizeof(char).\n";
    std::cout << "sizeof(double) = "
              << sizeof(double) << " times sizeof(char).\n\n";

    // Pointer types:
    std::cout << "Pointer types:\n";
    std::cout << "sizeof(bool*)      = "
              << sizeof(bool*) << " times sizeof(char).\n";
    std::cout << "sizeof(char*)      = "
              << sizeof(char*) << " times sizeof(char).\n";
    std::cout << "sizeof(int*)       = "
              << sizeof(int*) << " times sizeof(char).\n";
    std::cout << "sizeof(double*)    = "
              << sizeof(double*) << " times sizeof(char).\n\n";

    // Enumerations:
    // See also:
    //   http://mateusz.loskot.net/2009/05/24/size-of-enumeration-type-in-c/
    //   http://en.wikipedia.org/wiki/C%2B%2B0x#Strongly_typed_enumerations
    std::cout << "Enumeration types:\n";
    enum e1 { dark, light };
    enum e2 { a=3, b=9 };
    enum e3 { min=-10, max=1000000 };
    enum e4 { min2=-10, max2=2147483648 };
    std::cout << "sizeof(e1)    = "
              << sizeof(e1) << " times sizeof(char).\n";
    std::cout << "sizeof(e2)    = "
              << sizeof(e2) << " times sizeof(char).\n";
    std::cout << "sizeof(e3)    = "
              << sizeof(e3) << " times sizeof(char).\n";
    std::cout << "sizeof(e4)    = "
              << sizeof(e4) << " times sizeof(char).\n\n";

}
