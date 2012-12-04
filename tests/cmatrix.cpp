/**
 * Example from when I was working at Agilent.
 * I think I created this example to check what ranges are available for the
 * matrix.
 */

#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct myComplexS {
  double r;
  double i;
} myComplex;

myComplex **create_matrix(int nrl, int nrh, int ncl, int nch)
{
  int i ;
  myComplex **m ;

  m = (myComplex**) calloc( nrh-nrl+1, sizeof(myComplex*) );
  if (m==NULL) return m;
  m -= nrl ;
  
  for ( i=nrl ; i<=nrh ; i++ )
  { 
    m[i]= (myComplex *) calloc( nch-ncl+1, sizeof(myComplex) );
    if ( m[i] == NULL ) return NULL ;
    m[i] -= ncl ;
  }

  return m ;
}

int main()
{
  myComplex **myMatrix = create_matrix(1,2,1,2);
  myComplex a = {1,10};
  myComplex b = {2,20};
  myComplex c = {3,30};
  myComplex d = {4,40};

  //myMatrix[0][0] = a; // segfault
  myMatrix[1][1] = a;
  myMatrix[1][2] = b;
  myMatrix[2][1] = c;
  myMatrix[2][2] = d;
  //myMatrix[3][0] = a; // segfault
  //myMatrix[3][1] = a; // segfault

  cout << myMatrix[1][1].r << endl;
  cout << myMatrix[1][1].i << endl;
  cout << myMatrix[1][2].r << endl;
  cout << myMatrix[1][2].i << endl;
  cout << myMatrix[2][1].r << endl;
  cout << myMatrix[2][1].i << endl;
  cout << myMatrix[2][2].r << endl;
  cout << myMatrix[2][2].i << endl;
}
