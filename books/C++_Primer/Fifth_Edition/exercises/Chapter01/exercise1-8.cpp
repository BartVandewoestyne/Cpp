#include <iostream>

int main()
{
    // OK
    std::cout << "/*";

    // OK
    std::cout << "*/";

    // ERROR
    //std::cout << /* "*/" */;
    // CORRECTED
    std::cout << "*/";

    // OK
    std::cout << /*  "*/" /* "/*"  */;
}
