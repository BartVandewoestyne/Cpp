#include <iostream>

struct s {
    int mem[5] = {0, 1, 2, 3, 4};
};

double f()
{
    return 0.0;
}

int main()
{
    char x, y;
    int i = 0;
    bool a, b;
    s *p;

    // (a)
    std::cout << ( sizeof x + y  ) << std::endl;
    std::cout << ( (sizeof x) + y) << std::endl;

    // (b)
    std::cout << ( sizeof p->mem[i]  ) << std::endl;
    std::cout << ( sizeof(p->mem[i]) ) << std::endl;

    // (c)
    std::cout << ( sizeof a < b  ) << std::endl;
    std::cout << ( sizeof(a) < b ) << std::endl;

    // (d)
    std::cout << ( sizeof f()  ) << std::endl;
    std::cout << ( sizeof(f()) ) << std::endl;
}
