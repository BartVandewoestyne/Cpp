/**
 * Toy-program to illustrate stuff on passing parameters by value, pointer or ref.
 */

#include <iostream>

void g(int* x)
{
    *x = *x + 1;
}


void f(int& x)
{
    //g(x); // error!
    g(&x);
}

//void f(int x)
//{
//    // we are increasing the copy here!!!
//    g(&x);
//}

int main()
{
    int x = 5;

    f(x);

    std::cout << "x = " << x << std::endl;
}
