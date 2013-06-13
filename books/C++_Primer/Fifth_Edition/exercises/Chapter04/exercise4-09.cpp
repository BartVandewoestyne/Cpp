#include <iostream>

int main()
{
    const char *cp = "Hello World";

    // cp is a non-null pointer, and gets converted to boolean TRUE
    //
    // the content of *cp is the non-null string "Hello World" so also gets
    // converted to TRUE
    //
    // Then, TRUE && TRUE equals TRUE
    if (cp && *cp)
    {
        std::cout << "TRUE" << std::endl;
    }
    else
    {
        std::cout << "FALSE" << std::endl;
    }
}
