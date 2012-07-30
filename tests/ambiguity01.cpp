/**
 * This example demonstrates an ambiguity-problem that I once came across.
 * I was able to solve the problem by changing 'complex' to 'std::complex'.
 */

#include <complex>

// Putting the using-line here gives the ambiguity from the moment the complexS
// struct is defined...
//using namespace std;

typedef struct complexS {
  double r;
  double i;
} complex;

typedef complex Complex;

// Putting the using-line here only gives the ambiguity error from here on...
//using namespace std;

//complex<double> x; // doesn't work: ambiguity error
std::complex<double> x; // works
