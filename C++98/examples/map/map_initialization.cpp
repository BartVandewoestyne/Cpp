#include <iostream>
#include <map>

std::map<int, std::string> create_map()
{
    std::map<int, std::string> m;
    m[1] = "Foo";
    m[2] = "Bar";
    return m;
}
static std::map<int, std::string> mymap = create_map();

int main()
{
  for (std::map<int,std::string>::const_iterator it = mymap.begin(); it != mymap.end(); ++it)
  {
      std::cout << it->first << " => " << it->second << '\n';
  }
}
