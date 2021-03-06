/*
 * Show the sizes of the different fundamental types and pointers to them.
 */

#include <climits>
#include <iostream>

class Empty {};
class Base { int a; };
class Derived : public Base { int b; };

int main()
{
    std::cout << "On this platform, there are " << CHAR_BIT << " bits in one byte." << std::endl;

    std::cout << std::endl;

    std::cout << "Size in bytes of fundamental types:" << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(bool) = " << sizeof(bool) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "  sizeof(signed char) = " << sizeof(signed char) << std::endl;
    std::cout << "  sizeof(unsigned char) = " << sizeof(unsigned char) << std::endl;
    std::cout << "  sizeof(wchar_t) = " << sizeof(wchar_t) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(short) = " << sizeof(short) << std::endl;
    std::cout << "  sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "  sizeof(signed int) = " << sizeof(signed int) << std::endl;
    std::cout << "  sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl;
    std::cout << "  sizeof(long) = " << sizeof(long) << std::endl;
    std::cout << "  sizeof(signed long) = " << sizeof(signed long) << std::endl;
    std::cout << "  sizeof(unsigned long) = " << sizeof(unsigned long) << std::endl;
    std::cout << "  sizeof(long long) = " << sizeof(long long) << std::endl;
    std::cout << "  sizeof(signed long long) = " << sizeof(signed long long) << std::endl;
    std::cout << "  sizeof(unsigned long long) = " << sizeof(unsigned long long) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(float) = " << sizeof(float) << std::endl;
    std::cout << "  sizeof(double) = " << sizeof(double) << std::endl;
    std::cout << "  sizeof(long double) = " << sizeof(long double) << std::endl;

    std::cout << std::endl;

    std::cout << "Size in bytes of pointers to fundamental types:" << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(bool*) = " << sizeof(bool*) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(char*) = " << sizeof(char*) << std::endl;
    std::cout << "  sizeof(signed char*) = " << sizeof(signed char*) << std::endl;
    std::cout << "  sizeof(unsigned char*) = " << sizeof(unsigned char*) << std::endl;
    std::cout << "  sizeof(wchar_t*) = " << sizeof(wchar_t*) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(short*) = " << sizeof(short*) << std::endl;
    std::cout << "  sizeof(int*) = " << sizeof(int*) << std::endl;
    std::cout << "  sizeof(signed int*) = " << sizeof(signed int*) << std::endl;
    std::cout << "  sizeof(unsigned int*) = " << sizeof(unsigned int*) << std::endl;
    std::cout << "  sizeof(long*) = " << sizeof(long*) << std::endl;
    std::cout << "  sizeof(long long*) = " << sizeof(long long*) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(float*) = " << sizeof(float*) << std::endl;
    std::cout << "  sizeof(double*) = " << sizeof(double*) << std::endl;
    std::cout << "  sizeof(long double*) = " << sizeof(long double*) << std::endl;

    std::cout << std::endl;

    std::cout << "  sizeof(float*) = " << sizeof(float*) << std::endl;
    std::cout << "  sizeof(double*) = " << sizeof(double*) << std::endl;
    std::cout << "  sizeof(long double*) = " << sizeof(long double*) << std::endl;

    std::cout << std::endl;

    Empty e;
    Base b;
    Derived d;

    std::cout << "  sizeof(e) = " << sizeof(e) << std::endl;
    std::cout << "  sizeof(b) = " << sizeof(b) << std::endl;
    std::cout << "  sizeof(d) = " << sizeof(d) << std::endl;
}
