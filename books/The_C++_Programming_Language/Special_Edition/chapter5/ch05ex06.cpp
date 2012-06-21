#include <iostream>
#include <cstring>

void f(char c)
{
  std::cout << c << std::endl;
}

void g(char& c)
{
  std::cout << c << std::endl;
}

void h(const char& c)
{
  std::cout << c << std::endl;
}

int main ()
{
  char c;
  unsigned char uc;
  signed char sc;

  f('a');  // legal
  f(49);   // legal
  f(3300); // legal, but overflow
  f(c);    // legal
  f(uc);   // legal
  f(sc);   // legal

  //g('a');  // not legal
  //g(49);   // not legal
  //g(3300); // not legal
  g(c);      // legal
  //g(uc);   // not legal
  //g(sc);   // not legal

  h('a');  // legal
  h(49);   // legal
  h(3300); // legal, but overflow
  h(c);    // legal
  h(uc);   // legal
  h(sc);   // legal
}
