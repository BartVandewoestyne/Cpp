/*
 * PROBLEM 10
 * ----------
 * QUESTION:
 *   A) What is the output of this program?
 *   B) Swap the operands.  What is the output?
 *   C) What is the proper data type for the difference of pointers?
 *
 * ANSWER:
 *   A)
 *     offset1 = 2
 *     offset2 = 2
 *     offset3 = 2
 *
 *   B)
 *     offset4 = -2
 *     offset5 = 4294967294
 *     offset6 = 18446744073709551614
 *
 *   C) ptrdiff_t from <cstddef>
 */

#include <cstddef>
#include <iostream>

int main() {

  double x[] = {0.0, 1.0, 2.0, 3.0, 4.0, 5.0};
  double* xPtr = &x[1];
  double* yPtr = &x[3];

  int      offset1 = yPtr - xPtr;
  unsigned offset2 = yPtr - xPtr;
  size_t   offset3 = yPtr - xPtr;
  std::cout << "offset1 = " << offset1 << std::endl;
  std::cout << "offset2 = " << offset2 << std::endl;
  std::cout << "offset3 = " << offset3 << std::endl;

  int      offset4 = xPtr - yPtr;
  unsigned offset5 = xPtr - yPtr;
  size_t   offset6 = xPtr - yPtr;
  std::cout << "offset4 = " << offset4 << std::endl;
  std::cout << "offset5 = " << offset5 << std::endl;
  std::cout << "offset6 = " << offset6 << std::endl;

  // ADDED BY BART
  ptrdiff_t offset7 = yPtr - xPtr;
  ptrdiff_t offset8 = xPtr - yPtr;
  std::cout << "offset7 = " << offset7 << std::endl;
  std::cout << "offset8 = " << offset8 << std::endl;

  return 0;

}
