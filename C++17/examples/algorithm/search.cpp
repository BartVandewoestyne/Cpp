/*
 * C++17 updated std::search algorithm in two ways:
 *
 *   - you can now use execution policy to run the default version of the algorithm but in a parallel way.
 *   - you can provide a Searcher object that handles the search.
 *
 * References:
 *
 *   [filipek20180820] Speeding up Pattern Searches with Boyer-Moore Algorithm from C++17
 *     https://www.bfilipek.com/2018/08/searchers.html
 */
