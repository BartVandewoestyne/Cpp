/*
 * References:
 *
 *   [garland20211111] C++23 Standard Library Preview - Jeff Garland - Meeting C++ 2021
 *   https://youtu.be/rTVQe7zVQUw
 */

#include <string>
#include <fmt/core.h>  // TODO: change this once its standardized!

int main()
{
  std::string s( "the answer is 42" );
  if ( !s.contains( "foo" ) && s.ends_with( "42" ) ) 
  {
    fmt::print("so long, and thanks for all the fish\n");
  }
}

