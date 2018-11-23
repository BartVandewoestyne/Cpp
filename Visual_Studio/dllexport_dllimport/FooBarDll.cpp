/**
 * Defines the exported functions for the DLL application. 
 *
 * Compile the source files into object files:
 *
 *   cl -c -nologo -EHsc -GR -Zc:forScope -Zc:wchar_t -FoFooBarDll -DFOOBAR_DLL_EXPORTS FooBarDll.cpp
 *
 * Create the dynamic library:
 *
 *   link -nologo -dll -out:libFooBarDll.dll FooBarDll.obj
 */

#include "FooBarDll.h"

#include <stdexcept>
#include <iostream>

using namespace std;

namespace foobar
{
    double Computer::add(double a, double b)
    {
        return a + b;
    }

    double Computer::subtract(double a, double b)
    {
        return a - b;
    }

    double Computer::multiply(double a, double b)
    {
        return a * b;
    }

    double Computer::divide(double a, double b)
    {
        if (b == 0)
        {
            throw invalid_argument("b cannot be zero!");
        }

        return a / b;
    }


    void Printer::printSomething()
    {
        std::cout << "Printer::printSomething()" << std::endl;
    }


    void Runner::run()
    {
        std::cout << "Runner::run()" << std::endl;
    }

    void Runner::walk()
    {
        std::cout << "Runner::walk()" << std::endl;
    }
}
