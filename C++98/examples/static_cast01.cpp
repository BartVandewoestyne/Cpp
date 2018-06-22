/*
 * Type conversions that the compiler performs implicitly can be explicitly
 * requested by using a static_cast.
 *
 * References:
 *
 *   [1] C++ Primer, 4th Edition, Lipman, Lajoi, Moo, 2005, section 5.12.6
 *   'Named Casts'.
 */

int main()
{
  double d = 97.0;
  
  // cast specified to indicate that the conversion is intentional
  char ch = static_cast<char>(d);

  void* p = &d; // ok: address of any data object can be stored in a void*
  // ok: converts void* back to the original pointer type
  double *db = static_cast<double*>(p);
}
