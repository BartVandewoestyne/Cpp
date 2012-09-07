/************************************************
 * test the find_double array.                  *
 ************************************* **********/
#include <iostream>
char test[] = "This is a test for double letters\n";
/************************************************
 * find_double -- Find double letters in an     *
 *      array.                                  *
 *                                              *
 * Returns:                                     *
 *      number of double letters in a string.   *
 ************************************************/
static int find_double(
    const char str[]   // String to check
) {
    int index; // Index into the string

    /*
     * Start prev_ch out with a strange value
     * so we don't match on the first
     * character of the string.
     */
    char prev_ch = '\0';
    for (index = 0; str[index] != '\0'; ++index) {
        if (prev_ch == str[index])
            return (index-1);
        prev_ch = str[index];
    }
    return (-1);
}

int main() {
    std::cout << "find_double= " <<
        find_double(test) << std::endl;
    return (0);
}
