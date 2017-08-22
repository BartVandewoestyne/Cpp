/*
 * My own example on std::regex and the difference between std::regex_match
 * and std::regex_search.
 *
 * References:
 *   [1] https://youtu.be/IOxKjqC1Ozo
 *   [2] https://stackoverflow.com/questions/26696250/difference-between-stdregex-match-stdregex-search
 *   [3] https://channel9.msdn.com/Events/CPP/CppCon-2016/CppCon-2016-Tim-Shen-Regular-Expressions-in-C-Present-and-Future
 */

#include <iostream>
#include <regex>

int main()
{
    std::string s("one two three four");
    std::regex re("three");

    if (std::regex_match(s, re))
    {
        std::cout << "std::regex_match is true!" << std::endl;
    }

    if (std::regex_search(s, re))
    {
        std::cout << "std::regex_search is true!" << std::endl;
    }
}
