/**
 * Mismatched parameter types in base and derived classes.
 */

class Base {
public:
  virtual void f(long) const;
};

class Derived: public Base {
public:
  virtual void f(int) const override;     // error!
};
