/*
 * PROBLEM 9
 * ---------
 * QUESTION:
 *   * Which of these, if any, is a robust way to print out a long long?
 *
 * ANSWER:
 *   * See comments in the code.
 *
 * NOTES BART:
 *   * There seem to exist lld and llx format specifiers, but I think they
 *     are not part of the C++ standard???
 *
 * REFERENCES:
 *   * http://stackoverflow.com/questions/5548670/llx-format-specifier-invalid-warning
 */

#include <iostream>

int main() {

long long n = -20000000000;     // minus twenty billion

  // Fails.
  printf("d:    %d\n", n);

  // Works, but not sure if it's robust...
  printf("ld:   %ld\n", n);

  // Fails.
  printf("p:    %p\n", n);

  // Works, but not sure if it's robust...
  std::cout << "cout: " << n << std::endl;

  return 0;

}
