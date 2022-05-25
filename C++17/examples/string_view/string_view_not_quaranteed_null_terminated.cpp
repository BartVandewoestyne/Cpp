/*
 * Key idea:
 *
 *   std::string_views are not guaranteed to be null terminated!  Take that
 *   into consideration when calling C-interface APIs that expect C-style
 *   null-terminated strings.
 *
 * References:
 *
 *
 *   [cppreference] std::basic_string_view<CharT,Traits>::data (Notes)
 *     https://en.cppreference.com/w/cpp/string/basic_string_view/data
 *
 *   [reddit20211124] std::string_view could be made null character ending aware for interoperability with C
 *     https://www.reddit.com/r/cpp/comments/r17x40/stdstring_view_could_be_made_null_character/
 *
 *   [dicanio20210326] The Case of string_view and the Magic String
 *     https://blogs.msmvps.com/gdicanio/2021/03/26/the-case-of-string_view-and-the-magic-string/
 *
 *   [stackoverflow20161222] Using std::string_view with api, what expects null terminated string
 *     https://stackoverflow.com/questions/41286898/using-stdstring-view-with-api-what-expects-null-terminated-string
 */

#include <stdio.h>

#include <iostream>
#include <string>
#include <string_view>

void SomeCApi(const char* name)
{
    printf("Hello, %s!\n", name);
}

void DoSomething(std::string_view name)
{
    SomeCApi(name.data());
}

int main()
{
    std::string msg = "Connie is learning C++";
    auto untilFirstSpace = msg.find(' ');

    std::string_view v{ msg.data(), untilFirstSpace };

    std::cout << "String view: " << v << '\n';

    DoSomething(v);
}
