/**
 * TODO: find the exact compiler options that generate a warning here.
 */
class B {
public:
  virtual void f() const;
};

class D: public B {
public:
  virtual void f();
};
