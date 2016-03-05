/**
 * Defines the exported functions for the DLL application. 
 *
 * Compile the source files into object files:
 *
 *   cl -c -nologo -EHsc -GR -Zc:forScope -Zc:wchar_t -FoMathFuncsDll -DMATHFUNCSDLL_EXPORTS MathFuncsDll.cpp
 *
 * Create the dynamic library:
 *
 *   link -nologo -dll -out:libMathFuncsDll.dll MathFuncsDll.obj
 */

//#include "stdafx.h"
#include "MathFuncsDll.h"
#include <stdexcept>

using namespace std;

namespace MathFuncs
{
    double MyMathFuncs::Add(double a, double b)
    {
        return a + b;
    }

    double MyMathFuncs::Subtract(double a, double b)
    {
        return a - b;
    }

    double MyMathFuncs::Multiply(double a, double b)
    {
        return a * b;
    }

    double MyMathFuncs::Divide(double a, double b)
    {
        if (b == 0)
        {
            throw invalid_argument("b cannot be zero!");
        }

        return a / b;
    }
}
