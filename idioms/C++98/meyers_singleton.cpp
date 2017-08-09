/*
 * This implementation is not thread-safe??? (check why exactly)
 *
 * References:
 *   [1] More Effective C++, Scott Meyers, Item 26 'Limiting the number of
 *       objects of a class.' (check!)
 *   [2] Effective C++, Second Edition, Scott Meyers, Item 47: 'Ensure that
 *       non-local static objects are initialized before they're used.'
 *   [3] C++ and the Perils of Double-Checked Locking, Meyers S. and
 *       Alexandrescu Andrei,
 *       URL: http://www.aristeia.com/Papers/DDJ_Jul_Aug_2004_revised.pdf
 */
