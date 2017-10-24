/*
 * References:
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=32m17s
 *
 *   [1] http://en.cppreference.com/w/cpp/utility/optional
 *
 *   [2] Overload 140, page 26
 *       [https://accu.org/var/uploads/journals/Overload140.pdf]
 */

#include <string>
#include <iostream>
#include <optional>
 
// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}
 
int main()
{
    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';
 
    // optional-returning factory functions are usable as conditions of
    // while and if
    if (auto str = create(true)) {
        std::cout << "create(true) returned " << *str << '\n';
    }
}
