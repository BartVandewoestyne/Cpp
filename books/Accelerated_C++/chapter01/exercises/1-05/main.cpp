// The given program for this exercise was not valid and results in the error
//
//   ‘x’ was not declared in this scope
//
// It can be solved by moving the right brace from the innermost code block
// one line down.

#include <iostream>
#include <string>

int main()
{
    { std::string s = "a string";
    { std::string x = s + ", really";
    std::cout << s << std::endl;
    std::cout << x << std::endl; }
    }
    return 0;
}
