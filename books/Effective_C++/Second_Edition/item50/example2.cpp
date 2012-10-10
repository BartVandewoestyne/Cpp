class Base {
public:
  virtual void f(int x);
};

class Derived: public Base {
public:
  using Base::f;                   // import Base::f into
                                   // Derived's scope
  virtual void f(double *pd);
};

int main()
{
  Derived *pd = new Derived;
  pd->f(10);
}
