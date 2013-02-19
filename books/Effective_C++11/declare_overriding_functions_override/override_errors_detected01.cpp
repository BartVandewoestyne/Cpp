class Base {
public:
  virtual void f() const;
};

class Derived1: public Base {
public:
  void f() const override;        // fine
};

class Derived2: public Base {
public:
  virtual void f() override;      // error! not an override
};                                // (missing const)
