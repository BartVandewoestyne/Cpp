/**
 * Several things are demonstrated in this example:
 *
 *   - the use of reinterpret_cast
 *   - how to print a char or char* as a number
 *   - whether char is signed or unsigned is implementation defined (TODO: check this!)
 *
 * References:
 *
 *   [galowicz20170122] A reinterpret_cast Trap
 *     https://blog.galowicz.de/2017/01/22/reinterpret_cast_trap/
 *
 *   [roseen20140604] Is it safe to cast an unsigned char* to char*, and treat the dereferenced pointer as if it really points to a char?
 *     http://stackoverflow.com/questions/24032322/is-it-safe-to-cast-an-unsigned-char-to-char-and-treat-the-dereferenced-pointe
 *
 *   [2] http://www.parashift.com/c++-faq/print-char-or-ptr-as-number.html
 *
 */

#include <climits>
#include <iostream>

void check_content(unsigned char* p, char* p_oc, char* p_rc)
{
    std::cout << std::endl;
    std::cout << "p = " << static_cast<void*>(p) << ", p_oc = " << static_cast<void*>(p_oc) << ", p_rc = " << static_cast<void*>(p_rc) << std::endl;
    std::cout << "*p = " << +*p << ", *p_oc = " << +*p_oc << ", *p_rc = " << +*p_rc << std::endl;  // See [2]
    std::cout << "*p = '" << *p << "', *p_oc = '" << *p_oc << "', *p_rc = '" << *p_rc << "'" << std::endl;

    if (*p_oc == *p)
    {
        std::cout << "content with old-style cast EQUALS original content" << std::endl;
    }
    else
    {
        std::cout << "content with old-style cast DOES NOT EQUAL original content" << std::endl;
    }


    // According to [1], neither the C++11 nor C++14 guarantee that this will be true.
    // See [basic.fundamental]p1 in both C++98, C++11 and C++14.
    if (*p_rc == *p)
    {
        std::cout << "content with reinterpret_cast EQUALS original content" << std::endl;
    }
    else
    {
        std::cout << "content with reinterpret_cast DOES NOT EQUAL original content" << std::endl;
    }
}


int main()
{
    std::cout << "sizeof(unsigned char) = " << sizeof(unsigned char) << std::endl;
    std::cout << "sizeof(char) = " << sizeof(char) << std::endl;
    std::cout << "p is unsigned char*" << std::endl;
    std::cout << "p_oc is char*" << std::endl;
    std::cout << "p_rc is char*" << std::endl;

    unsigned char c = 'c';
    unsigned char* p = &c;

    char* p_oc = (char*) p;                   // old-style pointer: compiles
    //char* p_sc = static_cast<char*>(p);     // static_cast: compiler error
    char* p_rc = reinterpret_cast<char*>(p);  // reinterpret_cat: compiles

    check_content(p, p_oc, p_rc);

    *p = 127;
    check_content(p, p_oc, p_rc);

    *p = 128;
    check_content(p, p_oc, p_rc);

    *p = 254;
    check_content(p, p_oc, p_rc);

    // If we assign the maximum value of an unsigned char to *p and *p_xx is
    // signed, *p_xx won't be able to represent this value.  We will overflow
    // *p_xx and it will, most likely, end up having the value of -1.
    *p = UCHAR_MAX;
    check_content(p, p_oc, p_rc);
}
