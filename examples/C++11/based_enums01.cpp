/**
 * References:
 *
 *   [1] http://blog.smartbear.com/software-quality/bid/259230/closer-to-perfection-get-to-know-c11-scoped-and-based-enum-types
 */

enum class Bool: char {False, True}; // C++11 scoped and based enum

int main()
{
    int x = sizeof(Bool); // x = 1
    int y = static_cast<int>(Bool::False); // y = 0
    ++y;
}
