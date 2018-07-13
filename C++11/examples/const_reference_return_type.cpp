/*
 * References:
 *
 *   [boccara20180713] The Incredible Const Reference That Isn’t Const
 *     https://www.fluentcpp.com/2018/07/13/the-incredible-const-reference-that-isnt-const/
 */

#include <iostream>

template<typename T>
class Wrapper
{
public:
    Wrapper(T const& value) : value_(value) {}
    
    T const& get() const { return value_; }
    
private:
    T value_;
};

int main()
{
    using IntRefWrapper = Wrapper<int&>;
    int a = 42;
    IntRefWrapper intRefWrapper(a);
    
    intRefWrapper.get() = 43;

    std::cout << "a is now " << a << '\n';
}
