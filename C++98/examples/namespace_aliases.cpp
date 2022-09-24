/*
 * Key idea:
 *
 *   - Namespace aliases allow the programmer to define an alternate name for a
 *     namespace.
 *     They are commonly used as a convenient shortcut for long or deeply-nested
 *     namespaces.
 *
 * References:
 *
 *   [cppreference] Namespace aliases
 *     https://en.cppreference.com/w/cpp/language/namespace_alias
 *
 *   [stackoverflow] Assigning namespaces in C++
 *     https://stackoverflow.com/questions/16001853/assigning-namespaces-in-c
 */

#include <iostream>
 
namespace foo {
    namespace bar {
         namespace baz {
             int qux = 42;
         }
    }
}
 
namespace fbz = foo::bar::baz;
 
int main()
{
    std::cout << fbz::qux << '\n';
}
