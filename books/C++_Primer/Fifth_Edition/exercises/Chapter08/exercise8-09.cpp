#include <iostream>
#include <sstream>
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
  std::istringstream iss("Hello World!");

  // TODO: we are not assigning the result to anything. Writing
  //    iss = read(iss);
  // does not work... so what is the cleanest way to solve this? 
  read(iss);
}
