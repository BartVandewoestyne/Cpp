/*
 * In C++, const objects have internal linkage unless explicitly declared
 * extern.
 *
 * The method not using the extern keyword makes it easier for the compiler to
 * optimize the code, since it can see the actual value of the constant in each
 * translation unit.  But at the same time, conceptually you get separate,
 * independent constant objects in every translation unit.  For example, &a
 * will evaluate to a different address in each translation unit.
 *
 * The second method (using the extern keyword) creates truly global constants,
 * i.e. unique constant objects that are shared by the entire program.  For
 * example, &PI will evaluate to the same address in each translation unit.
 * But in this case the compiler can only see the actual values in one and only
 * one translation unit, which might impede optimizations.
 *
 * References:
 *
 *   [stackoverflow20120820] Define constant variables in C++ header
 *     https://stackoverflow.com/questions/12042549/define-constant-variables-in-c-header
 *
 *   [stackoverflow20120625] Declare and initialize constant in header file
 *     https://stackoverflow.com/questions/11194095/declare-and-initialize-constant-in-header-file
 *
 *   [stackoverflow20100224] constant variables not working in header
 *     https://stackoverflow.com/questions/2328671/constant-variables-not-working-in-header
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "X.h"

// This works in C++ because a name at namespace scope (including the global
// namespace) that is explicitly declared const and not explicitly declared
// extern has internal linkage, so this variable would not cause duplicate
// symbols when you link together translation units.
const int ci = 10;

// Alternatively, you could explicitly declare the constants as static.  This
// is more compatible with C and more readable for people that may not be
// familiar with C++ linkage rules.
//
// In C++ however, static is optional (because in C++, const objects have
// internal linkage by default).
static const int sci = 20;

// This has as a side effect that the name can be used as a compile time
// constant.
extern const int eci;

// This statement does *not* define a global constant!  Rather, it defines N
// global constants, with N being the number of .cpp files that include this
// header file.  Several independent objects will be created.  Notice the
// output of the program: the constructor is called three times: once for
// globals.cpp, once for file1.cpp and once for file2.cpp.  Note also that the
// order of initialization is undefined.
const X x;

#endif
