/*
 * References:
 *
 *   [khizbullin20200924] C++17 structured bindings for more safe, functional code
 *     https://itnext.io/c-17-structured-bindings-for-more-safe-functional-code-c0c5b4d31b0d
 *
 *   [boccara20180619] 3 Simple C++17 Features That Will Make Your Code Simpler
 *     https://www.fluentcpp.com/2018/06/19/3-simple-c17-features-that-will-make-your-code-simpler/
 *
 *   [doumler2017] The new C++17 and why it's good for you - Timur Doumler, ADC 2017
 *     https://youtu.be/ky_eXBMcJK0?t=4m59s
 *
 *   [gregory2017cppcon] 10 Core Guidelines You Need to Start Using Now
 *     https://youtu.be/XkDEzfpdcSg?t=34m15s
 *
 *   [1] http://insights.dice.com/2016/12/15/breaking-down-current-state-c-17/
 *
 *   [2] https://skebanga.github.io/structured-bindings/
 *
 *   [3] http://www.nuonsoft.com/blog/2017/07/26/c17-structured-bindings/
 */

int main()
{

    // Iterating over a map using structured bindings:
    std::map<int, int> m;
    for (const auto& [key, value] : m)
    {
        std::cout << key << std::endl;
        std::cout << value << std::endl;
    }

}
