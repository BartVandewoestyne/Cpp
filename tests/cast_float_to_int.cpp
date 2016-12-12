/*
 * Test how floats get cast to int.
 */

#include <iostream>

int main()
{
    std::cout << "int(1.0) = " << int(1.0) << std::endl;
    std::cout << "int(1.1) = " << int(1.1) << std::endl;
    std::cout << "int(1.2) = " << int(1.2) << std::endl;
    std::cout << "int(1.3) = " << int(1.3) << std::endl;
    std::cout << "int(1.4) = " << int(1.4) << std::endl;
    std::cout << "int(1.5) = " << int(1.5) << std::endl;
    std::cout << "int(1.6) = " << int(1.6) << std::endl;
    std::cout << "int(1.7) = " << int(1.7) << std::endl;
    std::cout << "int(1.8) = " << int(1.8) << std::endl;
    std::cout << "int(1.9) = " << int(1.9) << std::endl;
    std::cout << "int(2.0) = " << int(2.0) << std::endl;

    std::cout << "int(-1.0) = " << int(-1.0) << std::endl;
    std::cout << "int(-1.1) = " << int(-1.1) << std::endl;
    std::cout << "int(-1.2) = " << int(-1.2) << std::endl;
    std::cout << "int(-1.3) = " << int(-1.3) << std::endl;
    std::cout << "int(-1.4) = " << int(-1.4) << std::endl;
    std::cout << "int(-1.5) = " << int(-1.5) << std::endl;
    std::cout << "int(-1.6) = " << int(-1.6) << std::endl;
    std::cout << "int(-1.7) = " << int(-1.7) << std::endl;
    std::cout << "int(-1.8) = " << int(-1.8) << std::endl;
    std::cout << "int(-1.9) = " << int(-1.9) << std::endl;
    std::cout << "int(-2.0) = " << int(-2.0) << std::endl;

    std::cout << "static_cast<int>(1.0) = " << static_cast<int>(1.0) << std::endl;
    std::cout << "static_cast<int>(1.1) = " << static_cast<int>(1.1) << std::endl;
    std::cout << "static_cast<int>(1.2) = " << static_cast<int>(1.2) << std::endl;
    std::cout << "static_cast<int>(1.3) = " << static_cast<int>(1.3) << std::endl;
    std::cout << "static_cast<int>(1.4) = " << static_cast<int>(1.4) << std::endl;
    std::cout << "static_cast<int>(1.5) = " << static_cast<int>(1.5) << std::endl;
    std::cout << "static_cast<int>(1.6) = " << static_cast<int>(1.6) << std::endl;
    std::cout << "static_cast<int>(1.7) = " << static_cast<int>(1.7) << std::endl;
    std::cout << "static_cast<int>(1.8) = " << static_cast<int>(1.8) << std::endl;
    std::cout << "static_cast<int>(1.9) = " << static_cast<int>(1.9) << std::endl;
    std::cout << "static_cast<int>(2.0) = " << static_cast<int>(2.0) << std::endl;

    std::cout << "static_cast<int>(-1.0) = " << static_cast<int>(-1.0) << std::endl;
    std::cout << "static_cast<int>(-1.1) = " << static_cast<int>(-1.1) << std::endl;
    std::cout << "static_cast<int>(-1.2) = " << static_cast<int>(-1.2) << std::endl;
    std::cout << "static_cast<int>(-1.3) = " << static_cast<int>(-1.3) << std::endl;
    std::cout << "static_cast<int>(-1.4) = " << static_cast<int>(-1.4) << std::endl;
    std::cout << "static_cast<int>(-1.5) = " << static_cast<int>(-1.5) << std::endl;
    std::cout << "static_cast<int>(-1.6) = " << static_cast<int>(-1.6) << std::endl;
    std::cout << "static_cast<int>(-1.7) = " << static_cast<int>(-1.7) << std::endl;
    std::cout << "static_cast<int>(-1.8) = " << static_cast<int>(-1.8) << std::endl;
    std::cout << "static_cast<int>(-1.9) = " << static_cast<int>(-1.9) << std::endl;
    std::cout << "static_cast<int>(-2.0) = " << static_cast<int>(-2.0) << std::endl;
}
