/**
 * References:
 *
 *   [kalev20130206] Closer to Perfection: Get to Know C++11 Scoped and Based Enum Types
 *     https://smartbear.com/blog/closer-to-perfection-get-to-know-c11-scoped-and-ba/
 */

enum class Bool: char {False, True}; // C++11 scoped and based enum

int main()
{
    int x = sizeof(Bool); // x = 1
    int y = static_cast<int>(Bool::False); // y = 0
    ++y;
}
