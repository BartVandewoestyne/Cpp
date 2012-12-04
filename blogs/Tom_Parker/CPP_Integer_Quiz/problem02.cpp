/*
 * PROBLEM 2
 * ---------
 * QUESTION:
 *   * What is the output?
 *
 * ANSWER:
 *   * Nothing.
 *     sizeof returns something of type size_t which is defined in the <cstddef>
 *     header file (among others) as an unsigned integral type.  Therefore, in
 *     the smaller than comparison, i will get converted to an unsigned type and
 *     become larger than sizeof(double).
 *
 * REFERENCES:
 *   * http://eetimes.com/discussion/programming-pointers/4026076/Why-size-t-matters
 *   * http://stackoverflow.com/questions/131803/unsigned-int-vs-size-t
 */

#include <iostream>

using namespace std;

int main() {

  cout << "sizeof(double) = " << sizeof(double) << endl;
  cout << "static_cast<unsigned>(-2) = " << static_cast<unsigned>(-2) << endl;

  for (int i = -2; i < sizeof(double); ++i)
    std::cout << i << std::endl;

  return 0;

}
