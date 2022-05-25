/*
 * References:
 *
 *   [cppreference] std::tuple
 *     http://en.cppreference.com/w/cpp/utility/tuple
 *
 *   [chen20200629] Stupid std::tuple tricks: Finding a type in a tuple
 *     https://devblogs.microsoft.com/oldnewthing/20200629-00/?p=103910
 *
 *   [chen20200626] Mundane std::tuple tricks: Creating more interesting index sequences
 *     https://devblogs.microsoft.com/oldnewthing/20200626-00/?p=103904
 *
 *   [chen20200625] Mundane std::tuple tricks: Creating interesting index sequences
 *     https://devblogs.microsoft.com/oldnewthing/20200625-00/?p=103903
 *
 *   [chen20200624] Mundane std::tuple tricks: Selecting via an index sequence, part 2
 *     https://devblogs.microsoft.com/oldnewthing/20200624-00/?p=103902
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=34m15s
 */

#include <tuple>
#include <iostream>
#include <string>
#include <stdexcept>

std::tuple<double, char, std::string> get_student(int id)
{
    if (id == 0) return std::make_tuple(3.8, 'A', "Lisa Simpson");
    if (id == 1) return std::make_tuple(2.9, 'C', "Milhouse Van Houten");
    if (id == 2) return std::make_tuple(1.7, 'D', "Ralph Wiggum");
    throw std::invalid_argument("id");
}

int main()
{
    auto student0 = get_student(0);
    std::cout << "ID: 0, "
              << "GPA: " << std::get<0>(student0) << ", "
              << "grade: " << std::get<1>(student0) << ", "
              << "name: " << std::get<2>(student0) << '\n';

    // Note: from C++17 on, you can use structured bindings for this.

    double gpa1;
    char grade1;
    std::string name1;
    std::tie(gpa1, grade1, name1) = get_student(1);
    std::cout << "ID: 1, "
              << "GPA: " << gpa1 << ", "
              << "grade: " << grade1 << ", "
              << "name: " << name1 << '\n';
}
