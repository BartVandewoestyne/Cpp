#include <vector>

unsigned some_value()
{
    return 1;
}

int get_value()
{
    return 2;
}

int main()
{
    std::vector<unsigned> ivec = { 1, 2, 3 };

    unsigned index = some_value();
    
    int ix = 0;                        // FIX: move declaration of ix here.
    switch (index) {
        case 1:
            // int ix = get_value();   // FIX
            ix = get_value();          // FIX
            ivec[ ix ] = index;
            break;
        default:
            ix = ivec.size() - 1;
            ivec[ ix ] = index;
    }
}
