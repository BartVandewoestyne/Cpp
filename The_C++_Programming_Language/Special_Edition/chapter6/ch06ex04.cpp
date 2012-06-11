/*
 * Write a table of values for the bitwise logical operations (§6.2.4) for all
 * possible combinations of 0 and 1 operands.
 *
 * See also:
 *   http://www.learncpp.com/cpp-tutorial/38-bitwise-operators/
 *   http://www.codeproject.com/Articles/2247/An-introduction-to-bitwise-operators
 */

#include <iostream>

using namespace std;

int main()
{

  bool ZERO = false;
  bool ONE = true;
  int x = 1;

  // AND
  cout << "0 & 0 = " << (0 & 0) << endl;
  cout << "0 & 1 = " << (0 & 1) << endl;
  cout << "1 & 0 = " << (1 & 0) << endl;
  cout << "1 & 1 = " << (1 & 1) << endl;

  // OR
  cout << "0 | 0 = " << (0 | 0) << endl;
  cout << "0 | 1 = " << (0 | 1) << endl;
  cout << "1 | 0 = " << (1 | 0) << endl;
  cout << "1 | 1 = " << (1 | 1) << endl;

  // XOR
  cout << "0 ^ 0 = " << (0 ^ 0) << endl;
  cout << "0 ^ 1 = " << (0 ^ 1) << endl;
  cout << "1 ^ 0 = " << (1 ^ 0) << endl;
  cout << "1 ^ 1 = " << (1 ^ 1) << endl;

  // NOT
  cout << "~0 = " << (~ZERO) << endl;
  cout << "~1 = " << (~ONE) << endl;

  // Left shift
  cout << "1<<1 = " << (1<<1) << endl;
  cout << "1<<2 = " << (1<<2) << endl;

  // Right shift
  cout << "8>>1 = " << (8>>1) << endl;
  cout << "8>>2 = " << (8>>2) << endl;

}
