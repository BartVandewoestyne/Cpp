/************************************************
 * Combine strings with a variable length       *
 *      string class.                           *
 ************************************************/
#include <setjmp.h>
#include <iostream>
#include <cstring>

// Place to store jump information
static jmp_buf top_level;

// Longest string combination allowed.
static const unsigned int MAX_LENGTH = 30;

/************************************************
 * combine -- Combine two strings with          *
 *      limit checking                          *
 ************************************************/
static std::string combine(
    const std::string &first,   // First string
    const std::string &second   // Second string
)
{
    // Strings put together
    std::string together = first + second;

    if (together.length() > MAX_LENGTH) {
        longjmp(top_level, 5);
    }
    return (together);
}

int main()
{
    std::string first("First ");
    int i;

    for (i = 0; i < 10; i++) {

        // Save our place
        if (setjmp(top_level) == 0)
        {
            first = combine(first,
                    std::string("second "));
        } else {
            std::cout <<
                "Length limit exceeded\n";
            break;
        }
    }
    return (0);
}
