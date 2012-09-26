/*
 * References:
 *   [1] http://www.daniweb.com/software-development/cpp/threads/131659/how-exactly-to-use-extern
 */

#include <iostream>

extern int hours; // This is declared globally in B.cpp.

int setHoursFromA()
{
  hours = 1;
}
