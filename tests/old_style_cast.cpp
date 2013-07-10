/**
 * This is to demonstrate an issue I had at work, concerning a warning with
 * an old style cast.
 *
 * Compile with:
 *
 *   g++ -c --std=c++11 old_style_cast.cpp -Wold-style-cast
 *
 * Question:
 *
 *   How to fix this warning?
 */

typedef unsigned int TRAF_UINT32;
static const TRAF_UINT32 Infinite = (TRAF_UINT32)-1;
