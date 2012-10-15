/**
 * Reference:
 *
 *   [1] http://blog.smartbear.com/software-quality/bid/222929/c11-tutorial-let-your-compiler-detect-the-types-of-your-objects-automatically
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int func();
int func1();
int func2();
int& func_ref();

class A {
public:
  int f(int x);
};
int (A::*pmf) (int) = &A::f;       // pointer to member

class Foo {
};

/* C++11 Style Function Declarations */
auto newfunc(bool b)->decltype(b)
{
  return b;
}

template <class T> auto get_end(vector<T>& v)->decltype(v.end())
{ 
  // return type is vector<T>::iterator
  return v.end();
}

int main()
{
  /* Some stuff we need for the examples. */
  vector<Foo> vf;
  const vector<Foo> cvf;
  float f;

  /* auto declarations */

  auto x = 0;
  const auto PI = 3.14;
  auto curiosity_greeting = string("hello universe");
  auto dirty = true;
  auto p = new char [1024];
  auto distance = 10000000000LL;
  auto pf = func;


  /* const, arrays and reference variables */

  volatile auto z = 5;             // volatile int

  auto volatile const flag = true; // const volatile bool

  auto const y = 'a';              // const char

  auto iarr = {0,1,2,3};           // int [4]

  // TODO: does not work with g++ 4.6.2?
  //auto arrarr = {{0,1},{0,1}};     // int[2][2] // DOES NOT WORK YET?

  auto pf_arr = {func1, func2};    //array  int (*[2])()

  auto pmf_arr = {pmf,pmf};        //array int (A::*[2]) (int)

  auto x2 = func_ref();                    // x is int, not int&

  auto& xref = func_ref();                // xref is int&

  // TODO: does not work with g++ 4.6.2/
  //auto x3=5, d=0.54, flag2=false, arr={1,2,3}, pf=func;


  /* Operator decltype */

  decltype (x) z2=x;          // same as auto z=x;
  typedef decltype (x) XTYPE;  // XTYPE is a synonym for int
  XTYPE y2=5;

  // TODO: does not work with g++ 4.6.2.
  typedef decltype(vf.begin()) ITER;
  //for (ITER it=vf.begin(); it<vf.end(); it++)
  //  cout << *it << endl;

  typedef decltype(12) INT;  // a literal value

  typedef decltype(f) FLOAT; // a variable

  typedef decltype (std::vector<int>()) VI; // a temporary

  typedef decltype(4.9*0.357) DOUBLE; // a math expression

  // TODO: does not work with g++ 4.6.2.
  auto arr = {2,4,8};
  typedef decltype(arr) int_array; // an array
  int_array table;
  //table[0] = -10;


  /* C++11 Style Function Declarations */

  get_end(vf);  // returns vector<Foo>::iterator

  // TODO: does not work with g++ 4.6.2.
  //get_end(cvf); // returns vector<Foo>::const_iterator

}
