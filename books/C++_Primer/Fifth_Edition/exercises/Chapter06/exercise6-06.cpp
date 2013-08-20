#include <iostream>

// Parameters are automatic objects.  Storage for the parameters is allocated
// when the function begins.  Parameters are defined in the scope of the
// function body.  Hence, they are destroyed when the function terminates.
int f_parameter(int x)
{
    return 2*x;
}

int f_local_variable()
{
    int x = 1;
    return 2*x;
}

// Local variables are variables whose lifetime continues across calls to the
// function.  Each local static object is initialized before the *first* time
// execution passes through the object's definition.  Local statics are not
// destroyed when a function ends; they are destroyed when the program
// terminates.
size_t f_local_static_variable()
{
    static size_t cnt = 0;
    return ++cnt;
}

int main()
{
    int a = f_parameter(1);
    std::cout << a << std::endl;

    int b = f_local_variable();
    std::cout << b << std::endl;

    int c = f_local_static_variable();
    std::cout << c << std::endl;
    c = f_local_static_variable();
    std::cout << c << std::endl;
    c = f_local_static_variable();
    std::cout << c << std::endl;
}
