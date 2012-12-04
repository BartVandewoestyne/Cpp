/*
 * PROBLEM 6
 * ---------
 * QUESTION:
 *   * Using an int for n generates a compiler warning, so size_t is used
 *     instead.  What problem does that create?  How would you fix it?
 *
 * ANSWER:
 *   * The variable count can overflow because size_t or size_type can possibly
 *     contain much higher values.  I would declare both the variables
 *     count and n to be of type size_type.
 *
 * NOTES BART:
 *   * I compile with g++ 4.6.2 and
 *
 *       g++ -c -Wall problem06.cpp
 *
 *     and I don't get compiler warnings.
 *   * I think it's even better to use size_type instead of size_t.
 *
 * REFERENCES:
 *   * http://stackoverflow.com/questions/4849678/c-for-loop-size-type-vs-size-t
 */

#include <vector>
#include <cstddef>

static int countTrailingZeros(const std::vector<int>& data)
{
    int count = 0;
    int n = data.size();  // VS compiler warning
    //size_t n = data.size();
    while (n - 1 >= 0 && data[n - 1] == 0)
    {
        ++count;
        --n;
    }
    return count;
}
