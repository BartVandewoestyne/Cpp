#include <iostream>

size_t f()
{
    static size_t cnt = 0;
    return cnt++;
}

int main()
{
    for (int i = 0; i < 10; ++i)
    {
        std::cout << f() << std::endl;
    }

}
