/*
 * References:
 *
 *   [johnston20170726] std::string vs C-strings
 *     https://embeddedartistry.com/blog/2017/7/24/stdstring-vs-c-strings
 */

#include <iostream>
#include <string>

int main()
{
    /** C-style strings **/

    const char* str = "This is a string literal. See the double quotes?";


    /** std::string **/

    // Declaration

    std::string my_str;
    std::string name("Phillip");
    std::string name2(name);
    std::string lip(name, 4);
    std::string filled(16, 'A');

    // Assignment

    my_str = "Phillip";
    my_str = filled;
    my_str = std::move(name2);

    // Comparing strings

    if (my_str == name2)
    {
        std::cout << "my_str and name2 match!" << std::endl;
    }

    if (my_str == "Phillip")
    {
        std::cout << "my_str and \"Phillip\" match!" << std::endl;
    }

    std::string string1("Adam");
    std::string string2("Bart");

    if (string1 < string2)
    {
        std::cout << "string1 comes first lexicographically" << std::endl;
    }

    if (!string1.compare(string2))
    {
        std::cout << "These strings are equal" << std::endl;
    }

    // TODO: fix this!
    // int x = 3;
    // int y = 2;
    // if (!string1.compare(string2, x, y))
    // {
    //     std::cout << "String 1 is equal to the substring of String 2" << std::endl;
    // }

    // Concatenating Strings

    my_str = lip + name2;
    my_str += "lip";  // C-string cat works too

    {
        std::string my_str("test");
        std::string str2("boo");
        const char* c_str = "This is a c_str";

        // We can append a string
        my_str.append(str2);
        my_str.append(c_str);

        // We can append X characters from the beginning of a string
        my_str.append(str2, 2);
        my_str.append(c_str, 2);

        // We can also append a substring, starting at index X and of length Y
        my_str.append(str2, 1, 4);
        my_str.append(c_str, 1, 4);
    }
}