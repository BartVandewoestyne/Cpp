/*
 * References:
 *
 *   [stackoverflow20140515]
 *     https://stackoverflow.com/questions/23673577/shared-pointer-double-deleting
 *
 * TODO: why doesn't this crash with my g++ 8.3.0?
 */

#include <memory>

int main()
{
    int* a = new int(2);

    std::shared_ptr<int> b(a);
    std::shared_ptr<int> c(a);
}
