/**
 * Reference:
 *
 *   `The C++ Programming Language, Special Edition', page 146.
 *
 */
float fsqrt(const float&);

void g(double d)
{
  float r = fsqrt(2.0f);  // pass ref to temp holding 2.0f
  r = fsqrt(r);           // pass ref to r
  r = fsqrt(d);           // pass ref to temp holding float(d)
}
