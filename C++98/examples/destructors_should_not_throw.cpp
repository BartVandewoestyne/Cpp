/*
 * Key idea:
 *
 *   - Do not throw exceptions from a destructor!
 *
 * References:
 *
 *   [cppfaq] Can I throw an exception from a constructor? From a destructor?
 *     https://isocpp.org/wiki/faq/exceptions#ctor-exceptions
 *
 *   [cppfaq] How can I handle a destructor that fails?
 *     https://isocpp.org/wiki/faq/exceptions#dtors-shouldnt-throw
 *
 *   [cppcoreguidelines] E.16: Destructors, deallocation, and swap must never fail
 *     http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Re-never-fail
 *     http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Sd-never-fail
 */
