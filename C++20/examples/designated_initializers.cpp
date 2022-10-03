/*
 * References:
 *
 *   [elvert20220221] My favorite C++20 feature
 *     https://schneide.blog/2022/02/21/my-favorite-c20-feature/
 *
 *   [filipek20211122] Designated Initializers in C++20
 *     https://www.cppstories.com/2021/designated-init-cpp20/
 *
 *   [grimm20200706] Designated Initializers
 *     http://www.modernescpp.com/index.php/designated-initializers
 *
 *   [grimm20200706] C++20: Designated Initializers
 *     https://www.heise.de/developer/artikel/C-20-Designated-Initializers-4835833.html
 *
 *   [widlund20181119] Exploring C++20 - Designated initialisers
 *     https://blog.therocode.net/2018/11/exploring-cpp-20-designated-initializers
 */

struct Date {
    int year;
    int month;
    int day;
};

int main()
{
    // Old, less readable way.
    Date inFuture { 2050, 4, 10 };

    // New, more readable way.
    //Date inFuture { .year = 2050, .month = 4, .day = 10 };
}
