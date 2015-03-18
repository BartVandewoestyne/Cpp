#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{

  std::ifstream in(argv[1]);
  std::vector<std::string> v;
  std::string line;

  while (std::getline(in, line))
  {
    v.push_back(line);
  }

  for (const auto& s : v)
  {
    std::istringstream iss(s);
    std::string word;
    while (iss >> word)
    {
      std::cout << word << std::endl;
    }
  }

}
