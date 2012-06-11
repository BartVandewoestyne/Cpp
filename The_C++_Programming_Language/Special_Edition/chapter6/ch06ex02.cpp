#include <iostream>

using namespace std;

int f(int x, int y)
{
  cout << "inside f(x,y)" << endl;
  return 0;
}


int main()
{
  int a = 1;
  int b = 1;
  int* b2 = &b;
  int c = 1;
  int d = 1;
  int* d2 = &d;
  int a2[4][2];
  int x = 1;
  int i = 1;

  cout << ( a =    b +  c*d   << 2  & 8  ) << endl;
  cout << ( a = (((b + (c*d)) << 2) & 8) ) << endl;

  cout << (a &  077 != 3 ) << endl;
  cout << (a & (077 != 3)) << endl;

  cout << (    a == b  ||  a == c    &&  c < 5 )  << endl;
  cout << ( ( (a == b) || (a == c) ) && (c < 5) ) << endl; // TODO: check!

  cout << ( c =  x != 0  ) << endl;
  cout << ( c = (x != 0) ) << endl;

  cout << (  0 <= i  < 7 ) << endl;
  cout << ( (0 <= i) < 7 ) << endl;

  cout << ( f(1,2) + 3 ) << endl;
  cout << ( ((f(1,2)) + 3) ) << endl;

  cout << ( a =    -1+ +b--   -5  ) << endl; // TODO
  cout << ( a = (((-1)+(+(b--)))-5) ) << endl;

  cout << ( a =  b ==  c ++ ) << endl;
  cout << ( a = (b == (c ++)) ) << endl;

  cout << ( a=b=c=0 ) << endl;
  cout << ( a=(b=(c=0)) ) << endl;

  cout << ( a2[4][2] *= *b2 ? c : *d2 * 2 ) << endl;
  cout << ( (a2[4])[2] *= ((*b2) ? (c) : ((*d2) * 2)) ) << endl;

  cout << ( a-b,c=d ) << endl;
  cout << ( (a-b),(c=d) ) << endl;

}
