/*
 * References:
 *
 *   [grimm2017cpplibrary] The C++ Standard Library, Second Edition, Rainer Grimm.
 */

#include <string>
#include <string_view>

void getString(const std::string& str){}
void getStringView(std::string_view strView){}

int main()
{
    const std::string large = "0123456789-123456789-"
                        "123456789-123456789"; // 41 bytes allocated
    const std::string substr = large.substr(10); // 31 bytes allocated

    std::string_view largeStringView{large.c_str(), // 0 bytes allocated
                                     large.size()};
    largeStringView.remove_prefix(10); // 0 bytes allocated

    getString(large);
    getString("0123456789-123456789-"
              "123456789-123456789"); // 41 bytes allocated
    const char message []= "0123456789-123456789-123456789-123456789";
    getString(message); // 41 bytes allocated

    getStringView(large); // 0 bytes allocated
    getStringView("0123456789-123456789-"
                  "123456789-123456789"); // 0 bytes allocated
    getStringView(message); // 0 bytes allocated
}
