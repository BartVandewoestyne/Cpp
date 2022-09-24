/*
 * Key ideas:
 *
 *   - To iterate backwards through a list or vector, you can use a
 *     reverse_iterator.  A reverse iterator is made from a bidirectional, or
 *     random access iterator which it keeps as a member which can be accessed
 *     through base().  To iterate backwards use rbegin() and rend() as the
 *     iterators for the end of the collection, and the start of the collection
 *     respectively.
 *
 * References:
 *
 *   [cppreference] std::reverse_iterator
 *     https://en.cppreference.com/w/cpp/iterator/reverse_iterator
 *
 *   [riptutorial] Reverse Iterators
 *     https://riptutorial.com/cplusplus/example/5101/reverse-iterators
 *
 *   [chen20211112] Another way of looking at C++ reverse iterators
 *     https://devblogs.microsoft.com/oldnewthing/20211112-00/?p=105908
 *
 *   [stackoverflow20100831] Iterating C++ vector from the end to the beginning
 *     https://stackoverflow.com/questions/3610933/iterating-c-vector-from-the-end-to-the-beginning
 */

#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for (std::vector<int>::reverse_iterator it = v.rbegin();
         it != v.rend();
         ++it)
    {
        std::cout << *it << std::endl;
    }
}
