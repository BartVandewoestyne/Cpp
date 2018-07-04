/*
 * Example to illustrate how using std::weak_ptr is a good way to solve the
 * dangling pointer problem.
 *
 * References:
 *
 *   [user1434698_2012] When is std::weak_ptr useful?
 *     http://stackoverflow.com/questions/12030650/when-is-stdweak-ptr-useful
 */

#include <iostream>
#include <memory>

int main()
{
    /** Problem illustration **/

    int* ptr = new int(10);
    int* ref = ptr;
    delete ptr;  // Problem: ref will point to undefined data (dangling pointer)!


    /** Solution: check expired() or lock() to determine if pointer is valid. **/

    std::shared_ptr<int> sptr;

    sptr.reset(new int);
    *sptr = 10;

    // Get pointer to data without taking ownership.
    std::weak_ptr<int> weak1 = sptr;

    // Delete managed object and acquire new pointer.
    sptr.reset(new int);
    *sptr = 5;

    // Get pointer to new data without taking ownership.
    std::weak_ptr<int> weak2 = sptr;


    // Note that weak1 is expired!

    if (auto spt = weak1.lock()) {  // Has to be copied into a shared_ptr
        std::cout << *spt << '\n';  // before usage.
    } else {
        std::cout << "weak1 is expired\n";
    }

    // Note that weak2 still points to the new data (5).

    if (auto spt = weak2.lock()) {  // Has to be copied into a shared_ptr
        std::cout << *spt << '\n';  // before usage.
    } else {
        std::cout << "weak2 is expired\n";
    }
}
