/*
 * Key idea:
 *
 *   When writing an implicit conversion operator to a type foo, write it as a
 *   template and constrain the type to be the same as foo:
 *
 *     template <std::same_as<foo> T>
 *     operator T() const noexcept;
 *
 *   That way, you prevent additional implicit conversions in the user-defined
 *   conversion sequence. This is especially important if foo is a built-in
 *   type.
 *
 * References:
 *
 *   [mueller20230706]
 *   https://www.foonathan.net/2023/07/constrain-user-defined-conversions/
 */

#include <concepts>

class string_literal
{
public:

    // Worse
    //operator const char*() const noexcept
    //{
    //    return m_ptr;
    //}

    // Better
    template <std::same_as<const char*> T>
    operator T() const noexcept
    {
        return m_ptr;
    }

private:
    const char* m_ptr;
};

int main()
{
    string_literal str;

    if (str) {}

    str + 1;
}
