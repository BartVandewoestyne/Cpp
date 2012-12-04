/*
 * PROBLEM 11
 * ----------
 * QUESTION:
 *   A) Which of the iSquared variables, if any, accurately represent the value
 *      of ten thousand squared?
 *   B) Which of the jSquared variables, if any, accurately represent the value
 *      of one billion squared?
 *
 * ANSWER:
 *   A) Only the one declared as long.
 *   B) Only the one declared as long long.
 *
 * NOTES BART:
 *   * 2^26 < i*i = 10^8 < 2^27  -> requires 27 bits unsigned
 *   * 2^59 < j*j = 10^18 < 2^60 -> requires 60 bits unsigned
 *   * short: guaranteed from -32767 to 32767 (16 bits)
 *     int  : guaranteed from -32767 to 32767 (16 bits)
 *     long : guaranteed from -2147483647 to 2147483647 (32 bits)
 *     long long: guaranteed from -9223372036854775807 to 9223372036854775807 (64 bits, since C99)
 *     size_t: guaranteed from 0 to 65535 (16 bits, since C99)
 *
 * REFERENCES:
 *   * http://www.cplusplus.com/reference/clibrary/climits/
 *   * http://en.wikipedia.org/wiki/C_variable_types_and_declarations#Basic_types
 *   * http://stackoverflow.com/questions/4091826/size-guarantee-for-integral-arithmetic-types-in-c-and-c
 *   * http://stackoverflow.com/questions/4329777/is-long-guaranteed-to-be-at-least-32-bits
 *   * http://stackoverflow.com/questions/1089176/is-size-t-always-unsigned
 *   * http://stackoverflow.com/questions/918787/whats-sizeofsize-t-on-32-bit-vs-the-various-64-bit-data-models
 */

#include <cstddef>

int main() {

  short i = 10000;
  short  iSquared1 = i*i; // Unsafe.
  int    iSquared2 = i*i; // Unsafe.
  long   iSquared3 = i*i; // Safe.
  size_t iSquared4 = i*i; // Unsafe.

  int j = 1000000000;
  int       jSquared1 = j*j; // Unsafe.
  long      jSquared2 = j*j; // Unsafe
  long long jSquared3 = j*j; // Safe.
  size_t    jSquared4 = j*j; // Unsafe.

  return 0;

}
