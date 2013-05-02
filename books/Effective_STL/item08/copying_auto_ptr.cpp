#include "Widget.h"
#include <memory>
#include <iostream>
using namespace std;

int main()
{
    // pw1 points to a Widget TODO: ERRATA
    auto_ptr<Widget> pw1(new Widget);
    std::cout << "pw1 = " << pw1.get() << std::endl;

    // pw2 points to pw1's Widget.  pw1 is set to NULL (Ownership of the Widget
    // is transferred from pw1 to pw2).
    auto_ptr<Widget> pw2(pw1);
    std::cout << "pw1 = " << pw1.get() << std::endl;
    std::cout << "pw2 = " << pw2.get() << std::endl;

    // pw1 now points to the Widget again.  pw2 is set to NULL
    pw1 = pw2;
    std::cout << "pw1 = " << pw1.get() << std::endl;
    std::cout << "pw2 = " << pw2.get() << std::endl;
}
