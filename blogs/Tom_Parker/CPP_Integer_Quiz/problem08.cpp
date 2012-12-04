/*
 * PROBLEM 8
 * ---------
 * QUESTION:
 *   * Which of these, if any, is a robust way to print out a size_t?
 *
 * ANSWER:
 *   * See comments in the code.
 */

#include <cstddef>
#include <cstdio>
#include <iostream>

int main() {

  //size_t n = 3000000000;    // three billion, for 32-bit machines
  size_t n = 20000000000;     // twenty billion, for 64-bit machines

  // Signed decimal integer: fails.
  printf("d:    %d\n", n);

  // Unsigned decimal integer: fails.
  printf("u:    %u\n", n);

  // Long signed decimal integer: works.
  printf("ld:   %ld\n", n);

  // Long unsigned integer: works.
  printf("lu:   %lu\n", n);

  // Pointer address: fails.
  printf("p:    %p\n", n);

  // Works.  Probably because operator<< also supports unsigned long as
  // argument.
  std::cout << "cout: " << n << std::endl; // Works.

  return 0;

}
