/*
 * Key ideas:
 *   - Static variables marked with inline count as definitions.
 *     -> Guaranteed to exist only once in the program,
 *        even if included multiple times in multiple translation units.
 *     -> No need for .cpp files to define static/global objects
 *   - Might be initialized before main() or before first use.
 *   - constexpr implies inline.
 *
 * References:
 *
 *   [boccara20190723] What Every C++ Developer Should Know to (Correctly) Define Global Constants
 *     https://www.fluentcpp.com/2019/07/23/how-to-define-a-global-constant-in-cpp/
 *
 *   [gregoire20170828] C++17: Inline Variables
 *     http://www.nuonsoft.com/blog/2017/08/28/c17-inline-variables/
 *
 *   [josuttis201701XX] C++17: The Language Features - Nicolai Josuttis
 *     https://youtu.be/pEzV32yRu4U
 */

#include <iostream>

class WithStaticDataMember
{
    // Since C++17, this is a definition (since constexpr implies inline);
    // no further definition in a CPP file is required.
    static constexpr const char* debug_string = "DEBUG";
};

class C
{
public:
    static void log(bool b)
    {
        lg = b;
    }

    C()
    {
        if (lg) std::cout << "C::C()\n";
    }

private:
    static inline bool lg = false;
};

int main()
{
    C::log(true);
    C c1;
}
