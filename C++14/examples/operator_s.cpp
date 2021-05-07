/*
 * Key ideas:
 *   * You can use operator_s for type deduction.
 *   * You can use operator_s to initialize a std::string with null characters '\0':
 *   * It enables you to write shorter and clearer code.
 *   * Don't use it if you don't want a string, but only a character array or
 *     pointer to a character array.
 *
 * References:
 *
 *   [cppreference] http://en.cppreference.com/w/cpp/string/basic_string/operator%22%22s
 *
 *   [guzman2017] A SIMPLE way to make your C++ programs easier to read NOW, Suffix for basic_string Literals - this little known feature can be extremely valuable
 *     http://swdevmastery.com/a-simple-way-to-make-your-c-programs-easier-to-read-now-suffix-for-basic_string-literals-this-little-known-feature-can-be-extremely-valuable/
 */

#include <string>
#include <iostream>

// You need this to be able to use operator""s.
using namespace std::string_literals;

// Type deduction
auto fn()
{
    return "fn returns a std::string"s;
}

// Type deduction
template<typename T>
void g(T&& param)
{
    // ...
}

int main()
{
    // Type deduction
    auto str = "I am a std::string"s;  // str's type is std::string

    // Type deduction
    g("param's type is rvalue reference to std::string"s);

    // Initialize with null characters.
    std::string s1 = "here is a null char: \0, yeah..."s;

    // Shorter and clearer code:
    //auto s = std::string{"foo"};
    // vs
    auto s2 = "foo"s;

    // Shorter and clearer code:
    g("cool"s);
    // vs
    //g(std::string("not as cool"));
 
    std::string s3 = "abc\0\0def";
    std::string s4 = "abc\0\0def"s;
    std::cout << "s3: " << s3.size() << " \"" << s3 << "\"\n";
    std::cout << "s4: " << s4.size() << " \"" << s4 << "\"\n";
}
