/*
 * References:
 *
 *   [cppreference] std::basic_string::replace
 *     https://en.cppreference.com/w/cpp/string/basic_string/replace
 */

#include <iostream>
#include <string>
 
int main()
{
    std::string str("The quick brown fox jumps over the lazy dog.");
    str.replace(10, 5, "red");
    str.replace(str.begin(), str.begin() + 3, 1, 'A'); // (6)
    std::cout << str << '\n';

    std::string s("The\nquick\nbrown\nfox.");

    std::string search("\n");
    std::string replace("\\n");
    size_t pos = 0;
    while ( (pos = s.find(search, pos)) != std::string::npos )
    {
         s.replace(pos, search.length(), replace);
         pos += replace.length();
    }

    std::cout << s << std::endl;
}
