#include <iostream>

int main()
{
    int i = 1;
    //int i = 0;

    int *p = &i;
    //int *p = nullptr;

    if (p) {
        std::cout << "p is not a null pointer" << std::endl;
    } else {
        std::cout << "p is a null pointer" << std::endl;
    }

    if (*p) {
        std::cout << "Where p points to is nonzero." << std::endl;
    } else {
        std::cout << "Where p points to is zero." << std::endl;
    }
}
