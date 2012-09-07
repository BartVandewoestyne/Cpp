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


int main()
{
    tester a_var;    // Variable to test with
    std::cout << "In main\n";
    return (0);
}
