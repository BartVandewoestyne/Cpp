/*
 * Note: CTRL+D is EOF in Linux.
 */

#include <iostream>
#include <string>

std::istream& read(std::istream& is)
{
    std::string buf;
    while (is >> buf)
    {
        std::cout << buf << std::endl;
    }
    is.clear();
    return is;
}

int main()
{
  std::istream& is = read(std::cin);
  return 0;
}
