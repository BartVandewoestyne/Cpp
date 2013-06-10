#include <iostream>
#include <cstring>

int main()
{
    const char ca1[] = "Jan";
    const char ca2[] = "Jantje";

    const size_t LENGTH = strlen(ca1) + strlen(ca2) + 1;
    char largeStr[LENGTH];

    strcpy(largeStr, ca1);
    strcat(largeStr, ca2);

    std::cout << ca1 << std::endl;
    std::cout << ca2 << std::endl;
    std::cout << largeStr << std::endl;
}
