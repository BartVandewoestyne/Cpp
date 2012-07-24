/**
 * Program to illustrate the static keyword in the context of static linking.
 * Note that this form of the static keyword is considered deprecated and is
 * not guaranteed to be part of the C++ standard in the future.
 *
 * An alternative solution that avoids the static keyword is to employ anonymous
 * namespaces as shown on page 290.
 */
#include <iostream>
using namespace std;

// When using the static keyword here, at link time, we get the error:
//
//   /tmp/cc4FgqXy.o: In function `main':
//   FirstFile.cpp:(.text+0x5): undefined reference to `f()'
//   collect2: ld returned 1 exit status
//
//void f();
static void f();

void f()
{
  cout << "f\n";
}
