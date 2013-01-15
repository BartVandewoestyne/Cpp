/**
 * References:
 *
 *   [1] http://j.mp/cpp11ref
 */

#include <thread>
#include <iostream>

int main()
{
    using namespace std;

    thread t1([](){
        cout << "Hi from thread " << endl;});

    t1.join();

    return 0;
}
