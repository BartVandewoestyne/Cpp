/*
 * References:
 *
 *  [stackoverflow20180523] use of constexpr in header file
 *     https://stackoverflow.com/questions/50488831/use-of-constexpr-in-header-file
 *
 * See also the C++98 example.
 *
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "X.h"

// constexpr implies const and const on global/namespace scope implies static
// (internal linkage), which means that every translation unit including this
// header gets its own copy of ci. The memory for that static is only going to
// be allocated if an address or reference to it is taken, and the address is
// going to be different in each translation unit.
constexpr int ci = 10;

static constexpr int sci = 20;

// This fails, probably because x is not of a literal type...
//constexpr X x;

#endif
