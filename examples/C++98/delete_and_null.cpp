/*
 * Example on nulling a pointer after deleting it.
 *
 * Advantages of nulling the pointer:
 *   - it avoids crashes on double deletes
 *
 * Disadvantages of nulling the pionter:
 *   - it masks double delete bugs and leaves them unhandled
 *
 * References:
 *  [1] http://stackoverflow.com/questions/1931126/is-it-good-practice-to-null-a-pointer-after-deleting-it
 *  [2] https://blogs.microsoft.com/cybertrust/2012/04/24/guarding-against-re-use-of-stale-object-references/
 */

#include <cstddef>

class Foo {};

int main()
{
  {
    Foo* foo = 0;  // Sets the pointer to 0 (C++ NULL)
    delete foo;  // Won't do anything
  }

  {
    Foo* foo = new Foo;
    delete foo;  // Deletes the object
    delete foo;  // Undefined behavior
  }
}
