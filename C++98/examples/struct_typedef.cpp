/*
 * References:
 *
 *   [unkinkedash20171229] typedef struct or just struct
 *     http://www.cplusplus.com/forum/beginner/227625/
 *
 *   [criddell20090304] Difference between 'struct' and 'typedef struct' in C++?
 *     https://stackoverflow.com/questions/612328/difference-between-struct-and-typedef-struct-in-c
 */

struct Foo {
  int x;
  int y;
};


// Disadvantage:
//   * typedefs cannot be forward declared
typedef struct {
  int a;
  int b;
} Bar;


class Foo;    // OK.
//class Bar;  // Error!  Typedefs cannot be forward-declared.


int main()
{
  Foo f;
  Bar b;
}
