/**
 * References:
 *
 *   [1] http://www.boost.org/libs/filesystem
 */

#include <iostream>
#include <boost/filesystem.hpp>
using namespace std;
using namespace boost::filesystem;

int main(int argc, char* argv[])
{
  path p(argv[1]);

  cout << "p = " << p << std::endl;
  cout << "p.parent_path()--------: " << p.parent_path() << '\n';
  cout << "p.parent_path().parent_path()--------: " << p.parent_path().parent_path() << '\n';
  cout << "p.filename()-----------: " << p.filename() << '\n';
  cout << "p.stem()---------------: " << p.stem() << '\n';
  cout << "p.extension()----------: " << p.extension() << '\n';

  path p2 = p /= "test";
  //path p2 = p / "test";

  cout << "p = " << p << std::endl;
  cout << "p2 = " << p2 << std::endl;

  return 0;
}
