/*
 * References:
 *
 *   [cppreference] http://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
 *
 *   [guzman2017] A SIMPLE way to make your C++ programs easier to read NOW, Suffix for basic_string Literals - this little known feature can be extremely valuable
 *     http://swdevmastery.com/a-simple-way-to-make-your-c-programs-easier-to-read-now-suffix-for-basic_string-literals-this-little-known-feature-can-be-extremely-valuable/
 */

#include <string>
#include <iostream>
 
int main()
{
    using namespace std::string_literals;
 
    std::string s1 = "abc\0\0def";
    std::string s2 = "abc\0\0def"s;
    std::cout << "s1: " << s1.size() << " \"" << s1 << "\"\n";
    std::cout << "s2: " << s2.size() << " \"" << s2 << "\"\n";
}
