#include "Vector.h"

Vector::Vector(const Vector& a) // copy constructor
    :sz(a.sz)
{
    elem = new double[sz];
    for (int i=0; i<sz; ++i)
        elem[i] = a.elem[i];
}

// QUESTION: why is the temporary pointer to array p used here, instead
// of directly copying into elem???
Vector& Vector::operator=(const Vector& a)  // copy assignment
{
    double* p = new double[a.sz];
    for (int i=0; i<a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;        // delete old elements
    elem = p;
    sz = a.sz;
    return *this;
}


Vector::Vector(Vector&& a)
{
    elem = a.elem; // "grab the elements" from a
    sz = a.sz;
    a.elem = nullptr; // now a has no elements
    a.sz = 0;
}
