/************************************************
 * Compute the length of a string entered by    *
 * the user.                                    *
 ************************************************/
#include <iostream>

/************************************************
 * length -- Find the length of a string        *
 *      (strlen does a better job.)             *
 *                                              *
 * Returns:                                     *
 *      length of the string.                   *
 ************************************************/
static int length(
    const char string[] // String to check
)
{
    int index;       // index into the string

    /*
     * Loop until we reach the
     * end of string character
     */
     for (index=0; string[index] != '\0';++index)
         /* do nothing */

     return (index);
}

int main()
{
    char line[100];    // Input line from user

    while (1) {
        std::cout << "Enter a string: ";
        std::cin.getline(line, sizeof(line));

        std::cout << "Length is " <<
            length(line) << '\n';
    }
    return (0);
}
