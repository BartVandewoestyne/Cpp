/*
 * Type conversions that the compiler performs implicitly can be explicitly
 * requested by using a static_cast.
 *
 * References:
 *
 *   [1] C++ Primer, 4th Edition, Lipman, Lajoi, Moo, 2005, section 5.12.6
 *   'Named Casts'.
 *
 *   [2] Why use static_cast<int>(x) instead of (int)x?
 *     https://stackoverflow.com/questions/103512/why-use-static-castintx-instead-of-intx
 */

class Base {};
class Derived : public Base {};
class Other {};

int main()
{
    {
        double d = 97.0;
        
        // cast specified to indicate that the conversion is intentional
        char ch = static_cast<char>(d);

        void* p = &d; // ok: address of any data object can be stored in a void*
        // ok: converts void* back to the original pointer type
        double *db = static_cast<double*>(p);
    }

    {
        // Advantage 1: *compile-time* checking
        
        {
            // Example 1:
            
            Base* pBase = new Base();
            //Other* pOther1 = static_cast<Other*>(pBase);  // Compiler error: can't convert
            Other* pOther2 = (Other*)(pBase);  // No compiler error.  Same as reinterpret_cast<> and it's wrong!
        }

        {
            // Example 2: static cast only allows conversions between *compatible types*
            
            char c = 10;        // a char is 1 byte

            int* p = (int*)&c;  // an int is 4 bytes, and a C-style cast allows an integer pointer to point to a char
            *p = 5;  // runtime-error: stack corruption!

            // a static_cast will allow the compiler to check that the pointer
            // and pointee data types are compatible, which allows the
            // programmer to catch this incorrect pointer assignment during
            // compilation.
            //int* q = static_cast<int*>(&c);  // Compiler error!
        }

        // Advantage 2: casts are easy to search for (C-style casts are hard to search for).
        
        // Advantage 3: it clearly shows intent.
    }
}
