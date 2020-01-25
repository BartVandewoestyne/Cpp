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

constexpr int ci = 10;

static constexpr int sci = 20;

// This fails, probably because x is not of a literal type...
//constexpr X x;

#endif
