/*
 * Compile this program as follows:
 *
 *   cl finddomain.cpp /Fefinddomain.exe /EHsc /link /DEFAULTLIB:advapi32.lib
 *
 * To run it multiple times in a row:
 *
 *   FOR /L %i IN (1,1,100) DO finddomain %username%
 *
 * To run it infinitely:
 *
 *   FOR /L %i IN () DO finddomain %username%
 */

#include <Windows.h>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Please use the program as follows:" << '\n';
        std::cout << "  finddomain \%username\%" << '\n';
        std::cout << "Example:" << '\n';
        std::cout << "  finddomain barvan34887" << '\n';
        return 0;
    }

    std::string accountName(argv[1]);
    
    //char szComputerName[15 +  20 + 1] = "ESTERLINE\\barvan34887"; // This gives ESTERLINE!
    char szComputerName[15 +  20 + 1];
    szComputerName[0] = '\0';
    strcat(szComputerName, "\\");
    strcat(szComputerName, accountName.c_str());

    PBYTE pSid = new BYTE[64];

    DWORD cbSid = 64;

    char* pDomainName = new char[64];
    memset(pDomainName, 0, 64 * sizeof(char));

    DWORD cchDomainName = 64;

    SID_NAME_USE eSidType;

    const auto result = LookupAccountNameA(
        NULL,
        szComputerName,
        pSid,
        &cbSid,
        const_cast<LPSTR>(pDomainName),
        &cchDomainName,
        &eSidType
    );

    if (result != 0)
    {
        std::cout << "Found domain " << pDomainName << "\n";
    }
    else
    {
        std::cout << "Could not find Windows domain name." << '\n';
        std::cout << "last error = " << GetLastError();
    }
}
