/*
 * Key ideas:
 *   - [[fallthrough]]; helps you to avoid compiler warnings for fallthroughs.
 *   - no [[fallthrough]] is necessary for empty case statements.
 *
 * Compile with:
 *   gcc --std=c++17 -Wextra
 *   clang --std=c++17 -Wimplicit-fallthrough
 *
 * References:
 *
 *   [gregoire20180604] C++17: Fallthrough in switch statements
 *     http://www.nuonsoft.com/blog/2018/06/04/c17-fallthrough-in-switch-statements/
 *   [karpov20180127] break and fallthrough
 *     https://www.viva64.com/en/b/0554/
 */

#include <iostream>

bool f()
{   
    switch (2)
    {
        case 1:
            std::cout << "hello world" << std::endl;
            //[[fallthrough]];  // necessary to avoid the fallthrough warning
        case 2: 
            return true;
        default:
            return false;
    }  
}

bool g()
{
    switch (2)
    {
        case 1:
            // no [[fallthrough]] necessary because of empty case statement
        case 2: 
            return true;
        default:
            return false;
    } 
}

int main()
{
}
