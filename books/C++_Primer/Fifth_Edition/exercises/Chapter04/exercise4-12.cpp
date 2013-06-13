#include <iostream>

int main()
{
    int i = 0;
    int j = 2;
    int k = 3;

    // integer i gets converted to bool and compared with j < k which is also
    // bool.

    if (i != j < k)
    {
        std::cout << "TRUE" << std::endl;
    }
    else
    {
        std::cout << "FALSE" << std::endl;
    }
}
