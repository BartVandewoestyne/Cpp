/*
 * PROBLEM 4
 * ---------
 * QUESTION:
 *   * What is the output?
 *
 * ANSWER:
 *   * Output is -1294967296 due to overflow.
 *
 * NOTES BART:
 *   * At compilation, i also get the warning:
 *       "warning: this decimal constant is unsigned only in ISO C90 [enabled by default]"
 */

#include <iostream>

int main() {

  int n = 3000000000;   // 3 billion
  std::cout << n << std::endl;

  return 0;

}
