class Base {
public:
  virtual void f() const;
};

class Derived1: public Base {
public:
  virtual void f() const;  // overrides Base::f
};

class Derived2: public Base {
public:
  void f() const;          // also overrides Base::f
};
