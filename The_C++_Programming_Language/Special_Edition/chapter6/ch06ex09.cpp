/**
 * (*1) Fully parenthesize the following expressions:
 *
 *        *p++
 *        *--p
 *        ++a--
 *        (int*)p->m
 *        *p.m
 *        *a[i]
 */

#include <iostream>

using namespace std;

struct MyStruct {
  int *m;
};

int main()
{
  int a = 1;
  int *p;
  MyStruct p2 = {&a};
  MyStruct *p3 = &p2;
  int *b[3] = {&a, &a, &a};

  // First dereference p to get 1, then use '1' to print, and then increment
  // to 2 but don't use this 2.
  // TODO: check why reference solution is different.
  p = &a;
  cout << "*p++ = " << *p++ << endl;
  p = &a;
  cout << "((*p)++) = " << ((*p)++) << endl;
  p = &a;
  cout << "(*(p++)) = " << (*(p++)) << endl; // Reference solution???

  // First decrement pointer address to point to some uninitialized location,
  // than dereference to find the (undetermined) value.
  p = &a;
  cout << "*--p = " << *--p << endl;
  p = &a;
  cout << "(*(--p)) = " << (*(--p)) << endl;

  // TODO: figure this one out...
  // TODO: check why reference solution is different.
  a = 1;
  //cout << "++a-- = " << ++a-- << endl; // error
  cout << "((++a)--) = " << ((++a)--) << endl;
  //cout << "(++(a--)) = " << (++(a--)) << endl; // Reference solution???

  cout << "(int*)p3->m     = " << (int*)p3->m << endl;
  cout << "((int*)(p3->m)) = " << ((int*)(p3->m)) << endl;

  cout << "*p2.m     = " << *p2.m     << endl;
  cout << "(*(p2.m)) = " << (*(p2.m)) << endl;

  for (int i = 0; i < 3; i++)
  {
    cout << "*b[i]   = " << *b[i] << endl;
    cout << "*(b[i]) = " << *(b[i]) << endl;
  }
}
