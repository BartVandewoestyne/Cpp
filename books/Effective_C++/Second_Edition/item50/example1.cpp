class Base {
public:
  virtual void f(int x);
};

class Derived: public Base {
public:
  virtual void f(double *pd);
};

int main()
{
  Derived *pd = new Derived;
  //pd->f(10);                  // error!
}
