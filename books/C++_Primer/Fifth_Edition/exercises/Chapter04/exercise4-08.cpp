#include <iostream>

bool f_true()
{
    std::cout << "f_true()" << std::endl;
    return true;
}

bool f_false()
{
    std::cout << "f_false()" << std::endl;
    return false;
}

int main()
{
    // The logical AND and OR operators always evaluate their left operand
    // before the right.  Moreover, the right operand is evaluated if and only
    // if the left operand does not determine the result.  This strateg is known
    // as short-circuit evaluation:
    //
    //   * The right side of an && is evaluated if and only if the left side is
    //     true.
    //   * The right side of an || is evaluated if and only if the left side is
    //     false.

    std::cout << "f_true() && f_true()" << std::endl;
    f_true() && f_true();
    std::cout << "f_true() && f_false()" << std::endl;
    f_true() && f_false();
    std::cout << "f_false() && f_true()" << std::endl;
    f_false() && f_true();
    std::cout << "f_false() && f_false()" << std::endl;
    f_false() && f_false();

    std::cout << "f_true() || f_true()" << std::endl;
    f_true() || f_true();
    std::cout << "f_true() || f_false()" << std::endl;
    f_true() || f_false();
    std::cout << "f_false() || f_true()" << std::endl;
    f_false() || f_true();
    std::cout << "f_false() || f_false()" << std::endl;
    f_false() || f_false();

    std::cout << "f_true() == f_true()" << std::endl;
    f_true() == f_true();
    std::cout << "f_true() == f_false()" << std::endl;
    f_true() == f_false();
    std::cout << "f_false() == f_true()" << std::endl;
    f_false() == f_true();
    std::cout << "f_false() == f_false()" << std::endl;
    f_false() == f_false();

    std::cout << "f_true() != f_true()" << std::endl;
    f_true() != f_true();
    std::cout << "f_true() != f_false()" << std::endl;
    f_true() != f_false();
    std::cout << "f_false() != f_true()" << std::endl;
    f_false() != f_true();
    std::cout << "f_false() != f_false()" << std::endl;
    f_false() != f_false();
}
