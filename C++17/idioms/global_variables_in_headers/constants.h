/*
 * Key idea:
 *
 *   You should use constexpr for your constants in header files, if possible,
 *   otherwise const. And if you require the address of that constant to be the
 *   same everywhere mark it as inline.
 *
 * References:
 *
 *   [stackoverflow20100224] constant variables not working in header
 *     https://stackoverflow.com/questions/2328671/constant-variables-not-working-in-header
 *
 *   [stackoverflow] Static variables in C++
 *     https://stackoverflow.com/questions/3698043/static-variables-in-c
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "X.h"

// In C++17 you can also make your constants inline, so that there is only ever
// a single copy of the constant if an address or reference to it is taken
// (i.e. not static).  inline variables were introduced in C++17 to allow for
// header-only libraries with non-const variable definitions in the header
// files.
inline const int ci1 = 10;
inline constexpr int ci2 = 10;

// Note that constexpr on static data members implies inline, so inline is
// actually unnecessary here...
//
// Furthermore, by declaring the variables as static here, it will have
// 'internal linkage' and every translation unit that includes this header will
// get its *own*, *individual* variable (which is not visible outside your
// translation unit).  So if you have N .cpp files that include this header,
// you will have N individual copies of these static constant variables.
inline static const int sci1 = 20;  // TODO: for this one, the address is different in the two translation units.  Why???
inline static constexpr int sci2 = 20;  // TODO: for this one, the address is different in the two translation units.  Why???

// Note that even when more than one file include this header, only one X will be
// constructed (before main() is called)!  This is not the case in the C++98 example
// where we cannot use the inline keyword.
//
// The inline keyword tells the compiler to not define the object in every
// file, but rather to collaborate with the linker in order to place the object
// in only of of the generated binary files.
inline const X x1;

#endif
