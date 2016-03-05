/*
 * Illustrate that argument-dependent name lookup only searches the namespace
 * that something was defined in.
 *
 * References
 *
 *   [1] https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Core-C-/Stephan-T-Lavavej-Core-C-1-of-n (39:25)
 */

#include <stdio.h>

namespace Foo {

    namespace Bar {

        struct Meow {};

        // Example 1: purr is in the same namespace as its Meow argument.
        //void purr(const Meow&) {
        //    puts("Foo::Bar::purr()");
        //}

    }

    // Drag in Bar's Meow into the outer namespace Foo.
    using Bar::Meow;

    // Example 2: purr is NOT in the same namespace as its Meow argument.
    void purr(const Meow&) {
        puts("Foo::purr()");
    }
    
}

int main()
{
    //Foo::Bar::Meow m;  // compiles with Example 1
    Foo::Meow m;         // compiles with Example 1, but not with Example 2!

    purr(m);  // This does argument-dependent name lookup for finding purr:
              //   -> search in addition to unqualified name lookup only in the
              //      true namespace in which the argument lives.  It won't
              //      search namespaces in which the argument *appears* to live.
}
