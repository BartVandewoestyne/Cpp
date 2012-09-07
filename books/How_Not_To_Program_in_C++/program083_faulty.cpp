/************************************************
 * Class tester.   Test constructor / destructor*
 *      calling.                                *
 ************************************************/
#include <iostream>

/************************************************
 * tester -- Class that tells the world when    *
 *      it's created and destroyed.             *
 ************************************************/
class tester {
    public:
        tester(void) {
            std::cout <<
                "tester::tester() called\n";
        }
        ~tester(void) {
            std::cout <<
                "tester::~tester() called\n";
        }
};

static tester a_var;    // Variable to test with

int main()
{
    std::cout << "In main\n";
    return (0);
}
