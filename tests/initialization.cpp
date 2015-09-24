/*
 * Illustrate some of the vagaries of C++ initialization.
 *
 * Reference:
 *
 *   [1] http://scottmeyers.blogspot.be/2015/09/thoughts-on-vagaries-of-c-initialization.html
 *   [2] http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3922.html
 */

#include <atomic>

int main()
{
    int x1 = 0;    // copy initialization
    int x2(0);     // direct initialization
    int x3 = {0};  // copy list initialization
    int x4{0};     // direct list initialization

    //std::atomic<int> x5 = 0;  // error!
    std::atomic<int> x6(0);     // fine
    std::atomic<int> x7 = {0};  // fine
    std::atomic<int> x8{0};     // fine

    auto x9 = 0;     // x9's type is int                         (also under N3922)
    auto x10(0);     // x10's type is int                        (also under N3922)
    auto x11 = {0};  // x11's type is std::initializer_list<int> (also under N3922)
    auto x12{0};     // x12's type is std::initializer_list<int> (but x12's type is int under N3922)
}
