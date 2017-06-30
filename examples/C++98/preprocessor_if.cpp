#include <iostream>

int main()
{

#define PRINT_IT 0

#if PRINT_IT
    std::cout << "Hello world, from #if." << std::endl;
#endif

#ifdef PRINT_IT
    std::cout << "Hello world, from #ifdef." << std::endl;
#endif

}
