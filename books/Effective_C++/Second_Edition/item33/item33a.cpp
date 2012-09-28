inline void f() {}            // as above

void (*pf)() = f;                // pf points to f

int main()
{
  f();                           // an inline call to f

  pf();                          // a non-inline call to f
                                 // through pf
}
