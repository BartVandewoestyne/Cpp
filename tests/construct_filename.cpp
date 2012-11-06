/**
 * This example shows how string streams can be used to construct a filename
 * that has a number in it, possibly padded with zeros.
 *
 * References:
 *   [1] http://www.cplusplus.com/forum/general/15952/
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
  std::ostringstream ss;
  ss << std::setw(7) << std::setfill('0') << 1;

  std::string filename("test_");
  filename += ss.str();
  filename += ".dat";

  std::cout << filename << std::endl;
}
