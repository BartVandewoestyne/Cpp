/************************************************
 * test the keyword finding function: "keyword" *
 ************************************************/
#include <cstring>
#include <iostream>

/************************************************
 * keyword -- return true if a keyword found    *
 ************************************************/
bool keyword(
    const char word[]   // The work to look for
)
{
    // A set of keywords
    static const char *key_list[] = {
        "bool",
        "int",
        "const",
        NULL
    };
    int i;      // Index into the list

    // Look for the keyword
    for (i = 0;  key_list[i] != 0; ++i) {
        if (std::strcmp(word, key_list[i]))
            return (true);
    }
    return (false);
}
int main()
{
    std::cout << "keyword(bool) = " <<
        keyword("bool") << '\n';

    std::cout << "keyword(sam) = " <<
        keyword("sam") << '\n';
    return (0);
}
