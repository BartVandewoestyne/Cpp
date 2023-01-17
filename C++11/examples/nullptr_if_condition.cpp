/*
 * My own test program to check if nullptr can be used in an if-condition.
 *
 * Key idea:
 *
 *   - It seems like there are not hard objective arguments on why 'if (pointer)' should
 *     be preferred over 'if (pointer != null)', and things are mostly opinion based.
 *
 * References:
 *
 *   [stackoverflow20160731] difference between if(pointer) vs if(pointer != NULL) in c++, cpplint issue
 *     https://stackoverflow.com/questions/38682813/difference-between-ifpointer-vs-ifpointer-null-in-c-cpplint-issue
 *
 *   [stackoverflow20150513] Idiomatic way to compare to nullptr: if(p) vs if (p != nullptr)
 *     https://stackoverflow.com/questions/30218714/idiomatic-way-to-compare-to-nullptr-ifp-vs-if-p-nullptr
 *
 *   [stackoverflow20130721] Can I use if (pointer) instead of if (pointer != NULL)?
 *     https://stackoverflow.com/questions/17772103/can-i-use-if-pointer-instead-of-if-pointer-null
 */

#include <iostream>

void check(int* p)
{
    if (p)
    {
        std::cout << "p -> true" << std::endl;
    } else
    {
        std::cout << "p -> false" << std::endl;
    }
}

int main()
{
    int x = 0;

    int* px = &x;
    check(px);

    px = nullptr;
    check(px);
}
