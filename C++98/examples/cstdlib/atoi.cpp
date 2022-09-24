#include <iostream>
#include <cstdlib>
 
int main()
{
    const char *str1 = "42";
    const char *str2 = "3.14159";
    const char *str3 = "31337 with words";
    const char *str4 = "words and 2";
    const char *str5 = " -123junk";
    const char *str6 = "0";
    const char *str7 = "junk";
    const char *str8 = "2147483647";
    const char *str9 = "2147483648";
    const char *str10 = "4294967295";

    char *end;
 
    std::cout << "std::atoi(\"" << str1 << "\") is " << std::atoi(str1) << '\n';
    std::cout << "std::atoi(\"" << str2 << "\") is " << std::atoi(str2)<< '\n';
    std::cout << "std::atoi(\"" << str3 << "\") is " << std::atoi(str3)<< '\n';
    std::cout << "std::atoi(\"" << str4 << "\") is " << std::atoi(str4)<< '\n';
    std::cout << "std::atoi(\"" << str5 << "\") is " << std::atoi(str5)<< '\n';
    std::cout << "std::atoi(\"" << str6 << "\") is " << std::atoi(str6)<< '\n';
    std::cout << "std::atoi(\"" << str7 << "\") is " << std::atoi(str7)<< '\n';
    std::cout << "std::atoi(\"" << str8 << "\") is " << std::atoi(str8)<< '\n';
    std::cout << "std::atoi(\"" << str9 << "\") is " << std::atoi(str9)<< '\n';
    std::cout << "std::atoi(\"" << str10 << "\") is " << std::atoi(str10) << '\n';

    std::cout << "std::strtoul(\"" << str1 << "\") is " << std::strtoul(str1, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str2 << "\") is " << std::strtoul(str2, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str3 << "\") is " << std::strtoul(str3, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str4 << "\") is " << std::strtoul(str4, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str5 << "\") is " << std::strtoul(str5, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str6 << "\") is " << std::strtoul(str6, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str7 << "\") is " << std::strtoul(str7, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str8 << "\") is " << std::strtoul(str8, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str9 << "\") is " << std::strtoul(str9, &end, 10) << '\n';
    std::cout << "std::strtoul(\"" << str10 << "\") is " << std::strtoul(str10, &end, 10) << '\n';
}
