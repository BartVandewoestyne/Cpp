/**
 * Reference:
 *
 *   [mertz20180502] Trailing Return Types, East Const, and Code Style Consistency
 *     https://arne-mertz.de/2018/05/trailing-return-types-east-const-and-code-style-consistency/
 *
 *   [zemek20170117] Pros and Cons of Alternative Function Syntax in C++
 *     https://blog.petrzemek.net/2017/01/17/pros-and-cons-of-alternative-function-syntax-in-cpp/
 *
 *   [mertz20161130] Trailing return types everywhere
 *     http://arne-mertz.de/2016/11/trailing-return-types-everywhere/
 *
 *   [sumi20130604] Introduction to the C++11 feature: trailing return types
 *     https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/introduction_to_the_c_11_feature_trailing_return_types?lang=en
 */

#include <iostream>

template<typename T1, typename T2>
auto sum(const T1& t1, const T2& t2) -> decltype(t1 + t2)
{
    return t1 + t2;
}

int main()
{
    const auto i = 1;
    const auto j = 1.3;
    const auto k = sum(i,j);
    std::cout << k << std::endl;
}
