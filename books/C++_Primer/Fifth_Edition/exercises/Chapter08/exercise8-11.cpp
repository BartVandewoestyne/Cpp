#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main()
{
  std::string line;
  std::string word;
  std::vector<PersonInfo> people;
  std::istringstream record;

  while (std::getline(std::cin, line))
  {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word)
    {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
}
