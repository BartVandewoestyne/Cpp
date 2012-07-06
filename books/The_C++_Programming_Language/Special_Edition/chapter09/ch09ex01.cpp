/**
 * (*2) Find where the standard library headers are kept on your system.  List
 * their names. Are any nonstandard headers kept together with the standard
 * ones?  Can any nonstandard headers be #included using the <> notation?
 */

/*
 * The standard library headers are on my system kept in
 *
 *   /usr/include/c++/<version>/
 *
 * To list their names, one can simply perform an ls.
 *
 * Page 1225 (Annex D) also provides 25 C-headers (for compatibility with the
 * C standard library).
 *
 * TODO: check the C++ standard for the official list of library headers.
 */

// This is an example of a non-standard header that is located on my system
// in /usr/include/c++/4.4.4 and apparently I can include it.
#include <cxxabi.h>
