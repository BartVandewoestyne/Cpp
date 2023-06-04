/*
 * Key ideas:
 *   - A consteval-function must be evaluated at compile-time or compilation
 *     fails.  With that, a consteval-function is a stronger version of
 *     constexpr-functions.  We have now the choice:
 *       - compile-time only    => consteval
 *       - compile- or run-time => constexpr
 *       - run-time             => no attribute required
 *
 * References:
 *
 *   [filipek20221128] const vs constexpr vs consteval vs constinit in C++20
 *     https://www.cppstories.com/2022/const-options-cpp20/
 *
 *   [fertig20210706] C++20: A neat trick with consteval
 *     https://andreasfertig.blog/2021/07/cpp20-a-neat-trick-with-consteval/
 */

consteval int Calc(int x)
{
    return 4*x;
}

int main() {

    // Note that making res and Calc constexpr is not possible in this example,
    // because res being constexpr means that res is implicitly const, and
    // therefore we would not be able to modify it.  When using consteval for
    // Calc, we can.
    auto res = Calc(2);  // Compile-time due to consteval

    ++ res;  // Still possible to modify res at run-time.
}
