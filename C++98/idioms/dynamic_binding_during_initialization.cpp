/*
 * One should not call virtual functions from inside a constructor.  This is a
 * solution for that.
 *
 * References:
 *
 *   [cppidioms] More C++ Idioms/Calling Virtuals During Initialization
 *     https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Calling_Virtuals_During_Initialization
 *
 *   [cppfaq]
 *     https://isocpp.org/wiki/faq/strange-inheritance#calling-virtuals-from-ctor-idiom
 */
