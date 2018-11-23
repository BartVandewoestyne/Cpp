#ifndef FOOBAR_DLL_H
#define FOOBAR_DLL_H

#ifdef FOOBAR_DLL_EXPORTS
#define FOOBAR_DLL_API __declspec(dllexport) 
#else
#define FOOBAR_DLL_API __declspec(dllimport) 
#endif

namespace foobar
{

    // This class is exported from the MathFuncsDll.dll
    class Computer
    {
    public: 

        // Returns a + b
        static FOOBAR_DLL_API double add(double a, double b); 

        // Returns a - b
        static FOOBAR_DLL_API double subtract(double a, double b); 

        // Returns a * b
        static FOOBAR_DLL_API double multiply(double a, double b); 

        // Returns a / b
        // Throws const std::invalid_argument& if b is 0
        static FOOBAR_DLL_API double divide(double a, double b); 
    };


    class FOOBAR_DLL_API Printer
    {
    public:
        void printSomething();
    };


    class Runner
    {
    public:
        void FOOBAR_DLL_API run();
        void walk();
    };

}

#endif  // FOOBAR_DLL_H
