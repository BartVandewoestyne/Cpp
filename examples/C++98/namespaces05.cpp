/*
 * Fun with namespaces and explicit template specialization.
 *
 * References
 *   [1] https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-1-of-n
 */
#include <stdio.h>

namespace Foo {

    namespace Bar {

        // Primary template.
        template <typename T> struct Meow {
            void purr() {
                puts("Foo::Bar::Meow<T>::purr();");
            }
        };

        // Example 1: explicit specialization is in Foo::Bar.
        //template <> struct Meow<int> {
        //    void purr() {
        //        puts("Foo::Bar::Meow<int>::purr();");
        //    }
        //};

    }

    // Drag in the inner namespace Meow.
    using Bar::Meow;
    
}

// Example 2: explicit specialization is outside Foo::Bar.
// QUESTION:
//    - Lavavej thought this should fail to compile, but it compiles with his
//      version of Visual Studio (See [1] at 37:30).  With g++ 5.2.1 it fails
//      to compile.
template <> struct Foo::Meow<int> {
    void purr() {
        puts("Foo::Bar::Meow<int>::purr();");
    }
};


int main()
{
    // First looks in Foo for Meow, but because of the using-declaration also
    // looks in Bar for Meow.
    using Foo::Meow;

    Meow<long> l;
    l.purr();

    Meow<int> i;
    i.purr();
}
