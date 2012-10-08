/**
 * References:
 *
 *   [1] http://akrzemi1.wordpress.com/2012/09/30/why-make-your-classes-final/
 *
 * TODO: this didn't seem to compile with g++ 4.6.2...
 */

struct B final {
  int i;
};

struct D : B { // ERROR
  int j;
};
