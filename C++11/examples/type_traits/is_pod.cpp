/*
 * References:
 *
 *   [] CppCon 2015: Richard Powell “Intro to the C++ Object Model"
 *     https://youtu.be/iLiDezv_Frk?t=519
 */

#include <iostream>
#include <type_traits>
using std::cout;

struct Complex
{
    float real;
    float imag;
};

int main()
{
    cout << "is Complex a POD? " <<
        (std::is_pod<Complex>() ? "yes" : "no") << "\n";
}
