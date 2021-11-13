/*
 * Key ideas:
 *
 *   - Small cheap things should be passed by value:
 *
 *       int, char*, std::pair<int, int>, ...
 *       
 *   - Big or expensive things should be passed by const reference:
 *
 *       std::string
 *
 * References:
 *
 *   [odwyer20211109] Three reasons to pass std::string_view by value
 *     https://quuxplusone.github.io/blog/2021/11/09/pass-string-view-by-value/
 */
