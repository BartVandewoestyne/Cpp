#include <iostream>
#include <string>

int main()
{
    std::string s;
    char buff[255];

    sprintf_s(buff, sizeof(buff), "    <TDRmode>%d</TDRmode>", 2);
    //sprintf(buff, "    <TDRmode>%d</TDRmode>", 2);
    s.assign(buff);

    std::cout << s << std::endl;
}
