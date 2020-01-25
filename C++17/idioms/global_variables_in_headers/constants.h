/*
 * References:
 *
 *   [stackoverflow20100224] constant variables not working in header
 *     https://stackoverflow.com/questions/2328671/constant-variables-not-working-in-header
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "X.h"

inline const int ci = 10;

inline static const int sci = 20;  // TODO: for this one, the address is different in the two translation units.  Why???

inline const X x;

#endif
