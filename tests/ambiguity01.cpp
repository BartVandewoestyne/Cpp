/**
 * This example demonstrates an ambiguity-problem that I once came across.
 * I was able to solve the problem by changing 'complex' to 'std::complex'.
 */

#include <complex>

// using namespace std;  // putting the using-line here gives the ambiguity
                         // from the moment the complexS struct is defined...

typedef struct complexS {
  double r;
  double i;
} complex;

typedef complex Complex;


using namespace std; // putting the using-line here only gives the ambiguity
                     // error from here on...

std::complex<double> x; // works
//complex<double> x; // doesn't work: ambiguity error
