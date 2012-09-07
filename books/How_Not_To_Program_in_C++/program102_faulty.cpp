/********************************************
 * Check a couple of zip codes.             *
 ********************************************/
#include <iostream>

int main()
{
    // A couple of zip codes
    const int cleveland_zip   = 44101;
    const int pittsburgh_zip  = 15201;

    if (cleveland_zip < pittsburgh_zip)
    {
        std::cout <<
            "Cleveland < Pittsburgh (Wrong)\n";
    }
    else
    {
        std::cout <<
            "Pittsburgh < Cleveland (Right)\n";
    }

    return (0);
}
