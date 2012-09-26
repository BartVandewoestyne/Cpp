/*
 * References:
 *   [1] http://www.daniweb.com/software-development/cpp/threads/131659/how-exactly-to-use-extern
 */

#include <iostream>

int hours; // Here we declare the object WITHOUT extern.

extern void setHoursFromA(); // extern is optional on this line

int main()
{
  setHoursFromA();
}
