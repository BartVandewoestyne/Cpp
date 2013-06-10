#include <iostream>
#include <string>

int main()
{
    std::string s1 = "Jan";
    std::string s2 = "Jantje";

    if (s1 == s2)
    {
        std::cout << "Strings are equal!" << std::endl;
    }
    else
    {
        std::cout << "Strings are not equal!" << std::endl;
    }
}
