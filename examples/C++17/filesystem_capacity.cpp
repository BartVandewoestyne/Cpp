/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <experimental/filesystem>  // TODO: remove 'experimental'
#include <iostream>

namespace fs = std::experimental::filesystem;  // TODO: remove 'experimental'

int main()
{
    const auto root = fs::space("/");
    const auto usr = fs::space("/usr");
    std::cout << ". Capacity Free Available\n"
              << "/ " << root.capacity << " "
              << root.free << " " << root.available << "\n"
              << "usr " << usr.capacity << " "
              << usr.free << " " << usr.available;
}
