/**
 * Reference:
 *
 * http://software.intel.com/en-us/blogs/2012/06/08/performance-issues-for-c11-lambda-expressions/
 *
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main() {

  vector<int> v;
  v.resize(10);

  // Fill v with integers.  The first lambda expression here is
  //
  //   [&]( int& i ) {i=k++;}
  //
  // The [&] says to capture local variables by reference, meaning that the
  // identifier k inside the lambda expression is a reference to the local
  // variable k declared in main().  So each evaluation of the body "{i=k++}"
  // modifies the local variable k declared by main(). 
  int k = 0;
  for_each( v.begin(), v.end(), [&]( int& i ) {i=k++;});

  // Triple each element of v, and mangle m.  The second lambda expression is
  //
  //   [=]( int& i ) {i=i*m; *p*=2;}
  //
  // The [=] says to capture variables by value.  So even though each evaluation
  // of the lambda body modifies the local variable m via pointer p, the
  // captured copy of m is not modified.  So the "for_each" using that lambda
  // does indeed triple each element of vector v, while also doing ten doublings
  // of the m declared by main. 
  int m = 3;
  int* p = &m;
  for_each( v.begin(), v.end(), [=]( int& i ) {i=i*m; *p*=2;});

  // Print m.
  cout << "m = " << m << endl;

  // Print v.  The third lambda is
  //
  //   []( int i ) {cout<<" "<<i;}
  //
  // and captures nothing.
  cout << "v =";
  for_each( v.begin(), v.end(), []( int i ) {cout<<" "<<i;} );
  cout << endl;
}
