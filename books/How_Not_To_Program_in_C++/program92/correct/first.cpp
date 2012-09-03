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

#include <string>

// The first name of the key person
std::string first_name = "Bill";
