/**
 * References:
 *
 *   [1] http://www.boost.org/libs/filesystem
 */

#include <iostream>
#include <boost/filesystem.hpp>
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cout << "Usage: tut1 path\n";
    return 1;
  }
  std::cout << argv[1] << " " << file_size(argv[1]) << '\n';
  return 0;
}
