/**
 * References:
 *
 *   C++11 standard, section 12.9 'Inheriting constructors'.
 *
 * TODO: this does not compile yet???
 */

struct B1 {
  B1(int);
};

struct B2 {
  B2(int = 13, int = 42);
};

struct D1 : B1 {
  using B1::B1;
};

struct D2 : B2 {
  using B2::B2;
};
