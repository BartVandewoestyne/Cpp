// Declare a function f taking a double and returning an int.
int f1( double d );

// Parens around d aree ignored.
int f2( double (d) );

// Parameter name is omitted.
int f3( double );


// Declare a function g taking a parameter that's a pointer to a function
// taking nothing and returning a double.
int g1( double (*pf)() );

// Here, pf is declared using non-pointer syntax (a syntax that's valid in
// both C and C++), pf is implicitly a pointer.
int g2( double pf() );

// Here, the name pf has been eliminated/omitted.
int g3( double () );

int main()
{}
