#include <string>

const std::string exclam = "!";
const std::string message = "Hello" + ", world" + exclam;

// The last line gives the error:
//
//   "invalid operands of types ‘const char [6]’ and ‘const char [8]’ to
//    binary ‘operator+’"
