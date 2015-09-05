/**
 * Program to illustrate several things related to equality operator: 
 *
 *   - If no operator== is defined, then the compiler does not generate one for you.
 *   - operator== is best defined as a friend function (see [1])
 *
 * References:
 *
 *   [1] https://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=523
 */

#include <iostream>

// Without this define, we get a compiler error because the compiler does not
// automatically generate an operator== for us.  If we use this define,
// then we have an operator== available and the code compiles and runs.
#define HAS_OPERATOR_EQUALS

struct Foo {
  int x;
  int y;

#ifdef HAS_OPERATOR_EQUALS
  friend bool operator==(const Foo& lhs, const Foo& rhs);
#endif

};


#ifdef HAS_OPERATOR_EQUALS
bool operator==(const Foo& lhs, const Foo& rhs)
{
    return lhs.x == rhs.x &&
           lhs.y == rhs.y;
}
#endif


int main()
{
    Foo a;
    Foo b;
    
    a.x = 1;
    b.x = 1;
    a.y = 2;
    b.y = 2;

    if (a == b)
    {
        std::cout << "They are equal!" << std::endl;
    }
    else
    {
        std::cout << "They are NOT equal!" << std::endl;
    }
}
