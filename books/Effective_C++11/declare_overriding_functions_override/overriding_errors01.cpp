class Base {
public:
  virtual void f() const;
};

class Derived: public Base {
public:
  virtual void f();          // missing const;
};                           // doesn't override;
                             // declares new virtual function
