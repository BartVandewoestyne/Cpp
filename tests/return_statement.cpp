/**
 * Testprogram to check if parentheses around a return value may alter semantics.
 *
 * My current conclusion:
 *
 *   -> For C++98/03 I haven't found any reasons that it would make a difference.
 *
 *   -> For C++14 it can make a difference.
 *
 * References:
 *
 *   [1] http://stackoverflow.com/questions/3155789/brackets-around-0-in-return-0-statement-in-main-function-what-are-they
 *   [2] http://stackoverflow.com/questions/4762662/are-parentheses-around-the-result-significant-in-a-return-statement
 *
 * TODO: I haven't tested this code yet.  Check it with a C++14 compiler!
 */

decltype(auto) foo1() {
    int n;
    return (n);  // parentheses causes return type to be int&
}

decltype(auto) foo2() {
    int n;
    return n;  // no parentheses causes return type to be int
}

template<typename T> struct TD;

int main()
{
  // main.cpp:19:22: error: aggregate 'TD<int&()> f1' has incomplete type and cannot be defined TD<decltype(foo1)> f1;
  TD<decltype(foo1)> f1;

  // main.cpp:20:22: error: aggregate 'TD<int()> f2' has incomplete type and cannot be defined TD<decltype(foo2)> f2;
  TD<decltype(foo2)> f2;
}
