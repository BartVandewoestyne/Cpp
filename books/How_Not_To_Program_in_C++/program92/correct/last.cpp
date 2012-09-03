/**
  * When the program is compiled with
  *
  *    g++ -g -Wall -o last last.cpp first.cpp
  *
  * it works.  But when compiled as
  *
  *   g++ -g -Wall -o last first.cpp last.cpp
  *
  * it fails.
  */

/***********************************************
 * print_name -- Print the name of a person.   *
 ***********************************************/
#include <iostream>
#include <string>

// The first name
extern std::string first_name;

// The last name
std::string last_name = "Jones";

// The full name
std::string full_name =
    first_name + " " + last_name;

int main()
{
    // Print the name
    std::cout << full_name << std::endl;
    return (0);
}
