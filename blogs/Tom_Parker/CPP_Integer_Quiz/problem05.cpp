/*
 * PROBLEM 5
 * ---------
 * QUESTION:
 *   * Why does the second line generate a compiler warning?  How
 *     would you fix it?
 *
 * ANSWER:
 *   * The compiler warning is generated because the strlen function's return
 *     type is of type size_t.  Changing n's type to be of size_t solves the
 *     problem.
 *
 * NOTE BART:
 *   * I don't get a compiler warning for this, not even when I compile
 *     with g++ 4.6.2 and the command:
 *
 *	 g++ -Wall -Wextra -Weffc++ problem05.cpp 
 */
       

#include <cstring>

int main() {

  const char* s = "foo";
  int n = strlen(s);

  return 0;

}
