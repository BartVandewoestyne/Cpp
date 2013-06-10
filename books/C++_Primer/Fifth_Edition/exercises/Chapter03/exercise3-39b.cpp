#include <iostream>
#include <cstring>

int main()
{
    const char ca1[] = "Jan";
    const char ca2[] = "Jantje";

    if (strcmp(ca1, ca2) == 0)
    {
        std::cout << "Strings are equal!" << std::endl;
    }
    else
    {
        std::cout << "Strings are not equal!" << std::endl;
    }
}
