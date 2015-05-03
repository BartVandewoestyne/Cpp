#include <iostream>
#include <regex>
#include <string>

using std::cout;
using std::endl;
using std::regex;
using std::regex_match;
using std::smatch;
using std::string;

int main()
{
  regex rx(".*aa.*", std::regex_constants::ECMAScript);
  smatch m;
  string s("aatest bbaard");
  if (regex_match(s, m, rx))
  {
      cout << m[0] << endl;
  } else {
      cout << "no match" << endl;
  }
}
