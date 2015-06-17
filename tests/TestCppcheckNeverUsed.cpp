#include <iostream>

bool doSomething(int x)
{
    std::cout << "x = " << x << std::endl;
    return false;
}

int main()
{
    {   // Scenario 1: cppcheck reports 'Variable retVal is assigned a value that is never used.'

        bool retVal = true;

        for (int i = 0; i < 5; ++i)
        {
            retVal = (retVal && doSomething(i));
        }
    }

    {   // Scenario 2: after 'fixing' the cppcheck style warning we get different behavior...

        for (int i = 0; i < 5; ++i)
        {
            doSomething(i);
        }
    }

    return 0;
}
