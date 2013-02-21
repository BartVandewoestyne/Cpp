class Vector {
private:
    // elem points to an array of sz doubles
    double* elem;
    int sz;

public:
    // ...

    Vector(const Vector& a);             // copy constructor
    Vector& operator=(const Vector& a);  // copy assignment

    Vector(Vector&& a);                  // move constructor
    Vector& operator=(Vector&& a);       // move assignment

    // ...
};
