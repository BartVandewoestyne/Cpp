/*
 * References:
 *
 *   [grimm20171127] C++ Core Guidelines: Rules for Enumerations
 *     http://www.modernescpp.com/index.php/c-core-guidelines-rules-for-enumerations
 *
 *   [cppcoreguidelines] Enum.7: Specify the underlying type of an enumeration only when necessary
 *     http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Renum-underlying
 */

#include <iostream>

enum class Colour1 {
  red,
  blue,
  green
};
 
enum class Colour2 : char {
  red,
  blue,
  green
};

int main()
{
  std::cout << sizeof(Colour1) << std::endl;
  std::cout << sizeof(Colour2) << std::endl;
}
