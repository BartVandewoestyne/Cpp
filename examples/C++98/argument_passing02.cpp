/**
 * Reference:
 *
 *   `The C++ Programming Language, Special Edition', page 147.
 */

void update(float& i);

void g(double d, float r)
{

  // error: const argument
  // error from g++:
  //   error: invalid initialization of non-const reference of type ‘float&’ from a temporary of type ‘float’
  //   error: in passing argument 1 of ‘void update(float&)’
  //update(2.0f);

  update(r);     // pass ref to r

  // error: type conversion required
  // error from g++:
  //   error: invalid initialization of reference of type ‘float&’ from expression of type ‘double’
  //   error: in passing argument 1 of ‘void update(float&)’
  //update(d);

}
