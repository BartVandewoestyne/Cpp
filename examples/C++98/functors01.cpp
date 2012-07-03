/**
 * This is the rewrite of lambda_expressions03.cpp which replaces the lambda
 * expressions with hand-coded functors.
 *
 * The struct that replaces each lambda has a field for each captured variable.
 * In the case of capture by value, each field is a copy of the captured local
 * variable.  In the case of capture by reference, each field is a reference to
 * the captured local variable.
 *
 * Reference:
 *
 *   http://software.intel.com/en-us/blogs/2012/06/08/performance-issues-for-c11-lambda-expressions/
 *
 */

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

struct f {
  int& k;
  f( int& k_ ) : k(k_) {}
  void operator()(int& i) {i=k++;}
};

struct g {
  int m, *p;
  g( int m_, int* p_ ) : m(m_), p(p_) {}
  void operator()(int& i) const {i=i*m; *p*=2;}
};

struct h {
  h() {}
  void operator()(int i) const {cout<<" "<<i;}
};

int main() {

  vector<int> v;
  v.resize(10);

  // Fill v with integers
  int k = 0;
  for_each( v.begin(), v.end(), f(k) );

  // Triple each element of v, and mangle m
  int m = 3;
  int* p = &m;
  for_each( v.begin(), v.end(), g(m,p) );

  // Print m
  cout << "m = " << m << endl;

  // Print v
  cout << "v =";
  for_each( v.begin(), v.end(), h() );
  cout << endl;

}
