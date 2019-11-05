/*
 * My own example on std::regex and the difference between std::regex_match
 * and std::regex_search.
 *
 * References:
 *
 *   [grimm20190722] Mehr Regeln zu regulären Ausdrücken
 *     https://www.heise.de/developer/artikel/Mehr-Regeln-zu-regulaeren-Ausdruecken-4475875.html
 *
 *   [grimm20190718] More Rules to the Regular Expression Library
 *     http://www.modernescpp.com/index.php/more-rules-to-the-regular-expression-library
 *
 *   [grimm20190715] "The Regular Expression"-Bibliothek
 *     https://www.heise.de/developer/artikel/The-Regular-Expression-Bibliothek-4469602.html
 *
 *   [turner20170508] C++ Weekly - Ep 62 - std::regex
 *     https://youtu.be/IOxKjqC1Ozo
 *
 *   [shen20161102] CppCon 2016: Tim Shen “Regular Expressions in C++, Present and Future"
 *     https://channel9.msdn.com/Events/CPP/CppCon-2016/CppCon-2016-Tim-Shen-Regular-Expressions-in-C-Present-and-Future
 *
 *   [stackoverflow20141102] Difference between std::regex_match & std::regex_search?
 *     https://stackoverflow.com/questions/26696250/difference-between-stdregex-match-stdregex-search
 */

#include <iostream>
#include <regex>

int main()
{
    //std::string s("one two three four");
    //std::regex re("three");
    
    std::string s("foo$.xml");
    std::regex re("(.*)\\$.xml");

    if (std::regex_match(s, re))
    {
        std::cout << "std::regex_match is true!" << std::endl;
    }

    if (std::regex_search(s, re))
    {
        std::cout << "std::regex_search is true!" << std::endl;
    }
}
