/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <iostream>
#include <string>
#include <string_view>

int main()
{
    using namespace std;

    string str = "   A lot of space";
    string_view strView = str;
    strView.remove_prefix(min(strView.find_first_not_of(" "), strView.size()));
    cout << str << endl // "   A lot of space
         << strView << endl; // "A lot of space"

    const char arr[] = {'A',' ','l','o','t',' ','o','f',' ',
			's','p','a','c','e','\0', '\0', '\0'};
    string_view strView2(arr, sizeof arr);
    const auto trimPos = strView2.find('\0');
    if(trimPos != strView2.npos) strView2.remove_suffix(strView2.size() - trimPos);
    cout << arr << ": " << sizeof arr << endl // A lot of space: 17
         << strView2 << ": " << strView2.size() << endl; // A lot of space: 14
}
