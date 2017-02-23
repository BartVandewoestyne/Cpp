/*
 * Program illustrating that if you throw from an extern "C" function, you
 * have undefined behavior.
 *
 * Compile in Visual Studio with:
 *
 *   cl /EHsc extern_c_function_throwing_exception.cpp        => warning
 *   cl /EHs cl /EHs extern_c_function_throwing_exception.cpp => no warning
 *
 * References:
 *   [1] http://stackoverflow.com/questions/15845681/can-c-functions-marked-as-extern-c-throw
 *   [2] http://stackoverflow.com/questions/24362616/does-the-c-standard-mandate-that-c-linkage-functions-are-noexcept?noredirect=1&lq=1
 */

#include <exception>

extern "C" void foo() { throw std::exception(); }

int main()
{
    try
    {
        foo();
    } catch (std::exception e) { return 1; }
}
