/*
 * References:
 *
 *   [garland20211111] C++23 Standard Library Preview - Jeff Garland - Meeting C++ 2021
 *   https://youtu.be/rTVQe7zVQUw
 */

#include <string>
#include <fmt/core.h>  // TODO: change this once its standardized!

// This will construct a string with a nullptr.  In C++20, this
// gave a runtime exception, in C++23 this fails at compile time.
std::string doit()
{
    // some long block of complex code
    return nullptr;
}


int main()
{
  std::string s( "the answer is 42" );

  // 1. Addition of contains() and ends_with() member functions.
  if ( !s.contains( "foo" ) && s.ends_with( "42" ) ) 
  {

    fmt::print("so long, and thanks for all the fish\n");  // TODO: change this once it's standardized!
  }

  // 2. Constructs string from nullptr: runtime error in C++20, but should give compile-time error in C++23.
  std::string s = doit();
  fmt::print("{}\n", s);  // TODO: use std::print
}

