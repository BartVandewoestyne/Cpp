/**
 * Important remarks:
 *
 *   1. operator<< is not a member function (Item 19 explains why).
 *
 *   2. the Rational object to be output is passed into operator<< as a
 *      reference-to-const rather than as an object (see Item 22).
 */

#include <iostream>
using namespace std;

class Rational {

public:
  Rational(int numerator = 0, int denominator = 1);

private:
  int n, d;   // numerator and denominator

friend ostream& operator<<(ostream& s, const Rational& r);

};


Rational::Rational(int numerator, int denominator)
  : n(numerator), d(denominator)
{}


ostream& operator<<(ostream& s, const Rational& r)
{
  s << r.n << '/' << r.d;
  return s;
}


int main()
{
  Rational r(3,4);
  std::cout << r << std::endl;
}
