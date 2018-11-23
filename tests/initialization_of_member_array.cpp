/*
 * Test to see how member arrays get initialized.
 */

#include <iostream>

class Door {
public:
    Door() { std::cout << "Door()" << std::endl; }
};

class House {
public:

    // Without initialization in the initializer list.
    House()
    {}
 
    // With initialization in the initializer list.
    //House()
    //    : x()
    //    , d()
    //{}

    print()
    {
        for (int i = 0; i < 3; ++i)
        {
            std::cout << x[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    int x[3];
    Door d[2];
};

int main()
{
    House h;
    h.print();
}
