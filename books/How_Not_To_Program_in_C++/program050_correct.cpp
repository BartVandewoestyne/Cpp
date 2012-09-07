/************************************************
 * test bool_name, a function turn booleans into*
 *              text.                           *
 ************************************************/
#include <iostream>
#include <string>

/************************************************
 * bool_name -- given a boolean value, return   *
 *              the text version.               *
 *                                              *
 * Returns:                                     *
 *      Strings "true" or "false" depending     *
 *              on value.                       *
 ************************************************/
static const std::string bool_name(
    const bool value    // The value to check
)
{
    // The "true" value
    const std::string true_name("true");

    // The "false" value
    const std::string false_name("false");

    if (value == true)
        return (true_name);

    return (false_name);
}

int main() {
    std::cout << "True is " <<
        bool_name(true) << std::endl;

    std::cout << "False is " <<
        bool_name(false) << std::endl;
    return (0);
}
